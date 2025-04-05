#include "memory_manager.h"
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

    //Find returns the index of a clear bit 
    // & sets the bit
    //0 is unset & 1 is set
    //initially, bitmap is all 0
    //Find returns -1 if no free space

    int page = bitmap->Find();
    return page;
}

int MemoryManager::DeallocatePage(int which) {

//Check if bit at specified location is set or not
    //if it is not, then its already clear and we dont
    //do anything, -1 for failure
    if(bitmap->Test(which) == false) return -1;
    else {

        //else, if it was set, clear it
        //0 for success
        bitmap->Clear(which);

        return 0;
    }

}


unsigned int MemoryManager::GetFreePageCount() {

    return bitmap->NumClear();

}


