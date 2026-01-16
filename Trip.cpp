#include "Trip.h"

Trip::Trip(int id, Driver* d, Rider* r) {
    this->id = id;
    this->driver = d;
    this->rider = r;
    this->state = REQUESTED;
}

void Trip::assignDriver(Driver* d) {
    this->driver = d;
    this->state = ASSIGNED;
}

void Trip::startTrip() {
    this->state = ONGOING;
}

void Trip::completeTrip() {
    this->state = COMPLETED;
}

void Trip::cancelTrip() {
    this->state = CANCELLED;
}

TripState Trip::getState() {
    return state;
}

int Trip::getId() {
    return id;
}