#include "RideShareSystem.h"

RideShareSystem::RideShareSystem() {}

void RideShareSystem::requestRide(Rider* r) {
    Driver* d = engine.findAvailableDriver();

    if (d != nullptr) {
        Trip* t = new Trip(1, nullptr, r);  // correct constructor usage
        t->assignDriver(d);
        rollback.addTrip(t);
        d->setAvailable(false);
    }
}
void RideShareSystem::addDriver(Driver* d) {
    engine.addDriver(d);
}

