#include "pcb.h"
#include <string.h>

PCB::PCB(int id) {

    pid = id;
    parent = NULL;
    children = new List();
    thread = NULL;
    exitStatus = -9999;

}



PCB::~PCB() {

    delete children;
        for (std::map<int, OpenFile*>::iterator it = fileTable.begin(); it != fileTable.end(); ++it) {
    delete it->second;
}
}



void PCB::AddChild(PCB* pcb) {

    children->Append(pcb);


}


int PCB::RemoveChild(PCB* pcb){

    return children->RemoveItem(pcb);

}


bool PCB::HasExited() {
    return exitStatus == -9999 ? false : true;
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