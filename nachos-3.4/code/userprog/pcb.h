#ifndef PCB_H
#define PCB_H

#include "synch.h"

// Forward declaration
class Thread;

class PCB {
public:
    PCB(Thread *thread);  // Create a PCB for a process with the associated thread.
    ~PCB();

    int getID() const;       // Return the process ID.
    void setID(int id);      // Set the process ID.
    
    void setParent(PCB *parent);  // Set the parent PCB.
    PCB* getParent() const;       // Get the parent PCB.

    void setExitStatus(int status);  // Set exit status.
    int getExitStatus() const;       // Get exit status.
    
    // Condition variable for join (if needed later for waiting)
    Condition *joinCond;

private:
    int processID;
    Thread *processThread;
    PCB *parentPCB;
    int exitStatus;
};

#endif // PCB_H
