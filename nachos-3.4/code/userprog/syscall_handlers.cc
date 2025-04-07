#include "copyright.h" 
#include "system.h"
#include "syscall.h"
#include "pcb.h"
#include "addrspace.h"
#include "memory_manager.h"
#include "syscall_handlers.h"

// This function is the starting point of the child process.
static void ChildProcessStarter(int arg) {
    PCB *childPCB = (PCB *)arg;
    Thread *childThread = childPCB->getThread();

    currentThread = childThread;

    int funcAddr = childPCB->getStartAddress();
    machine->WriteRegister(PCReg, funcAddr);
    machine->WriteRegister(NextPCReg, funcAddr + 4);

    childThread->space->InitRegisters();
    childThread->space->RestoreState();

    machine->Run();  // Should never return
    ASSERT(FALSE);
}

//----------------------------------------------------------------------
// SysFork()
//----------------------------------------------------------------------
void SysFork() {
    int funcAddr = machine->ReadRegister(4);  // Function address passed from user program
    int pid = currentThread->space->getPCB()->getID();

    printf("System Call: [%d] invoked Fork.\n", pid);
    printf("Process [%d] Fork: start at address [0x%x] with [%d] pages memory\n",
           pid, funcAddr, currentThread->space->getNumPages());

    SpaceId childId = Fork((void (*)())funcAddr);  // Do actual fork
    machine->WriteRegister(2, childId);            // Return child PID
}

//----------------------------------------------------------------------
// SysExec()
//----------------------------------------------------------------------
void SysExec() {
    int pid = currentThread->space->getPCB()->getID();
    DEBUG('a', "System Call: %d invoked Exec\n", pid);

    int filenameAddr = machine->ReadRegister(4);
    char *filename = User2Kernel(filenameAddr);

    DEBUG('a', "Exec Program: %d loading %s\n", pid, filename ? filename : "unknown");

    OpenFile *executable = fileSystem->Open(filename);
    if (executable == NULL) {
        machine->WriteRegister(2, -1);
        delete[] filename;
        return;
    }

    AddrSpace *newSpace = new AddrSpace(executable);
    delete executable;
    if (newSpace == NULL) {
        machine->WriteRegister(2, -1);
        delete[] filename;
        return;
    }

    currentThread->space = newSpace;
    newSpace->InitRegisters();
    newSpace->RestoreState();
    machine->WriteRegister(2, 1);
    delete[] filename;
    machine->Run();  // Never returns
    machine->WriteRegister(2, -1);  // Just in case
}

//----------------------------------------------------------------------
// SysExit()
//----------------------------------------------------------------------
void SysExit() {
    int exitStatus = machine->ReadRegister(4);
    int pid = currentThread->space->getPCB()->getID();

    printf("System Call: [%d] invoked Exit.\n", pid);
    printf("Process [%d] exits with [%d]\n", pid, exitStatus);

    PCB *pcb = currentThread->space->getPCB();
    pcb->setExitStatus(exitStatus);

    processManager->clearPID(pcb->getID());
    currentThread->Finish();
    ASSERT(FALSE);  // Should never reach here
}

//----------------------------------------------------------------------
// SysYield()
//----------------------------------------------------------------------
void SysYield() {
    int pid = currentThread->space->getPCB()->getID();
    printf("System Call: [%d] invoked Yield.\n", pid);
    currentThread->Yield();
}

//----------------------------------------------------------------------
// SysJoin()
//----------------------------------------------------------------------
void SysJoin() {
    int pid = machine->ReadRegister(4);
    int callerPid = currentThread->space->getPCB()->getID();

    DEBUG('a', "System Call: %d invoked Join\n", callerPid);

    if (!processManager->isChild(pid)) {
        machine->WriteRegister(2, -1);
        return;
    }

    int childExitStatus = processManager->Join(currentThread, pid);
    machine->WriteRegister(2, childExitStatus);
}

//----------------------------------------------------------------------
// SysKill()
//----------------------------------------------------------------------
void SysKill() {
    int pid = machine->ReadRegister(4);
    int callerPid = currentThread->space->getPCB()->getID();

    DEBUG('a', "System Call: %d invoked Kill\n", callerPid);

    if (!processManager->Kill(pid)) {
        DEBUG('a', "Process %d cannot kill process %d: doesn't exist\n", callerPid, pid);
        machine->WriteRegister(2, -1);
    } else {
        DEBUG('a', "Process %d killed process %d\n", callerPid, pid);
        machine->WriteRegister(2, 0);
    }
}

//----------------------------------------------------------------------
// Fork() - Internal logic for process duplication
//----------------------------------------------------------------------
SpaceId Fork(void (*func)()) {
    int parentPid = currentThread->space->getPCB()->getID();
    DEBUG('a', "System Call: %d invoked Fork\n", parentPid);
    DEBUG('a', "Process %d Fork: start at address 0x%x\n", parentPid, (int)func);

    AddrSpace *childSpace = new AddrSpace(currentThread->space);
    if (!childSpace || !childSpace->wasForkSuccessful()) {
        DEBUG('a', "Failed to allocate address space for child\n");
        delete childSpace;
        return -1;
    }
    

    Thread *childThread = new Thread("child");
    childThread->space = childSpace;

    PCB *childPCB = new PCB(childThread);
    int childPid = processManager->getPID();
    if (childPid == -1) {
        delete childThread;
        delete childSpace;
        delete childPCB;
        return -1;
    }

    childPCB->setID(childPid);
    childPCB->setParent(currentThread->space->getPCB());
    childPCB->setStartAddress((int)func);
    processManager->setPCB(childPid, childPCB);

    DEBUG('a', "Forking child %d with thread %s\n", childPid, childThread->getName());

    //  START THE CHILD PROCESS
    childThread->Fork(ChildProcessStarter, (int)childPCB);

    return childPid;
}
