#include "Rider.h"

Rider::Rider(int id, int pickup, int dropoff) {
    this->id = id;
    this->pickupLocation = pickup;
    this->dropoffLocation = dropoff;
}

int Rider::getId() {
    return id;
}

int Rider::getPickup() {
    return pickupLocation;
}

int Rider::getDropoff() {
    return dropoffLocation;
}
