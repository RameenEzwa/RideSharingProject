#include "DispatchEngine.h"

#include <iostream>
using namespace std;

DispatchEngine::DispatchEngine() {
    drivers = new Driver*[100];
    driverCount = 0;
    trips = new Trip*[100];
    tripCount = 0;
}

void DispatchEngine::addDriver(Driver* d) {
    drivers[driverCount++] = d;
}

Trip* DispatchEngine::requestTrip(Rider* r) {
    for (int i = 0; i < driverCount; i++) {
        if (drivers[i]->isAvailable()) {
            Trip* t = new Trip(tripCount + 1, drivers[i], r);
            t->assignDriver(drivers[i]);
            drivers[i]->setAvailable(false);
            trips[tripCount++] = t;
            return t;
        }
    }
    return nullptr;
}

DispatchEngine::~DispatchEngine() {
    for (int i = 0; i < tripCount; i++)
        delete trips[i];
    delete[] trips;
    delete[] drivers;
}
