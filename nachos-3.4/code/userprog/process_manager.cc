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

int ProcessManager::Join(int childId)
{
    PCB* childPCB = getPCB(childId);
    if (childPCB == NULL) return -1;

    int parentId = currentThread->space->pcb->getID();
    if (childPCB->getParentID() != parentId) return -1;

    childPCB->waitForExit();
    return childPCB->getExitStatus();
}

void ProcessManager::Exit(int status)
{
    int pid = currentThread->space->pcb->getID();
    PCB* pcb = getPCB(pid);
    ASSERT(pcb != NULL);

    pcb->setExitStatus(status);
    pcb->signalExit();      // Wake up any parent waiting in Join()
    clearPID(pid);          // Remove from process table

    currentThread->Finish();  // Terminate thread (never returns)
}
