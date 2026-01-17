#include "Trip.h"

Trip::Trip(int id, Driver* d, Rider* r) {
    this->id = id;
    this->driver = d;
    this->rider = r;
    this->state = REQUESTED;
}

// Valid transition: REQUESTED -> ASSIGNED
bool Trip::assignDriver(Driver* d) {
    if (state == REQUESTED) {
        this->driver = d;
        this->state = ASSIGNED;
        return true;
    }
    return false;
}

// Valid transition: ASSIGNED -> ONGOING
bool Trip::startTrip() {
    if (state == ASSIGNED) {
        this->state = ONGOING;
        return true;
    }
    return false;
}

// Valid transition: ONGOING -> COMPLETED
bool Trip::completeTrip() {
    if (state == ONGOING) {
        this->state = COMPLETED;
        return true;
    }
    return false;
}

// Valid transition: REQUESTED or ASSIGNED -> CANCELLED
bool Trip::cancelTrip() {
    if (state == REQUESTED || state == ASSIGNED) {
        this->state = CANCELLED;
        return true;
    }
    return false;
}

TripState Trip::getState() {
    return state;
}

int Trip::getId() {
    return id;
}
