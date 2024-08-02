#include <iostream> // Input and output stream library for user interaction
#include <vector>   // Container library for dynamic arrays (vectors)
#include <limits>   // Library providing constants for numeric limits

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity as maximum integer value

// Structure to represent an edge between vertices
struct Edge {
    int source, destination, weight;
};

// Function to relax an edge and update the distance if a shorter path is found
void relax(Edge edge, vector<int> &distance) {
    // Check if the source vertex has a valid distance (not infinite)
    if (distance[edge.source] != INF) {
        // Calculate the potential distance to the destination through this edge
        int dist = distance[edge.source] + edge.weight;

        // If the potential distance is shorter, update the distance to the destination vertex
        if (dist < distance[edge.destination]) {
            distance[edge.destination] = dist;
        }
    }
}

// Bellman-Ford algorithm implementation:
void bellmanFord(vector<Edge> &edges, int V, int src) {
    vector<int> distance(V, INF);   // Initialize distances to infinity
    distance[src] = 0;  // Distance from source to itself is 0

    // Relax edges V-1 times to find the shortest paths
    for (int i = 0; i < V - 1; ++i) {
        // Iterate through all edges and relax each one
        for (const Edge &edge: edges) {
            relax(edge, distance);
        }
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (const Edge &edge: edges) {
        // If a shorter path is still possible, a negative cycle exists
        if (distance[edge.source] + edge.weight < distance[edge.destination]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\nGraph contains a negative weight cycle!";
        return;
    }

    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To vertex " << i + 1 << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;

    // Create a vector to store edges
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cout << "\nEnter edge " << i + 1 << " (source, destination, weight):\n";
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int src;
    cout << "\nEnter the source vertex: ";
    cin >> src;

    bellmanFord(edges, V, src);

    return 0;
}