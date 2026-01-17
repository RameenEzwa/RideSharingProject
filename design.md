# Ride-Sharing Dispatch & Trip Management System – Design

## 1. Graph Representation and Routing
The city is represented as a weighted graph using an adjacency matrix.
Each node represents a location, and edges represent roads with distances.
A shortest path algorithm similar to Dijkstra is implemented.
Cross-zone travel adds an additional cost.

## 2. Trip State Machine Design
Each trip follows a strict lifecycle:
REQUESTED → ASSIGNED → ONGOING → COMPLETED
Trips can be cancelled from REQUESTED, ASSIGNED, or ONGOING states.
Invalid state transitions are prevented in code.

## 3. Rollback Strategy
A rollback manager maintains a history of trips using an array.
Rollback operations restore driver availability and trip state.
The system supports rollback of the last trip or last k trips.

## 4. Time and Space Complexity
Shortest path algorithm runs in O(V²) time.
Rollback operations take O(k) time.
The adjacency matrix uses O(V²) space.
