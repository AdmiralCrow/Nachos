#include "pcb.h"
#include <string.h>

PCB::PCB(int id) {
    pid = id;
    parent = NULL;
    children = new List();
    thread = NULL;
    exitStatus = -9999;
    nextFd = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        fileTable[i] = NULL;
    }
}

PCB::~PCB() {
    delete children;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileTable[i] != NULL) {
            delete fileTable[i];
        }
    }
}

void PCB::AddChild(PCB* pcb) {
    children->Append(pcb);
}

int PCB::RemoveChild(PCB* pcb) {
    return children->RemoveItem(pcb);
}

bool PCB::HasExited() {
    return exitStatus != -9999;
}

void decspn(int arg) {
    PCB* pcb = (PCB*)arg;
    if (pcb->HasExited()) pcbManager->DeallocatePCB(pcb);
    else pcb->parent = NULL;
}

void PCB::DeleteExitedChildrenSetParentNull() {
    children->Mapcar(decspn);
}

List* PCB::GetChildren() {
    return children;
}

int PCB::AllocateFileDescriptor(OpenFile* file) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileTable[i] == NULL) {
            fileTable[i] = file;
            return i;
        }
    }
    return -1; // No available file descriptor
}

OpenFile* PCB::GetFile(int fileDescriptor) {
    if (fileDescriptor >= 0 && fileDescriptor < MAX_FILES) {
        return fileTable[fileDescriptor];
    }
    return NULL;
}

void PCB::ReleaseFileDescriptor(int fileDescriptor) {
    if (fileDescriptor >= 0 && fileDescriptor < MAX_FILES && fileTable[fileDescriptor] != NULL) {
        delete fileTable[fileDescriptor];
        fileTable[fileDescriptor] = NULL;
    }
}
