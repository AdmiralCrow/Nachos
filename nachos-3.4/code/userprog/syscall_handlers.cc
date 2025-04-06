#include "copyright.h" 
#include "system.h"
#include "syscall.h"
#include "pcb.h"
#include "addrspace.h"
#include "memory_manager.h"
#include "syscall_handlers.h"

// Corrected signature for Thread::Fork
static void ChildProcessStarter(int arg) {
    PCB *childPCB = (PCB *)arg;
    Thread *childThread = childPCB->getThread();

    currentThread = childThread;
    childThread->space->InitRegisters();

    // Set PC register to child's function start address
    machine->WriteRegister(PCReg, childPCB->getStartAddress());
    machine->WriteRegister(NextPCReg, childPCB->getStartAddress() + 4);

    childThread->space->RestoreState();
    machine->Run();
    ASSERT(FALSE);
}


// ------------------------------------------
// INSIDE syscall handler
//void SysFork() {
//    int funcAddr = machine->ReadRegister(4); // Read address from r4
//    int pid = currentThread->space->getPCB()->getID();  //

 //   DEBUG('a', "Func address passed to Fork: 0x%x\n", funcAddr);
 //   DEBUG('a', "System Call: %d invoked Fork\n", pid);

//    SpaceId childId = Fork((void (*)())funcAddr);  // Call actual fork logic
//    machine->WriteRegister(2, childId);            // Return child PID in r2
void SysFork() {
    int funcAddr = machine->ReadRegister(4);
    int pid = currentThread->space->getPCB()->getID();

    DEBUG('a', "Func address passed to Fork: 0x%x\n", funcAddr);
    DEBUG('a', "System Call: %d invoked Fork\n", pid);

    printf("🔧 Kernel: Fork() syscall received for PID %d, function addr: 0x%x\n", pid, funcAddr);

    SpaceId childId = Fork(funcAddr);
    machine->WriteRegister(2, childId);
}
//}


//----------------------------------------------------------------------
// Fork()
//----------------------------------------------------------------------
SpaceId Fork(int funcAddr) {
    int parentPid = currentThread->space->getPCB()->getID();
    DEBUG('a', "System Call: %d invoked Fork\n", parentPid);

    AddrSpace *childSpace = new AddrSpace(currentThread->space);
    if (!childSpace) {
        DEBUG('a', "Failed to create address space for child process\n");
        return -1;
    }

    Thread *childThread = new Thread("child");
    childThread->space = childSpace;

    PCB *childPCB = new PCB(childThread);
    int pid = processManager->getPID();
    if (pid == -1) {
        delete childSpace;
        delete childThread;
        delete childPCB;
        return -1;
    }

    childPCB->setID(pid);
    childPCB->setParent(currentThread->space->getPCB());
    childPCB->setStartAddress(funcAddr);  // You'll define this
    childThread->Fork(ChildProcessStarter, (int)childPCB);

    DEBUG('a', "Forked child %d at address 0x%x\n", pid, funcAddr);
    return pid;
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
        delete [] filename;
        return;
    }

    AddrSpace *newSpace = new AddrSpace(executable);
    delete executable;
    if (newSpace == NULL) {
        machine->WriteRegister(2, -1);
        delete [] filename;
        return;
    }

    currentThread->space = newSpace;
    newSpace->InitRegisters();
    newSpace->RestoreState();
    machine->WriteRegister(2, 1);
    delete [] filename;
    machine->Run();
    machine->WriteRegister(2, -1);
}

//----------------------------------------------------------------------
// SysExit()
//----------------------------------------------------------------------
void SysExit() {
    int exitStatus = machine->ReadRegister(4);
    int pid = currentThread->space->getPCB()->getID();

    DEBUG('a', "System Call: %d invoked Exit\n", pid);
    DEBUG('a', "Process %d exits with %d\n", pid, exitStatus);

    PCB *pcb = currentThread->space->getPCB();
    pcb->setExitStatus(exitStatus);

    // FIX Condition::Broadcast() to use a Lock — TEMPORARY place-holder
    // pcb->joinCond->Broadcast(lock); <-- to be fixed once lock is added

    processManager->clearPID(pcb->getID());
    currentThread->Finish();
    ASSERT(FALSE);
}

//----------------------------------------------------------------------
// SysYield()
//----------------------------------------------------------------------
void SysYield() {
    int pid = currentThread->space->getPCB()->getID();
    DEBUG('a', "System Call: %d invoked Yield\n", pid);
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
