#include "pcb.h"
#include <map>
#include "openfile.h"
#include "list.h"
#include "processmanager.h"

PCB::PCB(Thread *thread) : processThread(thread), parentPCB(NULL), processID(-1), exitStatus(-9999), nextFd(0)
{
    children = new List();
}

PCB::~PCB()
{
    delete children;
    for (auto it = fileTable.begin(); it != fileTable.end(); ++it) {
        delete it->second;
    }
}

int PCB::getID() const { return processID; }
void PCB::setID(int id) { processID = id; }

void PCB::setParent(PCB *parent) { parentPCB = parent; }
PCB* PCB::getParent() const { return parentPCB; }

void PCB::setExitStatus(int status) { exitStatus = status; }
int PCB::getExitStatus() const { return exitStatus; }

bool PCB::HasExited() {
    return exitStatus != -9999;
}

void PCB::AddChild(PCB* pcb) {
    children->Append(pcb);
}

int PCB::RemoveChild(PCB* pcb) {
    return children->RemoveItem(pcb);
}

void decspn(int arg) {
    PCB* pcb = (PCB*)arg;
    if (pcb->HasExited()) pcbManager->DeallocatePCB(pcb);
    else pcb->setParent(NULL);
}

void PCB::DeleteExitedChildrenSetParentNull() {
    children->Mapcar(decspn);
}

List* PCB::GetChildren() {
    return children;
}

//----------------------------------------------------------------------
// PCB::AllocateFileDescriptor
//  Allocates a file descriptor for a given file.
//----------------------------------------------------------------------
int PCB::AllocateFileDescriptor(OpenFile* file) {
    int fd = nextFd++;
    fileTable[fd] = file;
    return fd;
}

//----------------------------------------------------------------------
// PCB::GetFile
//  Retrieves the file pointer based on the file descriptor.
//----------------------------------------------------------------------
OpenFile* PCB::GetFile(int fileDescriptor) {
    auto it = fileTable.find(fileDescriptor);
    return it != fileTable.end() ? it->second : NULL;
}

//----------------------------------------------------------------------
// PCB::ReleaseFileDescriptor
//  Releases and removes a specified file descriptor.
//----------------------------------------------------------------------
void PCB::ReleaseFileDescriptor(int fileDescriptor) {
    auto it = fileTable.find(fileDescriptor);
    if (it != fileTable.end()) {
        delete it->second;
        fileTable.erase(it);
    }
}
