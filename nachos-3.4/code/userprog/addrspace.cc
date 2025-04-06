// addrspace.cc  
//	Routines to manage address spaces (executing user programs).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include "pcb.h"  // So the compiler knows what PCB actually is
#include "machine.h"


#ifdef HOST_SPARC
#include <strings.h>
#endif

//----------------------------------------------------------------------
// SwapHeader
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
//----------------------------------------------------------------------
AddrSpace::AddrSpace(OpenFile *executable)
{
    NoffHeader noffH;
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
        (WordToHost(noffH.noffMagic) == NOFFMAGIC))
        SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

    ASSERT(numPages <= NumPhysPages);

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", numPages, size);
    DEBUG('a', "Loaded Program: %d code | %d data | %d bss\n", 
          noffH.code.size, noffH.initData.size, noffH.uninitData.size);

    pageTable = new TranslationEntry[numPages];
    for (i = 0; i < numPages; i++) {
        pageTable[i].virtualPage = i;
        int physPage = memoryManager->getPage();
        ASSERT(physPage != -1);
        pageTable[i].physicalPage = physPage;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;
    }

    bzero(machine->mainMemory, size);

    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", 
              noffH.code.virtualAddr, noffH.code.size);
        executable->ReadAt(&(machine->mainMemory[noffH.code.virtualAddr]),
                           noffH.code.size, noffH.code.inFileAddr);
    }
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", 
              noffH.initData.virtualAddr, noffH.initData.size);
        executable->ReadAt(&(machine->mainMemory[noffH.initData.virtualAddr]),
                           noffH.initData.size, noffH.initData.inFileAddr);
    }

    pcb = new PCB(currentThread);
    int pid = processManager->getPID();
    ASSERT(pid != -1);
    pcb->setID(pid);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace (Copy Constructor)
//----------------------------------------------------------------------
AddrSpace::AddrSpace(const AddrSpace *parentSpace)
{
    numPages = parentSpace->numPages;
    pageTable = new TranslationEntry[numPages];

    for (unsigned int i = 0; i < numPages; i++) {
        pageTable[i].virtualPage = i;
        int physPage = memoryManager->getPage();
        ASSERT(physPage != -1);
        pageTable[i].physicalPage = physPage;
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;

        int parentPhys = parentSpace->pageTable[i].physicalPage;
        bcopy(&machine->mainMemory[parentPhys * PageSize],
              &machine->mainMemory[physPage * PageSize],
              PageSize);
    }

    pcb = new PCB(currentThread);
    int pid = processManager->getPID();
    ASSERT(pid != -1);
    pcb->setID(pid);
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
//----------------------------------------------------------------------
AddrSpace::~AddrSpace()
{
    for (unsigned int i = 0; i < numPages; i++) {
        memoryManager->clearPage(pageTable[i].physicalPage);
    }
    delete [] pageTable;
    delete pcb;
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
//----------------------------------------------------------------------
void AddrSpace::InitRegisters()
{
    for (int i = 0; i < NumPhysPages; i++)
        machine->WriteRegister(i, 0);

    machine->WriteRegister(PCReg, 0;)	
    machine->WriteRegister(NextPCReg, 4);
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

void AddrSpace::SaveState() {}

void AddrSpace::RestoreState()
{
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
}

int AddrSpace::ReadFile(int virtAddr, OpenFile *file, int size, int fileAddr)
{
    int physAddr = virtAddr;
    char *buffer = new char[size];
    int bytesRead = file->ReadAt(buffer, size, fileAddr);
    bcopy(buffer, &machine->mainMemory[physAddr], bytesRead);
    delete [] buffer;
    return bytesRead;
}
