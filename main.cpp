#include <iostream>
#include "RideShareSystem.h"
#include "Driver.h"
#include "Rider.h"
#include "City.h"

using namespace std;

int main() {

    City city(6, 2);

    city.addRoad(0, 1, 5);
    city.addRoad(1, 2, 7);
    city.addRoad(2, 3, 6);
    city.addRoad(3, 4, 8);
    city.addRoad(4, 5, 4);

    city.setZone(0, 0);
    city.setZone(1, 0);
    city.setZone(2, 1);
    city.setZone(3, 1);
    city.setZone(4, 1);
    city.setZone(5, 1);

    RideShareSystem system;

    Driver d1(1, 0);
    Driver d2(2, 3);

    system.addDriver(&d1);
    system.addDriver(&d2);

    Rider r1(1, 2, 5);

    system.requestRide(&r1, &city, 10);
    cout << "Ride requested successfully" << endl;

    system.completeTrip();
    cout << "Trip completed" << endl;

    system.printAnalytics();

    cout << "City Map:" << endl;
    city.display();

    return 0;
}


