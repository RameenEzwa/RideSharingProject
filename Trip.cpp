#include "Trip.h"

Trip::Trip(int id, Driver* d, Rider* r) {
    this->id = id;
    this->driver = d;
    this->rider = r;
    this->state = REQUESTED;
}

bool Trip::assignDriver(Driver* d) {
    if (state == REQUESTED) {
        this->driver = d;
        this->state = ASSIGNED;
        return true;
    }
    return false;
}

bool Trip::startTrip() {
    if (state == ASSIGNED) {
        this->state = ONGOING;
        return true;
    }
    return false;
}

bool Trip::completeTrip() {
    if (state == ONGOING) {
        this->state = COMPLETED;
        return true;
    }
    return false;
}

bool Trip::cancelTrip() {
    if (state == REQUESTED || state == ASSIGNED) {
        this->state = CANCELLED;
        return true;
    }
    return false;
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
