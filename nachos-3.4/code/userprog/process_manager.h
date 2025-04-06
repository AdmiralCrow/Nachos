#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include "copyright.h"
#include "bitmap.h"
#include "pcb.h"
#include "synch.h"

class ProcessManager {
public:
    // Constructor: initializes with a maximum number of processes.
    ProcessManager(int maxProcesses);
    ~ProcessManager();

    // Allocate and return an unused process ID.
    // Returns -1 if none is available.
    int getPID();

    // Free the given process ID.
    void clearPID(int pid);

    // Get the PCB for a given process ID.
    PCB* getPCB(int pid);

    // (Optional/Required) Add a PCB to the table.
    void addPCB(int pid, PCB* pcb) { pcbTable[pid] = pcb; }

    // Check if a process ID is a valid child of the current process.
    bool isChild(int pid);

    // Wait for the process with the given pid to finish.
    int Join(Thread* caller, int pid);

    // Kill the process with the given pid.
    bool Kill(int pid);

private:
    BitMap *pidMap;      // Bitmap tracking used process IDs.
    PCB **pcbTable;      // Array of PCB pointers, indexed by process ID.
    Lock *lock;          // Lock to protect allocation and access.
    int maxProcesses;    // Maximum number of processes supported.
};

#endif // PROCESS_MANAGER_H
