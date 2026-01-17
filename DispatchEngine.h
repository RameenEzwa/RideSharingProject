#ifndef DISPATCHENGINE_H
#define DISPATCHENGINE_H

#include "Driver.h"
#include "Rider.h"
#include "Trip.h"

class DispatchEngine {
private:
    Driver** drivers;
    int driverCount;

    Trip** trips;
    int tripCount;

public:
    DispatchEngine();

    void addDriver(Driver* d);

    Driver* findAvailableDriver();

    Trip* requestTrip(Rider* r);

    ~DispatchEngine();
};

#endif
