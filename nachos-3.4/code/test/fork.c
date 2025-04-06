#include "syscall.h"

int global_cnt = 0;

void ChildFunction() {
    int i;
    for (i = 0; i < 100; i++) {
        global_cnt++;  // Simulated computation
    }
    Exit(100);  // Child exits with status 100
}

int main() {
    global_cnt++;

    // First child
    Fork(ChildFunction);
    Yield();  // Give child chance to run

    global_cnt++;

    // Second child
    Fork(ChildFunction);
    Yield();

    global_cnt++;

    // Third child
    Fork(ChildFunction);
    Yield();

    global_cnt++;
    
    // Parent exits with final global count as status
    Exit(global_cnt);
}
