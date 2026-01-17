#include "Trip.h"

Trip::Trip(int id, Driver* d, Rider* r, int distance) {
    this->id = id;
    this->driver = d;
    this->rider = r;
    this->state = REQUESTED;
    this->distance = distance;
}

void Trip::assignDriver(Driver* d) {
    if (state == REQUESTED) {
        this->driver = d;
        this->state = ASSIGNED;
    }
}

void Trip::startTrip() {
    if (state == ASSIGNED) {
        this->state = ONGOING;
    }
}

void Trip::completeTrip() {
    if (state == ONGOING) {
        this->state = COMPLETED;
    }
}

void Trip::cancelTrip() {
    if (state == REQUESTED || state == ASSIGNED || state == ONGOING) {
        this->state = CANCELLED;
    }
}

TripState Trip::getState() {
    return state;
}

int Trip::getId() {
    return id;
}

int Trip::getDistance() {
    return distance;
}

Driver* Trip::getDriver() {
    return driver;
}

Rider* Trip::getRider() {
    return rider;
}


TripState Trip::getState() {
    return state;
}

int Trip::getId() {
    return id;
}

int Trip::getDistance() {
    return distance;
}

Driver* Trip::getDriver() {
    return driver;
}

Rider* Trip::getRider() {
    return rider;
}


