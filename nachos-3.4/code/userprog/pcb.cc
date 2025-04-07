#include "pcb.h"
#include "synch.h"
#include "thread.h"

PCB::PCB(Thread *thread)
{
    processThread = thread;
    parentPCB = NULL;
    processID = -1;      // Will be set by Process Manager.
    exitStatus = 0;      // Default exit status.
    startAddress = 0;    // Default start address for child processes
    joinCond = new Condition("joinCond");
}

PCB::~PCB()
{
    delete joinCond;
}

int PCB::getID() const {
    return processID;
}

void PCB::setID(int id) {
    processID = id;
}

void PCB::setParent(PCB *parent) {
    parentPCB = parent;
}

PCB* PCB::getParent() const {
    return parentPCB;
}

void PCB::setExitStatus(int status) {
    exitStatus = status;
}

int PCB::getExitStatus() const {
    return exitStatus;
}

Thread* PCB::getThread() const {
    return processThread;
}

// NEW: store the program counter for child process (e.g., from Fork())
void PCB::setStartAddress(int addr) {
    startAddress = addr;
}

int PCB::getStartAddress() const {
    return startAddress;
}
