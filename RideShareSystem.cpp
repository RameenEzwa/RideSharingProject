#include "RideShareSystem.h"

RideShareSystem::RideShareSystem() {}

void RideShareSystem::addDriver(Driver* d) {
    engine.addDriver(d);
}

void RideShareSystem::requestRide(Rider* r, City* city, int crossZoneCost) {
    Trip* t = engine.requestTrip(r, city, crossZoneCost);

    if (t != nullptr) {
        rollback.addTrip(t);
    }
}

void RideShareSystem::cancelLastTrip() {
    rollback.rollbackLast();
}
