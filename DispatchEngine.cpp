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
    if (driverCount < 100) {
        drivers[driverCount++] = d;
    }
}

Driver* DispatchEngine::findAvailableDriver() {
    for (int i = 0; i < driverCount; i++) {
        if (drivers[i]->isAvailable()) {
            return drivers[i];
        }
    }
    return nullptr;
}

Trip* DispatchEngine::requestTrip(Rider* r) {
    Driver* d = findAvailableDriver();

    if (d == nullptr) {
        return nullptr;
    }

    d->setAvailable(false);

    Trip* t = new Trip(tripCount + 1, d, r);
    trips[tripCount++] = t;

    return t;
}

DispatchEngine::~DispatchEngine() {
    for (int i = 0; i < tripCount; i++) {
        delete trips[i];
    }

    delete[] trips;
    delete[] drivers;
}
