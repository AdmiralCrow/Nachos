#ifndef PCB_H
#define PCB_H

#include "thread.h"   // for Thread*

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

    Thread* getThread() const;  // Getter for processThread

    void setStartAddress(int addr);     // ✅ NEW
    int getStartAddress() const;        // ✅ NEW

    // Condition variable for join (pointer only)
    Condition *joinCond;

private:
    int processID;
    Thread *processThread;
    PCB *parentPCB;
    int exitStatus;

    int startAddress;  // ✅ NEW: where child starts execution
};

#endif // PCB_H
