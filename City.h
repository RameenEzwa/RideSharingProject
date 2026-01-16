#ifndef CITY_H
#define CITY_H

class City {
private:
    int locations;
    int **roads;      // ? THIS WAS MISSING

public:
    City(int n);
    void addRoad(int a, int b, int d);
    int getDistance(int a, int b);
    void display();
    ~City();
};

#endif


