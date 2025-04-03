
// addrspace.h 
//	Data structures to keep track of executing user programs 
//	(address spaces).
//
//	Now, we include a pointer to a PCB for process management.
//	The user-level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "pcb.h"      // Include the PCB header

#define UserStackSize		1024 	// increase this as necessary!

class AddrSpace {
  public:
    AddrSpace(OpenFile *executable);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

    void InitRegisters();		// Initialize user-level CPU registers,
					// before jumping to user code
    void SaveState();			// Save address space-specific info on a context switch
    void RestoreState();		// Restore address space-specific info on a context switch

    // New function to load a segment from a file into the address space.
    int ReadFile(int virtAddr, OpenFile *file, int size, int fileAddr);

    // Accessor for the associated PCB.
    PCB* getPCB() { return pcb; }

  private:
    TranslationEntry *pageTable;	// Assume linear page table translation for now!
    unsigned int numPages;		// Number of pages in the virtual address space

    PCB *pcb;                     // Pointer to the process's PCB (for multiprogramming)
};

#endif // ADDRSPACE_H
