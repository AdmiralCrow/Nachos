// threadtest.cc 
//  Simple test case for the threads assignment.
//
//  Create multiple threads that context switch and update a shared variable.
//  This file contains both the unsynchronized version and the semaphore-synchronized
//  version, which is enabled by defining HW1_SEMAPHORES.
// 
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.

#include "copyright.h"
#include "system.h"
#include "synch.h"

// testnum is set in main.cc
int testnum = 1;

#ifdef HW1_SEMAPHORES

// A binary semaphore to protect the shared variable.
//Semaphore *mutex = new Semaphore("mutex", 1);
Lock *lock = new Lock("lock");


// Shared variable that all threads will increment.
int SharedVariable = 0;

// Used as a simple barrier: all threads decrement this until the last thread is done.
int numThreadsActive; 

//----------------------------------------------------------------------
// SimpleThread
//  Loop 5 times, yielding the CPU to allow context switching.
//  Each thread prints the shared variable before incrementing it.
//  At the end, all threads wait until every thread finishes its loop,
//  then they print the final value of SharedVariable.
//----------------------------------------------------------------------
void SimpleThread(int which) {

    int num, val;
    for (num = 0; num < 5; num++) {
        // Entry section: lock before reading and updating SharedVariable.
        //mutex->P();
        lock = Acquire();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val + 1;
        lock->Release();
        //mutex->V();  // Exit section: unlock.
        currentThread->Yield();
    }

    // Decrement the number of active threads safely.
    lock = Acquire();
    //mutex->P();
    numThreadsActive--;
    //mutex->V();
    lock->Release();

    // Barrier: Wait until all threads finish the loop.
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
    DEBUG('t', "Entering ThreadTest");
    
    static bool alreadyRan = false;
    if (alreadyRan) {
        //printf("Warning: ThreadTest() called again!\n");
        return;
    }
    alreadyRan = true;

    Thread *t;
    numThreadsActive = n;  // Set the number of threads that will run.
    printf("NumThreadsActive = %d\n", numThreadsActive);
    
    // Fork threads 1 through n-1.
    for (int i = 1; i < n; i++) {
        t = new Thread("forked thread");
        t->Fork(SimpleThread, i);
        currentThread->Yield();
    }
    
    // Main thread runs as thread 0.
    SimpleThread(0);
}

//----------------------------------------------------------------------
// Default ThreadTest()
//  This is added so that main.cc, which calls ThreadTest() with no arguments,
//  will link correctly. It calls ThreadTest(n) with a default value (e.g., 2).
//----------------------------------------------------------------------
void ThreadTest() {
    ThreadTest(2);  //setting the value.
}

#else  // Unsynchronized version (for comparison/testing)

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

