#include "process_manager.h"
#include "system.h"

ProcessManager::ProcessManager(int maxProcs)
{
    maxProcesses = maxProcs;
    pidMap = new BitMap(maxProcesses);
    pcbTable = new PCB*[maxProcesses];
    for (int i = 0; i < maxProcesses; i++) {
        pcbTable[i] = NULL;
    }
    lock = new Lock("ProcessManagerLock");
}

ProcessManager::~ProcessManager()
{
    delete pidMap;
    for (int i = 0; i < maxProcesses; i++) {
        if (pcbTable[i] != NULL) {
            delete pcbTable[i];
        }
    }
    delete [] pcbTable;
    delete lock;
}
void ProcessManager::setPCB(int pid, PCB* pcb) {
    lock->Acquire();
    if (pid >= 0 && pid < maxProcesses) {
        pcbTable[pid] = pcb;
    }
    lock->Release();
}

int ProcessManager::getPID()
{
    lock->Acquire();
    int pid = pidMap->Find(); // Find returns first clear bit or -1 if none.
    if (pid != -1) {
        pidMap->Mark(pid);
    }
    lock->Release();
    return pid;
}

void ProcessManager::clearPID(int pid)
{
    lock->Acquire();
    if (pid >= 0 && pid < maxProcesses) {
        pidMap->Clear(pid);
        pcbTable[pid] = NULL;
    }
    lock->Release();
}

PCB* ProcessManager::getPCB(int pid)
{
    lock->Acquire();
    PCB *pcb = NULL;
    if (pid >= 0 && pid < maxProcesses) {
        pcb = pcbTable[pid];
    }
    lock->Release();
    return pcb;
}

bool ProcessManager::isChild(int pid) {
    return pidMap->Test(pid) && pcbTable[pid]->getParent() == currentThread->space->getPCB();
}

int ProcessManager::Join(Thread *parent, int pid) {
    lock->Acquire(); 
    PCB *childPCB = pcbTable[pid];
    while (!childPCB->hasExited()) {
        childPCB->joinCond->Wait(lock);  
    }

    int status = childPCB->getExitStatus();

    lock->Release();  

    return status;
}


bool ProcessManager::Kill(int pid) {
    if (!pidMap->Test(pid)) return false;
    delete pcbTable[pid];   // or handle more gracefully
    pidMap->Clear(pid);
    return true;
}
