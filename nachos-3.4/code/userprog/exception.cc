
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


// Helper function to increment the program counter registers by 4 (one word)
static void IncrementPC() {
    int pc = machine->ReadRegister(PCReg);
    machine->WriteRegister(PrevPCReg, pc);
    pc = machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg, pc);
    machine->WriteRegister(NextPCReg, pc + 4);
}

extern int doFork(int);
extern int doExec(char*);
extern void doExit(int);
extern int doJoin(int);
extern int doKill(int);
extern void doYield();
extern void doCreate(char*);
extern int doOpen(char*);
extern void doClose(OpenFileId);
extern int doRead(int, int, OpenFileId);
extern int doWrite(int, int, OpenFileId);
extern char* readString(int); // read string from virtual memory

void ExceptionHandler(ExceptionType which) {
    int type = machine->ReadRegister(2);  // system call code

    if (which == SyscallException) {
        switch(type) {
        case SC_Halt:
            DEBUG('a', "Shutdown, initiated by user program.\n");
            interrupt->Halt();
            break;

        case SC_Exit:
            doExit(machine->ReadRegister(4));
            break;

        case SC_Fork: {
            int funcAddr = machine->ReadRegister(4);
            int ret = doFork(funcAddr);
            machine->WriteRegister(2, ret);
            break;
        }

        case SC_Exec: {
            int virtAddr = machine->ReadRegister(4);
            char* filename = readString(virtAddr);
            int ret = doExec(filename);
            machine->WriteRegister(2, ret);
            delete[] filename;
            break;
        }

        case SC_Join: {
            int childId = machine->ReadRegister(4);
            int ret = doJoin(childId);
            machine->WriteRegister(2, ret);
            break;
        }

        case SC_Kill: {
            int targetPid = machine->ReadRegister(4);
            int ret = doKill(targetPid);
            machine->WriteRegister(2, ret);
            break;
        }

        case SC_Yield:
            doYield();
            break;

        case SC_Create: {
            int virtAddr = machine->ReadRegister(4);
            char* filename = readString(virtAddr);
            doCreate(filename);
            delete[] filename;
            break;
        }

        case SC_Open: {
            int virtAddr = machine->ReadRegister(4);
            char* filename = readString(virtAddr);
            int ret = doOpen(filename);
            machine->WriteRegister(2, ret);
            delete[] filename;
            break;
        }

        case SC_Close: {
            OpenFileId fid = (OpenFileId)machine->ReadRegister(4);
            doClose(fid);
            break;
        }

        case SC_Read: {
            int virtAddr = machine->ReadRegister(4);
            int size = machine->ReadRegister(5);
            OpenFileId fid = (OpenFileId)machine->ReadRegister(6);
            int ret = doRead(virtAddr, size, fid);
            machine->WriteRegister(2, ret);
            break;
        }

        case SC_Write: {
            int virtAddr = machine->ReadRegister(4);
            int size = machine->ReadRegister(5);
            OpenFileId fid = (OpenFileId)machine->ReadRegister(6);
            int ret = doWrite(virtAddr, size, fid);
            machine->WriteRegister(2, ret);
            break;
        }

        default:
            printf("Unexpected system call %d\n", type);
            ASSERT(FALSE);
            break;
        }

        IncrementPC(); // Always increment PC after handling syscall
    } else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }
}
