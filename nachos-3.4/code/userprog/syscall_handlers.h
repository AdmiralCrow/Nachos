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
//SpaceId Fork(void (*func)());

extern void SysHalt();
extern void SysExit(int status);
extern int SysExec(char* name);
extern int SysJoin(int pid);
extern void SysCreate(char* name);
extern int SysOpen(char* name);
extern int SysRead(char* buffer, int size, int id);
extern int SysWrite(char* buffer, int size, int id);
extern void SysClose(int id);
extern int SysFork(void (*func)());  // Very important for you
extern void SysYield();
extern void SysKill(int pid);

#endif // SYSCALL_HANDLERS_H
