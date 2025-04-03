
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
static void
IncrementPC() {
    int pc = machine->ReadRegister(PCReg);
    machine->WriteRegister(PrevPCReg, pc);
    pc = machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg, pc);
    machine->WriteRegister(NextPCReg, pc + 4);
}


void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);  // system call code

    if (which == SyscallException) {
        switch(type) {
        case SC_Halt:
            DEBUG('a', "System Call: %d invoked Halt\n", currentThread->GetSpaceId());
            DEBUG('a', "Shutdown, initiated by user program.\n");
            interrupt->Halt();
            break;

        case SC_Exit: {
            int status = machine->ReadRegister(4);
            DEBUG('a', "System Call: %d invoked Exit\n", currentThread->GetSpaceId());
            DEBUG('a', "Process %d exits with %d\n", currentThread->GetSpaceId(), status);
            // Call your kernel-level Exit() implementation here.
            Exit(status);
            break;
        }

        case SC_Exec: {
            // In a complete implementation, copy the filename from user space.
            char *filename = NULL; // Replace with code to copy from user space.
            DEBUG('a', "System Call: %d invoked Exec\n", currentThread->GetSpaceId());
            DEBUG('a', "Exec Program: %d loading %s\n", currentThread->GetSpaceId(),
                  filename ? filename : "unknown");
            SpaceId result = Exec(filename);
            machine->WriteRegister(2, result);
            break;
        }

        case SC_Join: {
            int childId = machine->ReadRegister(4);
            DEBUG('a', "System Call: %d invoked Join\n", currentThread->GetSpaceId());
            int joinResult = Join(childId);
            machine->WriteRegister(2, joinResult);
            break;
        }

        case SC_Fork: {
            int funcAddr = machine->ReadRegister(4);
            DEBUG('a', "System Call: %d invoked Fork\n", currentThread->GetSpaceId());
            // In a complete implementation, Fork() should:
            //   - Save old process registers.
            //   - Duplicate the AddrSpace.
            //   - Create a new thread and PCB.
            //   - Copy registers and set the PC to funcAddr.
            //   - Fork the new thread.
            SpaceId childId = processManager->Fork(funcAddr);
            // Debug message (numPage is a placeholder for the actual allocated pages)
            DEBUG('a', "Process %d Fork: start at address 0x%x with %d pages memory\n",
                  currentThread->GetSpaceId(), funcAddr, /*numPage*/ 0);
            machine->WriteRegister(2, childId);
            break;
        }

        case SC_Yield:
            DEBUG('a', "System Call: %d invoked Yield\n", currentThread->GetSpaceId());
            Yield();
            break;

        case SC_Kill: {
            int killedId = machine->ReadRegister(4);
            DEBUG('a', "System Call: %d invoked Kill\n", currentThread->GetSpaceId());
            int killResult = Kill(killedId);
            if (killResult == 0) {
                DEBUG('a', "Process %d killed process %d\n", currentThread->GetSpaceId(), killedId);
            } else {
                DEBUG('a', "Process %d cannot kill process %d: doesn't exist\n",
                      currentThread->GetSpaceId(), killedId);
            }
            machine->WriteRegister(2, killResult);
            break;
        }

        default:
            printf("Unexpected system call %d\n", type);
            break;
        }
    } else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }

    // Increment the program counter so that the syscall isn't re-executed.
    IncrementPC();
}
