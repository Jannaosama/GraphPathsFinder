Description:
GraphPathsFinder is a comprehensive program designed to analyze and traverse a network of cities represented as a weighted graph. The primary objective is to find all shortest paths in the graph and traverse it using Depth-First Search (DFS). 

Features:
1. Traverse the given graph using the DFS algorithm.
2. Shortest Paths Calculation from a given city to all other cities using Dijkstra’s algorithm.

Implementation Notes:
- The graph is implemented using an adjacency matrix stored in a 2-D array of size Vmax by Vmax (where Vmax = 50).
- Vertices are numbered (0, 1, …, V-1) and mapped to city names (A, B, C, …).
- Edges are represented by the `Edge` class and stored in a 1-D array of size Emax (maximum number of possible edges).
- The `Graphs` class encapsulates the graph structure and its operations. The skeletal implementation is provided and needs completion.

Usage:
- Complete the implementation of the `Graphs` class.
- Use the provided test files to validate your implementation.
- The program should output the DFS traversal order and the shortest paths from a specified city to all others.

This project provides a practical application of graph traversal and shortest path algorithms, leveraging data structures to solve real-world problems in a network of cities.
