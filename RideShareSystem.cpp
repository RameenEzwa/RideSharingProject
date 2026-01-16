#include "RideShareSystem.h"

RideShareSystem::RideShareSystem() {}

void RideShareSystem::requestRide(Rider* r) {
    Driver* d = engine.findAvailableDriver();
    if (d != 0) {
        Trip* t = new Trip(1, r);
        t->assignDriver(d);
        rollback.addTrip(t);
        d->setAvailable(false);
    }
}
