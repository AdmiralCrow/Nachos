#include "copyright.h"
#include "system.h"
#include "synch.h"
#include "elevator.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Global pointer to the elevator instance.
ELEVATOR *elevatorInstance = NULL;

// -------------------------
// Elevator Thread Function
// -------------------------
void ElevatorThread(int numFloors) {
    // Create an elevator instance.
    elevatorInstance = new ELEVATOR(numFloors);
    // Start the elevator loop.
    elevatorInstance->start();
}

// -------------------------
// Elevator Interface Function
// -------------------------
void Elevator(int numFloors) {
    // Create and fork the elevator thread.
    Thread *t = new Thread("Elevator");
    t->Fork(ElevatorThread, numFloors);
}

// -------------------------
// Person Thread Function
// -------------------------
void PersonThread(int arg) {
    Person *p = (Person *)arg;
    // Call the elevator's hail function.
    elevatorInstance->hailElevator(p);
    // Finish the thread.
    currentThread->Finish();
}

// Global counter for unique person IDs.
int nextPersonID = 1;
Lock *personIDLock = new Lock("PersonIDLock");

// Utility function to generate unique IDs.
int getNextPersonID() {
    personIDLock->Acquire();
    int id = nextPersonID;
    nextPersonID++;
    personIDLock->Release();
    return id;
}

// -------------------------
// Elevator Class Implementation
// -------------------------
ELEVATOR::ELEVATOR(int numFloorsArg) {
    numFloors = numFloorsArg;
    currentFloor = 1;      // Start at floor 1.
    occupancy = 0;
    maxOccupancy = 5;      // Elevator can fit 5 people.
    elevatorLock = new Lock("ElevatorLock");

    // Allocate arrays for condition variables and waiting counts.
    entering = new Condition*[numFloors];
    leaving  = new Condition*[numFloors];
    waitingToEnter = new int[numFloors];
    waitingToLeave = new int[numFloors];
    for (int i = 0; i < numFloors; i++) {
        char buffer[32];
        sprintf(buffer, "Entering %d", i+1);
        entering[i] = new Condition(buffer);
        sprintf(buffer, "Leaving %d", i+1);
        leaving[i] = new Condition(buffer);
        waitingToEnter[i] = 0;
        waitingToLeave[i] = 0;
    }
    // Initialize termination counters.
    totalRequests = 0;
    servedRequests = 0;
}

ELEVATOR::~ELEVATOR() {
    for (int i = 0; i < numFloors; i++) {
        delete entering[i];
        delete leaving[i];
    }
    delete [] entering;
    delete [] leaving;
    delete [] waitingToEnter;
    delete [] waitingToLeave;
    delete elevatorLock;
}

void ELEVATOR::start() {
    while (true) {
        elevatorLock->Acquire();
        // Print elevator arrival.
        printf("Elevator arrives on floor %d.\n", currentFloor);
        
        // Signal persons waiting to leave on this floor.
        if (waitingToLeave[currentFloor - 1] > 0) {
            leaving[currentFloor - 1]->Broadcast(elevatorLock);
        }
        // Signal persons waiting to enter on this floor if there is capacity.
        if (waitingToEnter[currentFloor - 1] > 0 && occupancy < maxOccupancy) {
            entering[currentFloor - 1]->Broadcast(elevatorLock);
        }
        
        // Check termination condition:
        // If the elevator has a known total request count and it has served all requests, stop.
        if (totalRequests > 0 && servedRequests == totalRequests) {
            elevatorLock->Release();
            break;
        }
        elevatorLock->Release();

        // Simulate travel delay: 50 ticks.
        for (int i = 0; i < 50; i++) {
            currentThread->Yield();
        }

        // Move to the next floor.
        if (currentFloor < numFloors)
            currentFloor++;
        else
            currentFloor = 1;
    }
    printf("Elevator simulation terminating: served all %d requests.\n", totalRequests);
}

void ELEVATOR::hailElevator(Person *p) {
    elevatorLock->Acquire();
    
    // Indicate waiting at current floor.
    waitingToEnter[p->atFloor - 1]++;

    // Wait for elevator to arrive at the person's floor AND check if there is space.
    while (currentFloor != p->atFloor || occupancy >= maxOccupancy) {
        entering[p->atFloor - 1]->Wait(elevatorLock);
    }
    
    // The person can now enter the elevator.
    waitingToEnter[p->atFloor - 1]--;
    occupancy++;
    printf("Person %d got into the elevator.\n", p->id);

    // The person states their destination floor.
    waitingToLeave[p->toFloor - 1]++;

    // Wait until the elevator reaches the destination floor.
    while (currentFloor != p->toFloor) {
        leaving[p->toFloor - 1]->Wait(elevatorLock);
    }
    
    waitingToLeave[p->toFloor - 1]--;
    occupancy--;
    printf("Person %d got out of the elevator.\n", p->id);

    servedRequests++;

    elevatorLock->Release();
}

void ArrivingGoingFromTo(int atFloor, int toFloor) {
    // Create a new Person structure.
    Person *p = new Person;
    p->id = getNextPersonID();
    p->atFloor = atFloor;
    p->toFloor = toFloor;
    
    // Print the request.
    printf("Person %d wants to go to floor %d from floor %d\n", p->id, toFloor, atFloor);
    
    // Create a new thread for the person.
    char buffer[32];
    sprintf(buffer, "Person %d", p->id);
    Thread *t = new Thread(buffer);
    t->Fork(PersonThread, (int)p);
}
