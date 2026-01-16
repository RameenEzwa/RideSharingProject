#include <iostream>
#include "RideShareSystem.h"
#include "Driver.h"
#include "Rider.h"

using namespace std;

int main() {
    RideShareSystem system;

    Driver d1(1, 0);
    Rider r1(1, 2, 5);

    system.requestRide(&r1);

    cout << "Ride requested successfully" << endl;
    return 0;
}
