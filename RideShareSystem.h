#ifndef RIDESHARESYSTEM_H
#define RIDESHARESYSTEM_H

#include "DispatchEngine.h"
#include "RollbackManager.h"
#include "City.h"
#include <iostream>
using namespace std;

class RideShareSystem {
private:
    DispatchEngine engine;
    RollbackManager rollback;

    int totalDistance;
    int completedTrips;
    int cancelledTrips;
    int totalTrips;

public:
    RideShareSystem();

    void addDriver(Driver* d);
    void requestRide(Rider* r, City* city, int crossZoneCost);

    void startLastTrip();
    void completeTrip();
    void cancelLastTrip();
    void rollbackKTrips(int k);
    TripState getLastTripState();
    int getCompletedTrips();


    void printAnalytics();
};

#endif


