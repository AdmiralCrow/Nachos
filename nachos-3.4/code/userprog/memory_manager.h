#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "copyright.h"
#include "bitmap.h"
#include "synch.h"

class MemoryManager {
public:
    // Constructor: initializes the bitmap with the total number of physical pages.
    MemoryManager(int numTotalPages);
    
    // Destructor: cleans up the allocated bitmap and lock.
    ~MemoryManager();
    
    // Allocates and returns the index of the first free physical page.
    // Returns -1 if no free page is found.
    int getPage();
    
    // Frees the page at the given index.
    void clearPage(int pageId);

private:
    BitMap *bitmap;  // Bitmap to track free/used physical pages.
    Lock *lock;      // Lock to protect bitmap operations.
};

#endif // MEMORY_MANAGER_H

