#include <iostream>
#include "RideShareSystem.h"
#include "Driver.h"
#include "Rider.h"
#include "City.h"

using namespace std;

int main() {

    City city(6);

    city.addRoad(0, 1, 5);
    city.addRoad(1, 2, 7);
    city.addRoad(2, 3, 6);
    city.addRoad(3, 4, 8);
    city.addRoad(4, 5, 4);

    RideShareSystem system;

    Driver d1(1, 0);
    Driver d2(2, 3);

    system.addDriver(&d1);
    system.addDriver(&d2);

    Rider r1(1, 2, 5);

    system.requestRide(&r1);

    cout << "Ride requested successfully" << endl;

    cout << "City Map:" << endl;
    city.display();

    return 0;
}
