#ifndef PCB_H
#define PCB_H

#include "list.h"
#include "pcbmanager.h"
#include "openfile.h"

#define MAX_FILES 20

class Thread;
class PCBManager;
class Condition;
class Lock;
extern PCBManager* pcbManager;

class PCB {
public:
    PCB(int id);
    ~PCB();
    int pid;
    PCB* parent;
    Thread* thread;
    int exitStatus;

    void AddChild(PCB* pcb);
    int RemoveChild(PCB* pcb);
    bool HasExited();
    void DeleteExitedChildrenSetParentNull();
    List* GetChildren();

    int AllocateFileDescriptor(OpenFile* file);
    OpenFile* GetFile(int fileDescriptor);
    void ReleaseFileDescriptor(int fileDescriptor);

private:
    List* children;
    OpenFile* fileTable[MAX_FILES];
    int nextFd;
};

#endif // PCB_H
