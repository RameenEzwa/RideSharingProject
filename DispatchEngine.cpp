#include "DispatchEngine.h"

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

Driver* DispatchEngine::findBestDriver(Rider* r, City* city, int crossZoneCost) {
    Driver* best = nullptr;
    int bestCost = 1e9;

    for (int i = 0; i < driverCount; i++) {
        if (!drivers[i]->isAvailable()) continue;

        int driverLoc = drivers[i]->getLocation();
        int cost = city->shortestPathWithZoneCost(driverLoc, r->getPickup(), crossZoneCost);

        if (cost < bestCost) {
            bestCost = cost;
            best = drivers[i];
        }
    }

    return best;
}

Trip* DispatchEngine::requestTrip(Rider* r, City* city, int crossZoneCost) {
    Driver* d = findBestDriver(r, city, crossZoneCost);

    if (d == nullptr) {
        return nullptr;
    }

    d->setAvailable(false);

    Trip* t = new Trip(tripCount + 1, d, r);
    trips[tripCount++] = t;

    return t;
}

void DispatchEngine::cancelTrip(Trip* t) {
    if (t != nullptr) {
        t->cancelTrip();
        t->getDriver()->setAvailable(true);
    }
}

int DispatchEngine::getTripCount() {
    return tripCount;
}

DispatchEngine::~DispatchEngine() {
    for (int i = 0; i < tripCount; i++) {
        delete trips[i];
    }

    delete[] trips;
    delete[] drivers;
}

