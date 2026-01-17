#include <iostream>
using namespace std;
#include "RideShareSystem.h"

RideShareSystem::RideShareSystem() {
    totalDistance = 0;
    completedTrips = 0;
    cancelledTrips = 0;
    totalTrips = 0;
}

void RideShareSystem::addDriver(Driver* d) {
    engine.addDriver(d);
}

void RideShareSystem::requestRide(Rider* r, City* city, int crossZoneCost) {
    Trip* t = engine.requestTrip(r, city, crossZoneCost);
    if (t != nullptr) {
        rollback.addTrip(t);
        totalTrips++;
    }
}

void RideShareSystem::startLastTrip() {
    Trip* last = rollback.getLastTrip();
    if (last != nullptr && last->getState() == ASSIGNED) {
        last->startTrip();
    }
}

void RideShareSystem::completeTrip() {
    Trip* last = rollback.getLastTrip();
    if (last != nullptr && last->getState() == ONGOING) {
        last->completeTrip();
        completedTrips++;
        totalDistance += last->getDistance();
    }
}

void RideShareSystem::cancelLastTrip() {
    Trip* last = rollback.getLastTrip();
    if (last != nullptr) {
        rollback.rollbackLast();
        cancelledTrips++;
    }
}

void RideShareSystem::rollbackKTrips(int k) {
    rollback.rollbackK(k);
}

void RideShareSystem::printAnalytics() {
    if (completedTrips == 0) {
        cout << "No completed trips yet." << endl;
        return;
    }
    cout << "Average Distance: " << (float)totalDistance / completedTrips << endl;
    cout << "Completed Trips: " << completedTrips << endl;
    cout << "Cancelled Trips: " << cancelledTrips << endl;
}



