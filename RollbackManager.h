#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "Trip.h"

class RollbackManager {
private:
    Trip** history;
    int count;

public:
    RollbackManager();
    void addTrip(Trip* t);
    void rollbackLast();
    ~RollbackManager();
};

#endif
