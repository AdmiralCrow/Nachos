#include "pcb.h"
#include "synch.h"
#include "thread.h"
#include "filesys.h"
#include <map>

PCB::PCB(Thread *thread)
{
    processThread = thread;
    parentPCB = NULL;
    processID = -1;      // Will be set by Process Manager.
    exitStatus = 0;      // Default exit status.
    joinCond = new Condition("joinCond");
    nextFd = 0;          // Start file descriptor numbering from 0
}

PCB::~PCB()
{
    delete joinCond;

    // Close and delete all open files
    for (std::map<int, OpenFile*>::iterator it = fileTable.begin(); it != fileTable.end(); ++it) {
        delete it->second;
    }
    fileTable.clear();
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

//----------------------------------------------------------------------
// File descriptor management methods
//----------------------------------------------------------------------

int PCB::AllocateFileDescriptor(OpenFile* file) {
    int fd = nextFd++;
    fileTable[fd] = file;
    return fd;
}

OpenFile* PCB::GetFile(int fileDescriptor) {
    std::map<int, OpenFile*>::iterator it = fileTable.find(fileDescriptor);
    if (it != fileTable.end()) {
        return it->second;
    }
    return NULL;
}

void PCB::ReleaseFileDescriptor(int fileDescriptor) {
    std::map<int, OpenFile*>::iterator it = fileTable.find(fileDescriptor);
    if (it != fileTable.end()) {
        delete it->second; // Close the file
        fileTable.erase(it);
    }
}
