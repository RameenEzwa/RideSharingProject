#include "RideShareSystem.h"

RideShareSystem::RideShareSystem() {}

void RideShareSystem::addDriver(Driver* d) {
    engine.addDriver(d);
}

Trip* RideShareSystem::requestRide(Rider* r, City* city, int crossZoneCost) {
    Trip* t = engine.requestTrip(r, city, crossZoneCost);

    if (t != nullptr) {
        rollback.addTrip(t);
    }

    return t;
}

void RideShareSystem::cancelLastTrip() {
    rollback.rollbackLast();
}

int RideShareSystem::getCompletedTrips() {
    return rollback.getCompletedCount();
}

int RideShareSystem::getCancelledTrips() {
    return rollback.getCancelledCount();
}

double RideShareSystem::getAverageDistance() {
    return rollback.getAverageDistance();
}
