#ifndef PCB_H
#define PCB_H

#include "thread.h"
#include "synch.h"
#include "openfile.h"   // Needed for OpenFile*
#include <map>          // For std::map

class Condition;
class Thread;

class PCB {
public:
    PCB(Thread *thread);  
    ~PCB();

    int getID() const;
    void setID(int id);

    void setParent(PCB *parent);
    PCB* getParent() const;

    void setExitStatus(int status);
    int getExitStatus() const;

    Thread* getThread() const;

    // File descriptor management
    int AllocateFileDescriptor(OpenFile* file);
    OpenFile* GetFile(int fileDescriptor);
    void ReleaseFileDescriptor(int fileDescriptor);

    // Condition variable for join (pointer only)
    Condition *joinCond;

private:
    int processID;
    Thread *processThread;
    PCB *parentPCB;
    int exitStatus;

    // ✅ Add these:
    int nextFd;
    std::map<int, OpenFile*> fileTable;
};

#endif // PCB_H
