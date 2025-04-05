#ifndef PCB_H
#define PCB_H

#include "list.h"
#include "pcbmanager.h"
#include "openfile.h"
#include <map>

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

        //project 3
        // File descriptor management
        int AllocateFileDescriptor(OpenFile* file);
        OpenFile* GetFile(int fileDescriptor);
        void ReleaseFileDescriptor(int fileDescriptor);

    private:
        List* children;
        std::map<int, OpenFile*> fileTable; // Map for file descriptors
        int nextFd; // Counter for the next file descriptor to allocate

};

#endif // PCB_H