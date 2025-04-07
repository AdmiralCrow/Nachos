#ifndef SYSCALL_HANDLERS_H
#define SYSCALL_HANDLERS_H

#include "copyright.h"
#include "thread.h"
#include "synch.h"
#include "addrspace.h"
#include "pcb.h"
#include "syscall.h"

char* User2Kernel(int addr);

// Function declarations for kernel-level syscall handlers
void SysFork() {
    int funcAddr = machine->ReadRegister(4);  // Get start address of function
    int parentPid = currentThread->space->getPCB()->getID();

    DEBUG('a', "Func address passed to Fork: 0x%x\n", funcAddr);
    DEBUG('a', "System Call: %d invoked Fork\n", parentPid);

    SpaceId childId = Fork((void (*)())funcAddr);  // Call actual fork logic
    machine->WriteRegister(2, childId);            // Return child PID
}

void SysExec();
void SysExit();
void SysYield();
void SysJoin();
void SysKill();

#endif // SYSCALL_HANDLERS_H
