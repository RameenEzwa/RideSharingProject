#ifndef DISPATCHENGINE_H
#define DISPATCHENGINE_H

#include "Driver.h"
#include "Rider.h"
#include "Trip.h"
#include "City.h"

class DispatchEngine {
private:
    Driver **drivers;
    int driverCount;

    Trip **trips;
    int tripCount;

public:
    DispatchEngine();
    void addDriver(Driver *d);

    Driver* findBestDriver(Rider* r, City* city, int crossZoneCost);
    Trip* requestTrip(Rider* r, City* city, int crossZoneCost);

    void cancelTrip(Trip* t);
    int getTripCount();
    int calculateTripDistance(Rider* r, City* city);


    ~DispatchEngine();
};

#endif
