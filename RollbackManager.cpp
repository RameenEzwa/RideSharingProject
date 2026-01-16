#include "RollbackManager.h"

RollbackManager::RollbackManager() {
    history = new Trip*[100];
    count = 0;
}

void RollbackManager::addTrip(Trip* t) {
    history[count++] = t;
}

void RollbackManager::rollbackLast() {
    if (count > 0) {
        history[--count]->cancelTrip();
    }
}

RollbackManager::~RollbackManager() {
    delete[] history;
}
