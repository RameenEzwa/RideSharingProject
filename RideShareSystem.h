#ifndef RIDESHARESYSTEM_H
#define RIDESHARESYSTEM_H

#include "DispatchEngine.h"
#include "RollbackManager.h"
#include "City.h"

class RideShareSystem {
private:
    DispatchEngine engine;
    RollbackManager rollback;

public:
    RideShareSystem();

    void addDriver(Driver* d);
    void requestRide(Rider* r, City* city, int crossZoneCost);
    void cancelLastTrip();
};

#endif

