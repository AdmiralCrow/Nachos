#include "memorymanager.h"
#include "machine.h"

MemoryManager::MemoryManager() {

    //mem allocated at the granularity of a page
    bitmap = new BitMap(NumPhysPages);
}


MemoryManager::~MemoryManager() {

    delete bitmap;

}

//returns which frame # is available to use 
int MemoryManager::AllocatePage() {

    int page = bitmap->Find();
    return page;
}

int MemoryManager::DeallocatePage(int which) {

    if(bitmap->Test(which) == false) return -1;
    else {

        bitmap->Clear(which);

        return 0;
    }

}


unsigned int MemoryManager::GetFreePageCount() {

    return bitmap->NumClear();

}


