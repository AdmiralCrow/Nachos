// exception.cc
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

    if (which == SyscallException) {
        switch (type) {
            case SC_Halt:
                DEBUG('a', "System Call: Halt invoked.\n");
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

            case SC_Fork:
                SysFork();
                break;

            case SC_Yield:
                SysYield();
                break;

            case SC_Kill:
                SysKill();
                break;

            case SC_Create:
                SysCreate();
                break;

            case SC_Open:
                SysOpen();
                break;

            case SC_Read:
                SysRead();
                break;

            case SC_Write:
                SysWrite();
                break;

            case SC_Close:
                SysClose();
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