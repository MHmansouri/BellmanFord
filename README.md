# Bellman-Ford Algorithm Project

## About the Project

This repository contains the implementation of the Bellman-Ford algorithm, developed as part of a university project. The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph, including graphs with negative weight edges.

### Features

- **Single Source Shortest Path:** Computes the shortest paths from a given source vertex to all other vertices.
- **Handles Negative Weights:** Processes graphs with negative weight edges.
- **Detects Negative Cycles:** Identifies and reports negative weight cycles in the graph.

### Implementation Details

The project is implemented in C++. The main components of the code include:

- **Edge Structure:** Represents an edge between vertices, including source, destination, and weight.
- **Relax Function:** Updates the distance if a shorter path is found through an edge.
- **Bellman-Ford Function:** Implements the Bellman-Ford algorithm, including relaxation of edges and cycle detection.

### Example Usage

1. **Input:**
    ```
    Enter the number of vertices: 5
    Enter the number of edges: 8
    Enter edge 1 (source, destination, weight): 0 1 6
    Enter edge 2 (source, destination, weight): 0 2 7
    Enter edge 3 (source, destination, weight): 1 2 8
    Enter edge 4 (source, destination, weight): 1 3 5
    Enter edge 5 (source, destination, weight): 1 4 -4
    Enter edge 6 (source, destination, weight): 2 3 -3
    Enter edge 7 (source, destination, weight): 2 4 9
    Enter edge 8 (source, destination, weight): 3 1 -2
    Enter the source vertex: 0
    ```

2. **Output:**
    ```
    Shortest distances from vertex 0:
    To vertex 0: 0
    To vertex 1: 2
    To vertex 2: 7
    To vertex 3: 4
    To vertex 4: -2
    ```

### Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please fork the repository and submit a pull request.

### License

This project is licensed under the MIT License.
