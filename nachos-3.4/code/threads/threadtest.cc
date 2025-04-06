// threadtest.cc 

//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.

#include "copyright.h"
#include "system.h"
#include "synch.h"
#include <cstdlib>

// testnum is set in main.cc
int testnum = 1;


#ifdef HW1_CONDITIONS
// This branch tests Condition variable based synchronization.

Lock *condLock = new Lock("condLock");
Condition *barrierCV = new Condition("barrierCV");
int SharedVariable = 0;
int numThreadsActive;

void SimpleThread(int which) {
    int num, val;
    for (num = 0; num < 5; num++) {
        // Acquire the lock before accessing SharedVariable.
        condLock->Acquire();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val + 1;
        condLock->Release();
        currentThread->Yield();
    }

    // Acquire lock to update and check the barrier.
    condLock->Acquire();
    numThreadsActive--;
    // If this is the last thread, signal all waiting threads.
    if (numThreadsActive == 0)
        barrierCV->Broadcast(condLock);
    else
        // Otherwise, wait on the condition.
        barrierCV->Wait(condLock);
    condLock->Release();

    printf("Thread %d sees final value %d\n", which, SharedVariable);
}

void ThreadTest(int n) {
    DEBUG('t', "Entering ThreadTest (Condition version)");
    Thread *t;
    numThreadsActive = n;
    printf("NumThreadsActive = %d\n", numThreadsActive);

    for (int i = 1; i < n; i++) {
        t = new Thread("forked thread");
        t->Fork(SimpleThread, i);
    }
    SimpleThread(0);
}

void ThreadTest() {
    ThreadTest(2);
}


#elif defined(HW1_LOCKS)   // Use the Lock-based version for synchronization
// ---------------------
// Lock-based version (Exercise 2)
// ---------------------
// Global lock to protect shared data.

Lock *lock = new Lock("lock");

// Shared variable that all threads will increment.
int SharedVariable = 0;

// Counter to implement a barrier: tracks how many threads are still running.
int numThreadsActive;

//----------------------------------------------------------------------
// SimpleThread
//  Loop 5 times, yielding the CPU to allow context switching.
//  Each thread prints the shared variable before incrementing it.
//  After finishing the loop, each thread decrements the active-thread counter,
//  then waits (barrier) until all threads finish before printing the final value.
//----------------------------------------------------------------------
void SimpleThread(int which) {
    int num, val;
    for (num = 0; num < 5; num++) {
        // Entry section: acquire the lock before accessing SharedVariable.
        lock->Acquire();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val + 1;
        lock->Release();  // Exit section: release the lock.
        currentThread->Yield();
    }
    
    // Safely decrement the active thread counter.
    lock->Acquire();
    numThreadsActive--;
    lock->Release();
    
    // Barrier: wait until all threads have finished their loops.
    while (numThreadsActive > 0) {
        currentThread->Yield();
    }
    
    // Print the final value.
    printf("Thread %d sees final value %d\n", which, SharedVariable);
}

//----------------------------------------------------------------------
// ThreadTest(int n)
//  Fork "n" threads (numbered 0 to n-1) and have them execute SimpleThread.
//----------------------------------------------------------------------
void ThreadTest(int n) {
    DEBUG('t', "Entering ThreadTest (Lock version)");
    Thread *t;
    numThreadsActive = n;  // Set the number of threads that will run.
    printf("NumThreadsActive = %d\n", numThreadsActive);
    
    // Fork threads 1 through n-1.
    for (int i = 1; i < n; i++) {
        t = new Thread("forked thread");
        t->Fork(SimpleThread, i);
    }
    
    // Main thread runs as thread 0.
    SimpleThread(0);
}

//----------------------------------------------------------------------
// Default ThreadTest()
//  This ensures that when main.cc calls ThreadTest() without an argument,
//  the lock version is used with a default thread count (e.g., 2).
//----------------------------------------------------------------------
void ThreadTest() {
    ThreadTest(2);
}

#elif defined(HW1_SEMAPHORES)
//---------------------------------------------------------------------
// Semaphore-based version (existing version for Exercise 1)
//---------------------------------------------------------------------

// A binary semaphore to protect the shared variable.
Semaphore *mutex = new Semaphore("mutex", 1);

// Shared variable that all threads will increment.
int SharedVariable = 0;

// Used as a simple barrier: all threads decrement this until the last thread is done.
int numThreadsActive; 

void SimpleThread(int which) {
    int num, val;
    for (num = 0; num < 5; num++) {
        // Entry section: lock before reading and updating SharedVariable.
        mutex->P();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val + 1;
        mutex->V();  // Exit section: unlock.
        currentThread->Yield();
    }

    // Decrement the number of active threads safely.
    mutex->P();
    numThreadsActive--;
    mutex->V();

    // Barrier: wait until all threads finish the loop.
    while (numThreadsActive > 0) {
        currentThread->Yield();
    }

    // Print the final value.
    printf("Thread %d sees final value %d\n", which, SharedVariable);
}

void ThreadTest(int n) {
    DEBUG('t', "Entering ThreadTest (Semaphore version)");
    Thread *t;
    numThreadsActive = n;  // Set the number of threads that will run.
    printf("NumThreadsActive = %d\n", numThreadsActive);
    
    // Fork threads 1 through n-1.
    for (int i = 1; i < n; i++) {
        t = new Thread("forked thread");
        t->Fork(SimpleThread, i);
    }
    
    // Main thread runs as thread 0.
    SimpleThread(0);
}

void ThreadTest() {
    ThreadTest(2);
}

#else

// Unsynchronized version (for comparison/testing)

void SimpleThread(int which) {
    int num;
    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

void ThreadTest1() {
    DEBUG('t', "Entering ThreadTest1");
    Thread *t = new Thread("forked thread");
    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

void ThreadTest() {
    switch (testnum) {
        case 1:
            ThreadTest1();
            break;
        default:
            printf("No test specified.\n");
            break;
    }
}

#endif
