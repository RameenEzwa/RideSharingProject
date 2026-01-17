#include <iostream>
#include "City.h"
using namespace std;

City::City(int n, int z) {
    locations = n;
    zones = z;

    roads = new int*[locations];
    for (int i = 0; i < locations; i++) {
        roads[i] = new int[locations];
        for (int j = 0; j < locations; j++) {
            roads[i][j] = 0;
        }
    }

    zoneOfLocation = new int[locations];
    for (int i = 0; i < locations; i++) {
        zoneOfLocation[i] = 0;
    }
}

void City::addRoad(int a, int b, int d) {
    roads[a][b] = d;
    roads[b][a] = d;
}

int City::getDistance(int a, int b) {
    return roads[a][b];
}

void City::display() {
    for (int i = 0; i < locations; i++) {
        for (int j = 0; j < locations; j++) {
            cout << roads[i][j] << " ";
        }
        cout << endl;
    }
}

void City::setZone(int loc, int z) {
    zoneOfLocation[loc] = z;
}

int City::getZone(int loc) {
    return zoneOfLocation[loc];
}

int City::shortestPath(int start, int end) {
    int *dist = new int[locations];
    int *visited = new int[locations];

    for (int i = 0; i < locations; i++) {
        dist[i] = 1e9;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int k = 0; k < locations - 1; k++) {
        int u = -1;
        int minDist = 1e9;

        for (int i = 0; i < locations; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (roads[u][v] != 0 && !visited[v]) {
                int newDist = dist[u] + roads[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    int ans = dist[end];
    delete[] dist;
    delete[] visited;
    return ans;
}

int City::shortestPathWithZoneCost(int start, int end, int crossZoneCost) {
    int *dist = new int[locations];
    int *visited = new int[locations];

    for (int i = 0; i < locations; i++) {
        dist[i] = 1e9;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int k = 0; k < locations - 1; k++) {
        int u = -1;
        int minDist = 1e9;

        for (int i = 0; i < locations; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (roads[u][v] != 0 && !visited[v]) {

                int extra = 0;
                if (zoneOfLocation[u] != zoneOfLocation[v]) {
                    extra = crossZoneCost;
                }

                int newDist = dist[u] + roads[u][v] + extra;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    int ans = dist[end];
    delete[] dist;
    delete[] visited;
    return ans;
}

City::~City() {
    for (int i = 0; i < locations; i++) {
        delete[] roads[i];
    }
    delete[] roads;

    delete[] zoneOfLocation;
}
