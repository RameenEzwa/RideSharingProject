#include "RollbackManager.h"

RollbackManager::RollbackManager(int capacity) {
    this->capacity = capacity;
    history = new Trip*[capacity];
    count = 0;
}

void RollbackManager::addTrip(Trip* t) {
    if (count < capacity) {
        history[count++] = t;
    }
}

void RollbackManager::rollbackLast() {
    if (count > 0) {
        Trip* last = history[--count];

        if (last->getDriver() != nullptr) {
            last->getDriver()->setAvailable(true);
        }

        last->cancelTrip();
    }
}

void RollbackManager::rollbackK(int k) {
    for (int i = 0; i < k; i++) {
        rollbackLast();
    }
}

RollbackManager::~RollbackManager() {
    delete[] history;
}

