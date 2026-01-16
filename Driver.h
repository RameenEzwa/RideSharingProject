#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
private:
    int id;
    int currentLocation;
    bool available;

public:
    Driver(int id, int location);
    int getId();
    int getLocation();
    bool isAvailable();
    void setAvailable(bool status);
    void setLocation(int loc);
};

#endif
