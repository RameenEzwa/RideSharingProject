#include "Driver.h"

Driver::Driver(int id, int location) {
    this->id = id;
    this->currentLocation = location;
    this->available = true;
}

int Driver::getId() {
    return id;
}

int Driver::getLocation() {
    return currentLocation;
}

bool Driver::isAvailable() {
    return available;
}

void Driver::setAvailable(bool status) {
    available = status;
}

void Driver::setLocation(int loc) {
    currentLocation = loc;
}
