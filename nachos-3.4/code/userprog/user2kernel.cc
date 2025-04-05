// user2kernel.cc
#include "syscall_handlers.h"
#include "machine.h"

char* User2Kernel(int addr) {
    int i = 0;
    int oneChar;
    char* kernelBuf = new char[MaxFileLength + 1];

    do {
        machine->ReadMem(addr + i, 1, &oneChar);
        kernelBuf[i++] = (char)oneChar;
    } while (kernelBuf[i - 1] != '\0' && i < MaxFileLength);

    return kernelBuf;
}
