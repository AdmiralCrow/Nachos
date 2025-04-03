#include "syscall.h"

void ChildFunc() {
    Write("Child: I'm running!\n", 20, ConsoleOutput);
    Exit(42);  // Child exits W code 42
}

int main() {
    SpaceId child = Fork(ChildFunc);  // Fork a new process
    int status = Join(child);         // Waits for child to exit

    Write("Parent: child exited with code ", 32, ConsoleOutput);

    //print number
    char c = status + '0';
    Write(&c, 1, ConsoleOutput);
    Write("\n", 1, ConsoleOutput);

    Exit(0);  // Parent exits
}
