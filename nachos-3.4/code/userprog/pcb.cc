#include "pcb.h"
#include "synch.h"
#include "thread.h"

PCB::PCB(Thread *thread)
{
    processThread = thread;
    parentPCB = NULL;
    processID = -1;
    exitStatus = 0;
    startAddress = 0;
    exited = false;  // initialize properly
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

void PCB::setExitStatus(int status, Lock *lock) {
    lock->Acquire();
    exitStatus = status;
    exited = true;
    joinCond->Broadcast(lock);
    lock->Release();
}


int PCB::getExitStatus() const {
    return exitStatus;
}

Thread* PCB::getThread() const {
    return processThread;
}

void PCB::setStartAddress(int addr) {
    startAddress = addr;
}

int PCB::getStartAddress() const {
    return startAddress;
}

bool PCB::hasExited() const {
    return exited;
}
