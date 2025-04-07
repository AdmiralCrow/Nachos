#ifndef PCB_H
#define PCB_H

#include "thread.h"   
#include "synch.h"  

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

    void setExitStatus(int status, Lock *lock);
    int getExitStatus() const;

    Thread* getThread() const;  // Getter for processThread

    void setStartAddress(int addr);     
    int getStartAddress() const;        
   
    bool hasExited() const;     // Used by Join
    Lock* getLock() const;


    // Condition variable for join (pointer only)
    Condition *joinCond;

private:
    int processID;
    Thread *processThread;
    PCB *parentPCB;
    int exitStatus;
    bool exited;
    int startAddress;  
};

#endif // PCB_H
