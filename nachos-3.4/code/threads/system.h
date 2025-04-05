// system.h
//	All global variables used in Nachos are defined here.
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


// Initialization and cleanup routines
extern void Initialize(int argc, char **argv); 	
extern void Cleanup();				
extern Thread *currentThread;			
extern Thread *threadToBeDestroyed;  		
extern Scheduler *scheduler;			
extern Interrupt *interrupt;			
extern Statistics *stats;			
extern Timer *timer;				


#ifdef USER_PROGRAM
#include "machine.h"
#include "memorymanager.h"
#include "synch.h"
#include "pcbmanager.h"
extern Machine* machine;	
extern MemoryManager* mm;
extern Lock* mmLock;
extern PCBManager* pcbManager;
#endif

#ifdef FILESYS_NEEDED 		
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

#endif // SYSTEM_H
