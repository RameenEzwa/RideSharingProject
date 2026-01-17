#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "Trip.h"

class RollbackManager {
private:
    Trip** history;
    int count;
    int capacity;

public:
    RollbackManager(int capacity = 100);

    void addTrip(Trip* t);

    void rollbackLast();

    void rollbackK(int k);

    ~RollbackManager();
};

#endif
