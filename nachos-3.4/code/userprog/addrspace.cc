// addrspace.cc  
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include "synch.h"
#include "pcb.h"
#ifdef HOST_SPARC
#include <strings.h>
#endif

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------
static void 
SwapHeader (NoffHeader *noffH)
{
    noffH->noffMagic = WordToHost(noffH->noffMagic);
    noffH->code.size = WordToHost(noffH->code.size);
    noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
    noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
    noffH->initData.size = WordToHost(noffH->initData.size);
    noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
    noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
    noffH->uninitData.size = WordToHost(noffH->uninitData.size);
    noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
    noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//----------------------------------------------------------------------
AddrSpace::AddrSpace(OpenFile *executable)
{
    NoffHeader noffH;
    unsigned int i, size;

    // Read and possibly swap the header
    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
        (WordToHost(noffH.noffMagic) == NOFFMAGIC))
        SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    // Calculate the size of the address space: code, init data, uninit data, plus stack.
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

    // Check that we don't exceed physical memory (until virtual memory is implemented).
    ASSERT(numPages <= NumPhysPages);

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", numPages, size);

    // --- Debug Print: Loaded Program segments ---
    DEBUG('a', "Loaded Program: %d code | %d data | %d bss\n", 
          noffH.code.size, noffH.initData.size, noffH.uninitData.size);

    // Set up the translation:
    // Use the Memory Manager to allocate a free physical page for each virtual page.
    pageTable = new TranslationEntry[numPages];
    int freePages = memoryManager->countFreePages();
    DEBUG('a', "Requesting %d pages, available: %d\n", numPages, freePages);
    ASSERT(numPages <= freePages); // Optional, can also gracefully handle below
    
    for (i = 0; i < numPages; i++) {
        int physPage = memoryManager->getPage();
        if (physPage == -1) {
            printf("Out of memory: could not allocate page %d\n", i);
            currentThread->Finish();  // Or call Exit(-1);
            return;
        }
    
        pageTable[i].virtualPage = i;
        pageTable[i].physicalPage = physPage;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
    }
    
    
    for (i = 0; i < numPages; i++) {
        int physAddr = pageTable[i].physicalPage * PageSize;
        bzero(&machine->mainMemory[physAddr], PageSize);
    }
    

    // Copy the code segment from the NOFF file into memory.
    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", 
              noffH.code.virtualAddr, noffH.code.size);
        executable->ReadAt(&(machine->mainMemory[noffH.code.virtualAddr]),
                           noffH.code.size, noffH.code.inFileAddr);
    }
    // Copy the initialized data segment.
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", 
              noffH.initData.virtualAddr, noffH.initData.size);
        executable->ReadAt(&(machine->mainMemory[noffH.initData.virtualAddr]),
                           noffH.initData.size, noffH.initData.inFileAddr);
    }
    // The uninitialized data segment (bss) is already zeroed out by bzero.

    // --- Create and associate a PCB with this address space ---
    // Assume processManager is a global pointer to the Process Manager.
    pcb = new PCB(currentThread);
    int pid = processManager->getPID();
    ASSERT(pid != -1);
    pcb->setID(pid);
    // Optionally, set the parent PCB if applicable.
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Deallocate an address space.
//----------------------------------------------------------------------
AddrSpace::~AddrSpace()
{
    // Free each physical page allocated using the Memory Manager.
    for (unsigned int i = 0; i < numPages; i++) {
        memoryManager->clearPage(pageTable[i].physicalPage);
    }
    delete [] pageTable;
    delete pcb;  // Clean up the associated PCB.
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace (copy constructor)
//  Clone an existing address space (used in Fork)
//----------------------------------------------------------------------
AddrSpace::AddrSpace(AddrSpace *parent)
{
        numPages = parent->numPages;
        pageTable = new TranslationEntry[numPages];

        for (unsigned int i = 0; i < numPages; i++) {
            int newPhysPage = memoryManager->getPage();
            ASSERT(newPhysPage != -1); // Ensure page available

            // Copy page table entry
            pageTable[i].virtualPage = i;
            pageTable[i].physicalPage = newPhysPage;
            pageTable[i].valid = TRUE;
            pageTable[i].use = FALSE;
            pageTable[i].dirty = FALSE;
            pageTable[i].readOnly = parent->pageTable[i].readOnly;

            // Copy content from parent's physical page to new physical page
            int parentPhysPage = parent->pageTable[i].physicalPage;
            bcopy(&machine->mainMemory[parentPhysPage * PageSize],
                &machine->mainMemory[newPhysPage * PageSize],
                PageSize);
        }

        // Allocate a PCB for the new address space
        int pid = processManager->getPID();
        ASSERT(pid != -1);
        pcb = new PCB(currentThread);
        pcb->setID(pid);
        processManager->setPCB(pid, pcb);
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//----------------------------------------------------------------------
void
AddrSpace::InitRegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister(i, 0);

    // Set the initial program counter to 0.
    machine->WriteRegister(PCReg, 0);	

    // Set the next instruction counter.
    machine->WriteRegister(NextPCReg, 4);

    // Set the stack pointer to the end of the address space.
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state specific to this address space.
//----------------------------------------------------------------------
void AddrSpace::SaveState() 
{
    // Currently, nothing to save.
}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that this address space can run.
//----------------------------------------------------------------------
void AddrSpace::RestoreState() 
{
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
}

//----------------------------------------------------------------------
// AddrSpace::ReadFile
// 	Load a segment from an open file into the address space's memory.
// 	This function translates the virtual address to physical memory using the 
// 	page table and copies 'size' bytes from the file starting at 'fileAddr' into
// 	the address space starting at 'virtAddr'.
// 	Returns the number of bytes read.
//----------------------------------------------------------------------
int AddrSpace::ReadFile(int virtAddr, OpenFile *file, int size, int fileAddr)
{
    // In a complete implementation, you'd translate virtAddr to a physical address.
    // For now, assume a direct mapping.
    int physAddr = virtAddr; // Replace with translation using your page table.
    char *buffer = new char[size];
    int bytesRead = file->ReadAt(buffer, size, fileAddr);
    bcopy(buffer, &machine->mainMemory[physAddr], bytesRead);
    delete [] buffer;
    return bytesRead;
}