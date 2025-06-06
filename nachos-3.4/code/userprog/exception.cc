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
#include "synch.h"

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


void doExit(int status) {

    // Manage PCB memory As a parent process
    PCB* pcb = currentThread->space->pcb;
    //save currentthread pid for later 
    int pid = pcb->pid;

    printf("System Call: [%d] invoked [Exit]\n", pid);
    printf ("Process [%d] exits with [%d]\n", pid, status);

    currentThread->space->pcb->exitStatus = status;
    //exit status
    pcb->exitStatus = status;


    // Delete exited children and set parent null for non-exited ones
    pcb->DeleteExitedChildrenSetParentNull();

    // Manage PCB memory As a child process
    if(pcb->parent == NULL) {
        pcbManager->DeallocatePCB(pcb);
    }

    // Delete address space only after use is completed
    delete currentThread->space;

    printf("process [%d] exits with [%d]\n", pid, status);
    // Finish current thread only after all the cleanup is done
    // because currentThread marks itself to be destroyed (by a different thread)
    // and then puts itself to sleep -- thus anything after this statement will not be executed!
    currentThread->Finish();

}

void incrementPC() {
    int oldPCReg = machine->ReadRegister(PCReg);

    machine->WriteRegister(PrevPCReg, oldPCReg);
    machine->WriteRegister(PCReg, oldPCReg + 4);
    machine->WriteRegister(NextPCReg, oldPCReg + 8);
}


void childFunction(int pid) {

    // 1. Restore the state of registers
    currentThread->RestoreUserState();

    // 2. Restore the page table for child
    currentThread->space->RestoreState();
    //call run
    machine->Run();

}

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

    // 1. Check if sufficient memory exists to create new process
    if(currentThread->space->GetNumPages() <= mm->GetFreePageCount())
    {
    // if check fails, return -1
        printf("Not Enough Memory for child process %d\n", pcb->pid);
        
        //deallocate
        pcbManager->DeallocatePCB(pcb);
    }
    // 2. SaveUserState for the parent thread
    currentThread->SaveUserState();

    // 3. Create a new address space for child by copying parent address space
    // Parent: currentThread->space
    AddrSpace* childAddrSpace = new AddrSpace(currentThread->space);

    if(childAddrSpace->valid==false)
    {
        printf("Couldnt Create the address space\n");

        return -1;
    }

    // 4. Create a new thread for the child and set its addrSpace
    Thread* childThread = new Thread("childThread");
    childThread->space = childAddrSpace;



    // 5. Create a PCB for the child and connect it all up
    // pcb: pcbManager->AllocatePCB();
    pcb->thread = childThread;
    // set parent for child pcb
    pcb->parent = currentThread->space->pcb; 
    //connect child pcb to child address space
    childAddrSpace->pcb = pcb;
    // add child for parent pcb
    currentThread->space->pcb->AddChild(pcb);


    // 6. Set up machine registers for child and save it to child thread
    // PCReg: functionAddr
    // PrevPCReg: functionAddr-4
    // NextPCReg: functionAddr+4
    // childThread->SaveUserState();
    machine->WriteRegister(PCReg, functionAddr);
    machine->WriteRegister(PrevPCReg, functionAddr -4);
    machine->WriteRegister(NextPCReg, functionAddr +4);
    childThread->SaveUserState();

    // 7. Restore register state of parent user-level process
    currentThread->RestoreUserState();

    // 8. Call thread->fork on Child
    childThread->Fork(childFunction, pcb->pid);

    // pcreg = machine->ReadRegister(PCReg)
    // print message for child creation (pid,  pcreg, currentThread->space->GetNumPages())
    printf("Process [%d] Fork: Start at address [0x%0x]  with [%u] pages of memory\n", currentThread->space->pcb->pid,functionAddr,currentThread->space->GetNumPages());

    // 9. return pcb->pid;
    return pcb->pid;

}

int doExec(char* filename) {

    // Use progtest.cc:StartProcess() as a guide
    
    // 1. Open the file and check validity
    OpenFile *executable = fileSystem->Open(filename);
    AddrSpace *space;

    if (executable == NULL) 
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    // 2. Delete current address space but store current PCB first if using in Step 5.
    PCB* pcb = currentThread->space->pcb;
    delete currentThread->space;

    // 3. Create new address space
    space = new AddrSpace(executable);

    // 4.     delete executable;			// close file
    delete executable;
    // 5. Check if Addrspace creation was successful
    if(space->valid != true) 
    {
        printf("Could not create AddrSpace\n");
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


int doJoin(int pid) 
{

    // 1. Check if this is a valid pid and return -1 if not
    PCB* joinPCB = pcbManager->GetPCB(pid);
    if (joinPCB == NULL) return -1;


    // 2. Check if pid is a child of current process
    PCB* pcb = currentThread->space->pcb;
    if (pcb != joinPCB->parent) 
    {
        return -1;
    }

    // 3. Yield until joinPCB has not exited
    while(!(joinPCB->HasExited()))
    {
        currentThread->Yield();
    }
    // 4. Store status and delete joinPCB
    int status = joinPCB->exitStatus;
    delete joinPCB;

    // 5. return status;
    return status;

}


int doKill (int pid) {
    
    
    // 1. Check if the pid is valid and if not, return -1
    PCB* targetPCB = pcbManager->GetPCB(pid);
    if (targetPCB == NULL) {
        printf("Process [%d] cannot kill process[%d]", currentThread->space->pcb->pid, pid);
        return -1;
    }
    PCB* pcb = currentThread->space->pcb;
    // 2. IF pid is self, then just exit the process
    if (pcb == currentThread->space->pcb) {
        doExit(0);
        return 0;
    }
    else{

    // 3. Valid kill, pid exists and not self, do cleanup similar to Exit
    // However, change references from currentThread to the target thread
    // pcb->thread is the target thread
    pcb->exitStatus = 0;

    //deallocate pcbs of currentthreads
    pcb->DeleteExitedChildrenSetParentNull();
    //if currentThread is a child who's parent is null, deallocate their pcb
    if(pcb->parent == NULL){
        pcbManager->DeallocatePCB(pcb);
    }
    //Store thread to kill
    Thread* threadToKill = pcb->thread;

    // 4. Set thread to be destroyed.
    pcb->thread->Finish(); // Safely finishes the thread

    //delete address space && thread
    delete threadToKill->space;
    delete threadToKill;

   } // 5. return 0 for success!
    return 0;
}



void doYield() {
    currentThread->Yield();
}






// This implementation is correct!
// perform MMU translation to access physical memory
char* readString(int virtualAddr) {
    char* str = new char[256];  // Allocate memory for the string
    int i = 0;

    while (i < 255) {  // Avoid buffer overflows
        unsigned int physicalAddr = currentThread->space->Translate(virtualAddr);

        // Read from main memory using translated physical address
        str[i] = machine->mainMemory[physicalAddr];
        
        if (str[i] == '\0') break;

        i++;
        virtualAddr++;
    }

    str[i] = '\0';  // Ensure null-terminated string
    return str;
}


void doCreate(char* fileName)
{
    printf("Syscall Call: [%d] invoked Create.\n", currentThread->space->pcb->pid);
    fileSystem->Create(fileName, 0);
}

void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

    if ((which == SyscallException) && (type == SC_Halt)) {
	DEBUG('a', "Shutdown, initiated by user program.\n");
   	interrupt->Halt();
    } else  if ((which == SyscallException) && (type == SC_Exit)) {
        // Implement Exit system call
        doExit(machine->ReadRegister(4));
    } else if ((which == SyscallException) && (type == SC_Fork)) {
        int ret = doFork(machine->ReadRegister(4));
        machine->WriteRegister(2, ret);
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