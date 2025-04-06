// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "system.h"
#include "synch.h"


void doExit(int status) {

    //Exit has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Exit.\n", currentThread->space->pcb->pid);

    //Store pcb of currentThread that is exiting
    PCB* pcb = currentThread->space->pcb;

    //Set exit status
    pcb->exitStatus = status;

    // Save currentThread PID for later use
    int pid = pcb->pid;  
 
    //deallocate pcb's of currentThread's exited children, set parent to null for non exited ones
    pcb->DeleteExitedChildrenSetParentNull();

    //if currentThread is a child who's parent is null, deallocate their pcb
   if (pcb->parent == NULL) {
        pcbManager->DeallocatePCB(pcb);
    }

    // Delete the currentThread address space
    delete currentThread->space;

    // Print the process exit information using the saved PID and status
    printf("Process [%d] exits with [%d]\n", pid, status);

    // Finish the current thread
    currentThread->Finish();
    // Note: Anything after currentThread->Finish() will not be executed,
    // as Finish() will terminate the current thread.
}

//function to increment program counter
void incrementPC() {
    int oldPCReg = machine->ReadRegister(PCReg);

    machine->WriteRegister(PrevPCReg, oldPCReg);
    machine->WriteRegister(PCReg, oldPCReg + 4);
    machine->WriteRegister(NextPCReg, oldPCReg + 8);
}

//Child function invoked during doFork
void childFunction(int pid) {

    // 1. Restore the state of registers
    currentThread->RestoreUserState();


    // 2. Restore the page table for child
    currentThread->space->RestoreState();

    //call run
    machine->Run();

}

//Creates a new child process
int doFork(int functionAddr) {

    //Fork has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Fork.\n", currentThread->space->pcb->pid);

    // 1. Create a PCB for the child, must do this first bc pid is needed
      PCB* pcb = pcbManager->AllocatePCB();
      if (pcb == NULL) {
            // Handle allocation failure
            printf("PCB null\n");
            return -1;
        }

    // 2. Check if sufficient memory exists to create new process
    // currentThread->space->GetNumPages() <= mm->GetFreePageCount()
    // if check fails, return -1
    if(currentThread->space->GetNumPages() > mm->GetFreePageCount())
    {
        //report that fork failed
        printf("Not Enough Memory for Child Process %d\n", pcb->pid);

        //deallocate pcb if function returns
        pcbManager->DeallocatePCB(pcb);

        return -1;
    
    }


    // 3. SaveUserState for the parent thread
    // currentThread->SaveUserState();

    currentThread->SaveUserState();

    // 4. Create a new address space for child by copying parent address space
    // Parent: currentThread->space
    // childAddrSpace: new AddrSpace(currentThread->space)
    AddrSpace* childAddrSpace = new AddrSpace(currentThread->space);

    if(childAddrSpace->valid == false){
        printf("Could Not Create Address Space: not Valid\n");

        return -1;
    }

    // 5. Create a new thread for the child and set its addrSpace
    // childThread = new Thread("childThread")
    // child->space = childAddSpace;
    Thread* childThread = new Thread("childThread");
    childThread->space = childAddrSpace;

    //set thread for pcb
    pcb->thread = childThread;

    // set parent for child pcb
    pcb->parent = currentThread->space->pcb; 

    //connect child pcb to child address space
    childAddrSpace->pcb = pcb;

    //add child for parent pcb
    currentThread->space->pcb->AddChild(pcb);

    // 6. Set up machine registers for child and save it to child thread
    // PCReg: functionAddr
    // PrevPCReg: functionAddr-4
    // NextPCReg: functionAddr+4
    // childThread->SaveUserState();
    
    machine->WriteRegister(PrevPCReg, functionAddr-4);
    machine->WriteRegister(PCReg, functionAddr);
    machine->WriteRegister(NextPCReg, functionAddr + 4);

    childThread->SaveUserState();

    // 7. Restore register state of parent user-level process
    // currentThread->RestoreUserState()

    currentThread->RestoreUserState();

    // 8. Call thread->fork on Child
    // childThread->Fork(childFunction, pcb->pid)

    childThread->Fork(childFunction, pcb->pid);

    //Fork success message
    printf("Process [%d] Fork: start at address [0x%0x] with [%u] pages memory\n", currentThread->space->pcb->pid,functionAddr,currentThread->space->GetNumPages());

    // 9. return pcb->pid;
    return pcb->pid;

}

int doExec(char* filename) {

    //Exec has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Exec.\n", currentThread->space->pcb->pid);
    // 1. Open the file and check validity
    OpenFile *executable = fileSystem->Open(filename);

    //Declare new address space
    AddrSpace *space;

    //check if executable is valid
    if (executable == NULL) {
        printf("Unable to open file %s\n", filename);
         return -1;
     }

    //should be reusing the pcb of the process, only need to update the addyspace
    // 2. Delete current address space but store current PCB first if using in Step 5.
     PCB* pcb = currentThread->space->pcb;


     //may want to hook up threads w spaces like in fork
     delete currentThread->space;

    // 3. Create new address space
     space = new AddrSpace(executable);


    //Declare that program is being loaded
     printf("Exec Program: [%d] loading [%s]\n", pcb->pid, filename);

    // 4. // close file
    delete executable;

    // 5. Check if Addrspace creation was successful
     if(space->valid != true) {
     printf("Could not create AddrSpace\n");

        doExit(0);
        return -1;
     }

    // 6. Set the PCB for the new addrspace - reused from deleted address space
     space->pcb = pcb;

    // 7. Set the addrspace for currentThread
     currentThread->space = space;

    // 8. Initialize registers for new addrspace
      space->InitRegisters();		// set the initial register values

    // 9. Initialize the page table
     space->RestoreState();		// load page table register

    // 10. Run the machine now that all is set up
     machine->Run();			// jump to the user progam
     ASSERT(FALSE); // Execution nevere reaches here

    return 0;
}

//Join process specified by pid
int doJoin(int pid) {

    //Join has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Join.\n", currentThread->space->pcb->pid);

    //Check if pid is valid. If not, return -1
    if(pid < 0){
        return -1;
    }

    // 1. Check if this is a valid pcb and return -1 if not
     PCB* joinPCB = pcbManager->GetPCB(pid);
     if (joinPCB == NULL) return -1;

    // 2. Check if pid is a child of current process
     PCB* pcb = currentThread->space->pcb;
     if (pcb != joinPCB->parent){
      return -1;
     }

    // 3. Yield until joinPCB has not exited
     while(!(joinPCB->HasExited())){
         currentThread->Yield();
     }


    // 4. Store status and delete joinPCB
     int status = joinPCB->exitStatus;
    // delete joinPCB;

    //Check if join process has exited
    if (joinPCB->HasExited()) {

        // 5. return status;
        return status;
    }

}


int doKill (int pid) {

    //Kill has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Kill.\n", currentThread->space->pcb->pid);

    //Check if pid is valid. If not, return -1
    if(pid < 0){
        return -1;
    }
    // 1. Check if the pid is valid and if not, return -1
     PCB* pcb = pcbManager->GetPCB(pid);
     if (pcb == NULL){
        printf("Process [%d] cannot kill process [%d]: doesn't exist", currentThread->space->pcb->pid, pid);
         return -1;
     }
    // 2. IF pid is self, then just exit the process
     if (pcb == currentThread->space->pcb) {
             doExit(0);
             return 0;
     }else{
        // 3. Valid kill, pid exists and not self, do cleanup similar to Exit
        // However, change references from currentThread to the target thread
        // pcb->thread is the target thread

        //set exit status for process to be filled
        pcb->exitStatus = 0;

        //deallocate pcb's of currentThread's exited children, set parent to null for non exited ones
        pcb->DeleteExitedChildrenSetParentNull();

        //if currentThread is a child who's parent is null, deallocate their pcb
        if(pcb->parent == NULL){
            pcbManager->DeallocatePCB(pcb);
        }

        //Store thread to kill
        Thread* threadToKill = pcb->thread;

        //remove thread to kill from ready list
        scheduler->RemoveThread(pcb->thread);

        //delete address space
        delete threadToKill->space;

        //delete thread
        delete threadToKill;

        //process killed successfully, print message
        printf("Process [%d] killed process [%d]\n", currentThread->space->pcb->pid, pid);

         return 0;
     }

     }


void doYield() {

    //Yield has been invoked, print pid of currentThread
    printf("System Call: [%d] invoked Yield.\n", currentThread->space->pcb->pid);

    //Invoke yield
    currentThread->Yield();
}

// This implementation (discussed in one of the videos) is broken!
// Try and figure out why.
char* readString1(int virtAddr) {

    unsigned int pageNumber = virtAddr / 128;
    unsigned int pageOffset = virtAddr % 128;
    unsigned int frameNumber = machine->pageTable[pageNumber].physicalPage;
    unsigned int physicalAddr = frameNumber*128 + pageOffset;

    char *string = &(machine->mainMemory[physicalAddr]);

    return string;

}



// This implementation is correct!
// perform MMU translation to access physical memory
char* readString(int virtualAddr) {
    int i = 0;
    char* str = new char[256];
    unsigned int physicalAddr = currentThread->space->Translate(virtualAddr);

    // Need to get one byte at a time since the string may straddle multiple pages that are not guaranteed to be contiguous in the physicalAddr space
    bcopy(&(machine->mainMemory[physicalAddr]),&str[i],1);
    while(str[i] != '\0' && i != 256-1)
    {
        virtualAddr++;
        i++;
        physicalAddr = currentThread->space->Translate(virtualAddr);
        bcopy(&(machine->mainMemory[physicalAddr]),&str[i],1);
    }
    if(i == 256-1 && str[i] != '\0')
    {
        str[i] = '\0';
    }

    return str;
}

/*
========================================================================================================================
========================================================================================================================
Project 3 Start 


========================================================================================================================
========================================================================================================================
*/




//----------------------------------------------------------------------
// doClose
//  This function assists in executing the close system call.
//
//  "id" represents the file identifier that needs to be closed.
//----------------------------------------------------------------------

void doClose(OpenFileId id) {
    printf("System Call: Close invoked by Process [%d].\n",
            currentThread->space->pcb->pid);
    // currentThread->space->pcb->RemoveFileDescriptor((int) id);
    currentThread->space->pcb->ReleaseFileDescriptor((int) id);
}

//----------------------------------------------------------------------
// doOpen
//  Auxiliary function for executing the open system call.
//
//  "fileName" denotes the name of the file to be opened.
//
//  Returns the identifier of the opened file if successful, otherwise -1.
//----------------------------------------------------------------------

OpenFileId doOpen(char* fileName) {
    printf("System Call: Open invoked by Process [%d].\n",
            currentThread->space->pcb->pid);
    char fullPath[256] = "../test/";
    strcat(fullPath, fileName);

    // Try to open the file
    OpenFile* file = fileSystem->Open(fullPath);
    if (file == NULL) {
        // If the file couldn't be opened, return -1
        printf("Unable to open file: %s\n", fullPath);
        return -1;
    }

    // Allocate a file descriptor for the opened file
    int fileId = currentThread->space->pcb->AllocateFileDescriptor(file);
    return (OpenFileId) fileId;
}


//----------------------------------------------------------------------
// doCreate
//  This function assists in handling the create system call.
//
//  "fileName" represents the name of the file to be created.
//----------------------------------------------------------------------

void doCreate(char* fileName) {
    printf("System Call: Create initiated by Process [%d].\n",
            currentThread->space->pcb->pid);
    char fullPath[256] = "../test/";
    strcat(fullPath, fileName);
    fileSystem->Create(fullPath, 0);
}



//----------------------------------------------------------------------
// doRead
//  Auxiliary function for executing the read system call.
//
//  "virtAddr" denotes the starting virtual address for the read operation.
//  "nBytes" specifies the quantity of bytes to be read.
//  "id" is the file descriptor from which the data is to be read.
//
//  Returns the actual number of bytes read on success, otherwise -1.
//  The returned byte count may be less than nBytes if it reaches the end of the file.
//----------------------------------------------------------------------

int doRead(int virtAddr, int nBytes, OpenFileId id) {
    PCB* pcb = currentThread->space->pcb;
    OpenFile* file = pcb->GetFile(id);
    if (file == NULL) {
        return -1; // Invalid file descriptor
    }

    char* buffer = new char[nBytes];
    int bytesRead = file->Read(buffer, nBytes);

    // Now copy from kernel buffer to user space
    for (int i = 0; i < bytesRead; i++) {
        machine->mainMemory[currentThread->space->Translate(virtAddr + i)] = buffer[i];
    }

    delete[] buffer;
    return bytesRead; // Number of bytes actually read
}




//----------------------------------------------------------------------------------------------------------------
// doWrite
//  This function supports the write system call.
//
//  "virtAddr" represents the virtual address where writing begins.
//  "nBytes" indicates the amount of bytes to be written.
//  "id" is the file descriptor of the target file for writing.
//
//  Returns the actual number of bytes written on success, otherwise -1.
//----------------------------------------------------------------------------------------------------------------
int doWrite(int virtAddr, int nBytes, OpenFileId id) {
    PCB* pcb = currentThread->space->pcb;
    OpenFile* file = pcb->GetFile(id);
    if (file == NULL) {
        return -1; // Invalid file descriptor
    }

    char* buffer = new char[nBytes];
    // Copy from user space to kernel buffer
    for (int i = 0; i < nBytes; i++) {
        buffer[i] = machine->mainMemory[currentThread->space->Translate(virtAddr + i)];
    }

    int bytesWritten = file->Write(buffer, nBytes);

    delete[] buffer;
    return bytesWritten; // Number of bytes actually written
}





// Translate virtual memory address to physical address for memory access
char* readStringFromVirtual(int virtualAddr) {
    int index = 0;
    char* extractedString = new char[256];
    unsigned int physicalAddr = currentThread->space->Translate(virtualAddr);

    // Retrieve each byte individually due to possible string extension across different non-contiguous pages
    bcopy(&(machine->mainMemory[physicalAddr]), &extractedString[index], 1);
    while(extractedString[index] != '\0' && index < 255) {
        virtualAddr++;
        index++;
        physicalAddr = currentThread->space->Translate(virtualAddr);
        bcopy(&(machine->mainMemory[physicalAddr]), &extractedString[index], 1);
    }

    // Ensure null termination of the string if it's not already terminated
    if(index < 255 && extractedString[index] != '\0') {
        extractedString[index] = '\0';
    }

    return extractedString;
}


//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions
//	are in machine.h.
//----------------------------------------------------------------------

//all system calls have single entry point, which is exceptionhandler
void
ExceptionHandler(ExceptionType which)
{
    //machine obj represents simulated MIPS machine
    //method is reading register 2, which contains number of system call being invoked
    //by user level program, in this case, halt exception
    int type = machine->ReadRegister(2);

    if ((which == SyscallException) && (type == SC_Halt)) {
	DEBUG('a', "Shutdown, initiated by user program.\n");
   	interrupt->Halt();
    } else  if ((which == SyscallException) && (type == SC_Exit)) {
        // Implement Exit system call
        //need to read argument provided when invoking exit()
        //register 4 holds value of 1st arg of syscall (0)
        doExit(machine->ReadRegister(4));
    } else if ((which == SyscallException) && (type == SC_Fork)) {
        int ret = doFork(machine->ReadRegister(4));
        //populate return register for syscall
        machine->WriteRegister(2, ret);
        //if we dont increment PC, syscall will repeat
        incrementPC();
    } else if ((which == SyscallException) && (type == SC_Exec)) {
        int virtAddr = machine->ReadRegister(4);
        char* fileName = readString(virtAddr);
        int ret = doExec(fileName);
        machine->WriteRegister(2, ret);
        incrementPC();
    } else if ((which == SyscallException) && (type == SC_Join)) {
        int ret = doJoin(machine->ReadRegister(4));
        machine->WriteRegister(2, ret);
        incrementPC();
    } else if ((which == SyscallException) && (type == SC_Kill)) {
        int ret = doKill(machine->ReadRegister(4));
        machine->WriteRegister(2, ret);
        incrementPC();
    } else if ((which == SyscallException) && (type == SC_Yield)) {
        doYield();
        incrementPC();
    } else if((which == SyscallException) && (type == SC_Create)) {
        int virtAddr = machine->ReadRegister(4);
        char* fileName = readString(virtAddr);
        doCreate(fileName);
        incrementPC();
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}

