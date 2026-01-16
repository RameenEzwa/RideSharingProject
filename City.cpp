#include <iostream>
#include "City.h"

using namespace std;

// Constructor
City::City(int n) {
    locations = n;

    roads = new int*[locations];
    for (int i = 0; i < locations; i++) {
        roads[i] = new int[locations];
        for (int j = 0; j < locations; j++) {
            roads[i][j] = 0;   // no road initially
        }
    }
}

// Add road
void City::addRoad(int a, int b, int d) {
    roads[a][b] = d;
    roads[b][a] = d;   // undirected graph
}

// Get direct distance
int City::getDistance(int a, int b) {
    return roads[a][b];
}

// Display city map
void City::display() {
    for (int i = 0; i < locations; i++) {
        for (int j = 0; j < locations; j++) {
            cout << roads[i][j] << " ";
        }
        cout << endl;
    }
}

// Destructor
City::~City() {
    for (int i = 0; i < locations; i++) {
        delete[] roads[i];
    }
    delete[] roads;
}

