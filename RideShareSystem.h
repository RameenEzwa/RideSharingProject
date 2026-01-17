#ifndef RIDESHARESYSTEM_H
#define RIDESHARESYSTEM_H

#include "DispatchEngine.h"
#include "RollbackManager.h"
#include "Rider.h"   // ✅ REQUIRED

class RideShareSystem {
private:
    DispatchEngine engine;
    RollbackManager rollback;

public:
    RideShareSystem();
    void requestRide(Rider* r);
    void addDriver(Driver* d);

};

#endif
