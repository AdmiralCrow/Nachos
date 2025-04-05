#include "pcb.h"
#include "synch.h"    // bring in the full Condition definition
#include "thread.h"

PCB::PCB(Thread *thread)
{
    processThread = thread;
    parentPCB = NULL;
    processID = -1;      // Will be set by Process Manager.
    exitStatus = 0;      // Default exit status.
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

// Added this getter for processThread
Thread* PCB::getThread() const {
    return processThread;
}
