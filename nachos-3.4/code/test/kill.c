#include "syscall.h"

int main() {
    int pid = Fork();
    if (pid == 0) {
        // This is the child
        while (1) {
            Yield();  // Simulate doing something forever
        }
    } else {
        // Parent
        Yield();
        Kill(pid);
        Exit(0);
    }
    return 0; // not reached
}
