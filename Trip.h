#ifndef TRIP_H
#define TRIP_H

#include "Driver.h"
#include "Rider.h"

enum TripState { REQUESTED, ASSIGNED, ONGOING, COMPLETED, CANCELLED };

class Trip {
private:
    int id;
    Driver* driver;
    Rider* rider;
    TripState state;

public:
    Trip(int id, Driver* d, Rider* r);

    bool assignDriver(Driver* d);
    bool startTrip();
    bool completeTrip();
    bool cancelTrip();
    Driver* getDriver();


    TripState getState();
    int getId();
};

#endif
