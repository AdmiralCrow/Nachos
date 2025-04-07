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
    joinCond = new Condition("joinCond");
    exited = false;  // <- add this here
}
bool exited;


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

bool PCB::hasExited() const {
    return exited;
}

bool PCB::hasExited() const {
    return exited;
}

