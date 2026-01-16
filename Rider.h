#ifndef RIDER_H
#define RIDER_H

#include <string>

class Rider {
private:
    int id;
    int pickupLocation;
    int dropoffLocation;

public:
    Rider(int id, int pickup, int dropoff);
    int getId();
    int getPickup();
    int getDropoff();
};

#endif
