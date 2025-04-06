#include "syscall.h"

void child() {
    Write("Hello from child!\n", 18, 1);
    Exit(100);
}

int main() {
    Write("Before fork\n", 13, 1);
    Fork(child);
    Yield();
    Write("After fork\n", 12, 1);
    Exit(4);
}
