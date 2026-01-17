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
    cout << "Test 1 (Graph OK): City created with roads and zones." << endl;

    int dist = city.shortestPath(0, 3);
    cout << "Test 2 (Shortest Path 0->3): " << dist << " (Expected 18)" << endl;

    int distZone = city.shortestPathWithZoneCost(0, 3, 10);
    cout << "Test 3 (Zone Cost 0->3): " << distZone << endl;

    RideShareSystem system;

    Driver d1(1, 0);
    Driver d2(2, 3);

    system.addDriver(&d1);
    system.addDriver(&d2);
    cout << "Test 4 (Drivers added): " << d1.isAvailable() << " " << d2.isAvailable() << endl;

    Rider r1(1, 2, 5);
    system.requestRide(&r1, &city, 10);
    cout << "Test 5 (Ride requested): Driver d1 available? " << d1.isAvailable() << endl;

    system.startLastTrip();
    cout << "Test 6 (Trip started): " << (system.getLastTripState() == ONGOING) << endl;

    system.completeTrip();
    cout << "Test 7 (Trip completed): " << system.getCompletedTrips() << endl;

    system.requestRide(&r1, &city, 10);
    system.cancelLastTrip();
    cout << "Test 8 (Cancel trip): Driver available? " << d1.isAvailable() << endl;

    system.requestRide(&r1, &city, 10);
    system.rollbackKTrips(1);
    cout << "Test 9 (Rollback): Driver available? " << d1.isAvailable() << endl;
    
    system.printAnalytics();

    cout << "City Map:" << endl;
    city.display();

    return 0;
}