// system.h 
//    All global variables used in Nachos are defined here.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SYSTEM_H
#define SYSTEM_H

#include "copyright.h"
#include "utility.h"
#include "thread.h"
#include "scheduler.h"
#include "interrupt.h"
#include "stats.h"
#include "timer.h"

// Include headers for multiprogramming support:
#include "memory_manager.h"    // Memory Manager header
#include "process_manager.h"   // Process Manager header

// Initialization and cleanup routines
extern void Initialize(int argc, char **argv);  // Called before anything else
extern void Cleanup();                          // Called when Nachos is done

extern Thread *currentThread;          // The thread currently holding the CPU
extern Thread *threadToBeDestroyed;    // The thread that just finished
extern Scheduler *scheduler;           // The ready list
extern Interrupt *interrupt;           // Interrupt status
extern Statistics *stats;              // Performance metrics
extern Timer *timer;                   // The hardware timer device

#ifdef USER_PROGRAM
#include "machine.h"
extern Machine* machine;               // User program memory and registers
#endif

#ifdef FILESYS_NEEDED   // FILESYS or FILESYS_STUB
#include "filesys.h"
extern FileSystem  *fileSystem;
#endif

#ifdef FILESYS
#include "synchdisk.h"
extern SynchDisk   *synchDisk;
#endif

#ifdef NETWORK
#include "post.h"
extern PostOffice* postOffice;
#endif

// Global Memory Manager instance (to manage physical memory pages)
extern MemoryManager *memoryManager;

// Define a maximum number of user processes supported (adjust as needed)
#define MAX_PROCESSES 128

// Global Process Manager instance (to manage PCBs and process IDs)
extern ProcessManager *processManager;

#endif // SYSTEM_H
