#ifndef CITY_H
#define CITY_H

class City {
    int locations;
    int **roads;
    int *zoneOfLocation;
    int zones;

public:
    City(int n, int z);
    void addRoad(int a, int b, int d);
    int getDistance(int a, int b);
    void display();

    void setZone(int loc, int z);
    int getZone(int loc);

    int shortestPath(int start, int end);
    int shortestPathWithZoneCost(int start, int end, int crossZoneCost);

    ~City();
};

#endif
