#include "copyright.h"
#include "system.h"
#include "synch.h"
#include "elevator.h"

// ElevatorTest creates the elevator thread and spawns multiple person threads.
void ElevatorTest(int numFloors, int numPersons) {
    // Start the elevator thread.
    Elevator(numFloors);
    
    // Wait until the elevator instance is created.
    while (elevatorInstance == NULL) {
        currentThread->Yield();
    }
    
    // Set the total number of requests.
    elevatorInstance->setTotalRequests(numPersons);
    
    // Create numPersons person threads.
    for (int i = 0; i < numPersons; i++) {
        int atFloor = (Random() % numFloors) + 1; // Random starting floor.
        int toFloor = -1;
        do {
            toFloor = (Random() % numFloors) + 1; // Ensure destination is different.
        } while (toFloor == atFloor);
        
        ArrivingGoingFromTo(atFloor, toFloor);
        
        // Simulate a delay between arrivals.
        for (int j = 0; j < 10; j++) {
            currentThread->Yield();
        }
    }
}
