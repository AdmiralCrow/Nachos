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
SpaceId Fork(void (*func)());

void SysExec();
void SysExit();
void SysYield();
void SysJoin();
void SysKill();
void SysCreate();
void SysOpen();
void SysRead();
void SysWrite();
void SysClose();

#endif // SYSCALL_HANDLERS_H
