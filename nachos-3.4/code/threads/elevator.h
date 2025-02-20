#ifndef ELEVATOR_H 
#define ELEVATOR_H

#include "copyright.h"
#include "synch.h"

// Uncomment the following lines to check that HW1_LOCKS is defined.
//#ifndef HW1_LOCKS
//#error "HW1_LOCKS must be defined for elevator simulation."
//#endif

// These two functions are the interface for the elevator simulation.
// They should only be called when HW1_ELEVATOR is defined.
void Elevator(int numFloors);
void ArrivingGoingFromTo(int atFloor, int toFloor);

typedef struct Person {
    int id;
    int atFloor;
    int toFloor;
} Person;

class ELEVATOR {
public:
    ELEVATOR(int numFloors);
    ~ELEVATOR();
    // Called by person threads to request the elevator.
    void hailElevator(Person *p);
    // The elevator thread's main function.
    void start();

    // Public setter for termination condition.
    void setTotalRequests(int total) { totalRequests = total; }

private:
    int numFloors;
    int currentFloor;
    int occupancy;
    int maxOccupancy;
    Lock *elevatorLock;
    // Arrays of condition variables for each floor:
    Condition **entering; // Persons waiting to enter on each floor.
    Condition **leaving;  // Persons waiting to leave on each floor.
    // Counts for persons waiting:
    int *waitingToEnter;  // For each floor.
    int *waitingToLeave;  // For each floor.

    // For termination condition:
    int totalRequests;    // Total number of person requests expected.
    int servedRequests;   // Number of requests that have been served.
};

// Prototype for testing the elevator simulation.
void ElevatorTest(int numFloors, int numPersons);

// Declare the global elevator instance.
extern ELEVATOR *elevatorInstance;

#endif // ELEVATOR_H
