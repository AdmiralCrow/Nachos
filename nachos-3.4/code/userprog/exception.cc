// exception.cc  
//	Entry point into the Nachos kernel from user programs.
//	Handles syscalls and exceptions.
//  System call codes are read from register r2.
//  The result of the system call is placed in register r2.
//  PC registers must be incremented before returning to avoid infinite loops.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "syscall_handlers.h"

// Helper: Copy a null-terminated string from user space into kernel space.
char* User2Kernel(int addr) {
    const int maxLength = 256;
    char *kernelStr = new char[maxLength];
    int i = 0, val;
    while (i < maxLength - 1) {
        if (!machine->ReadMem(addr + i, 1, &val)) break;
        kernelStr[i] = (char)val;
        if (kernelStr[i] == '\0') break;
        i++;
    }
    kernelStr[i] = '\0';
    return kernelStr;
}

// Helper: Increment PC registers by 4 bytes.
static void IncrementPC() {
    int pc = machine->ReadRegister(PCReg);
    machine->WriteRegister(PrevPCReg, pc);
    pc = machine->ReadRegister(NextPCReg);
    machine->WriteRegister(PCReg, pc);
    machine->WriteRegister(NextPCReg, pc + 4);
}

void ExceptionHandler(ExceptionType which) {
    int type = machine->ReadRegister(2);  // system call code
    int pid = currentThread->space->getPCB()->getID();

    if (which == SyscallException) {
        switch (type) {
            case SC_Halt:
                DEBUG('a', "System Call: %d invoked Halt\n", pid);
                DEBUG('a', "Shutdown, initiated by user program.\n");
                interrupt->Halt();
                break;

            case SC_Exit:
                SysExit();
                break;

            case SC_Exec:
                SysExec();
                break;

            case SC_Join:
                SysJoin();
                break;

            case SC_Fork: {
                int funcAddr = machine->ReadRegister(4);
                DEBUG('a', "System Call: %d invoked Fork\n", pid);
                SpaceId childId = Fork((void (*)())funcAddr);
                DEBUG('a', "Process %d Fork: start at address 0x%x with %d pages memory\n", pid, funcAddr, 0);
                machine->WriteRegister(2, childId);
                break;
            }

            case SC_Yield:
                SysYield();
                break;

            case SC_Kill:
                SysKill();
                break;

            default:
                printf("Unexpected system call %d\n", type);
                ASSERT(FALSE);
        }
    } else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }

    // Advance PC so syscall instruction isn't repeated.
    IncrementPC();
}

