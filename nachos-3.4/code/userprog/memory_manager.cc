#include "memory_manager.h"
#include "system.h"
#include "process_manager.h"

#define MAX_PROCESSES 128  
ProcessManager* processManager = new ProcessManager(MAX_PROCESSES);


MemoryManager::MemoryManager(int numTotalPages) {
    // Create a bitmap with one bit per physical page.
    bitmap = new BitMap(numTotalPages);
    // Create a lock for synchronizing access to the bitmap.
    lock = new Lock("MemoryManagerLock");
}

MemoryManager::~MemoryManager() {
    delete bitmap;
    delete lock;
}

int MemoryManager::getPage() {
    // Acquire the lock to ensure thread safety.
    lock->Acquire();
    // Find the first free page (a clear bit in the bitmap).
    int page = bitmap->Find();  // Returns -1 if no free page is available.
    lock->Release();
    return page;
}

void MemoryManager::clearPage(int pageId) {
    // Acquire the lock before modifying the bitmap.
    lock->Acquire();
    bitmap->Clear(pageId);
    lock->Release();
}
