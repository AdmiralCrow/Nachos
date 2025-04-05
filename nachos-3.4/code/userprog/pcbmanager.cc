#include "pcbmanager.h"
#include "system.h"

// Constructor: Initialize bitmap, array of PCBs, and lock
PCBManager::PCBManager(int maxProcesses) {
    bitmap = new BitMap(maxProcesses);
    pcbs = new PCB*[maxProcesses];
    pcbManagerLock = new Lock("pcbManagerLock");

    for (int i = 0; i < maxProcesses; i++) {
        pcbs[i] = NULL;
    }
}

// Destructor: Clean up resources
PCBManager::~PCBManager() {
    for (int i = 0; i < bitmap->NumBits(); i++) {
        if (pcbs[i] != NULL) {
            delete pcbs[i];
        }
    }
    delete[] pcbs;
    delete bitmap;
    delete pcbManagerLock;
}

// Allocate a new PCB and return a pointer to it
PCB* PCBManager::AllocatePCB(Thread* thread) {
    pcbManagerLock->Acquire();

    int pid = bitmap->Find();
    if (pid == -1) {
        pcbManagerLock->Release();
        return NULL;  // No free slots
    }

    PCB* newPCB = new PCB(thread);
    newPCB->setID(pid);
    pcbs[pid] = newPCB;

    pcbManagerLock->Release();
    return newPCB;
}

// Deallocate a PCB and free its slot
int PCBManager::DeallocatePCB(PCB* pcb) {
    int pid = pcb->getID();

    pcbManagerLock->Acquire();

    if (pcbs[pid] == NULL) {
        pcbManagerLock->Release();
        return -1; // PCB not found
    }

    delete pcbs[pid];
    pcbs[pid] = NULL;
    bitmap->Clear(pid);

    pcbManagerLock->Release();
    return 0;
}

// Retrieve a PCB by its process ID
PCB* PCBManager::GetPCB(int pid) {
    return pcbs[pid];
}
