# Graph Vertex Coloring - Greedy and Backtracking Solutions

This repository contains C code implementations for solving the graph vertex coloring problem using two different approaches:

1.  **Greedy Algorithm:** A simple and fast heuristic approach.
2.  **Naive Backtracking:** A brute-force, exhaustive search method.

## Problem Description

The graph vertex coloring problem aims to assign colors to the vertices of a graph such that no two adjacent vertices share the same color. The goal is often to minimize the number of colors used.

## Files

* `greedy_algorithm.c`: Contains the implementation of the greedy graph coloring algorithm.
* `naive-method_backtracking.c`: Contains the implementation of the naive backtracking graph coloring algorithm.
  * `graph_utils.h`: Header file containing graph data structure definitions and utility functions.
* `main.c`: Main program to demonstrate the usage of both algorithms.
  * `input.txt`: Example graph input file.
* `README.md`: This file.

## Graph Input Format (input.txt)

The `input.txt` file should represent the graph in the following format:


<number_of_vertices>
<adjacency_matrix_row_1>
<adjacency_matrix_row_2>
...
<adjacency_matrix_row_<number_of_vertices>>


* The first line specifies the number of vertices in the graph.
* The subsequent lines represent the adjacency matrix, where each line corresponds to a row of the matrix.
* The adjacency matrix uses 1 to indicate an edge between vertices and 0 to indicate no edge.

Example for a graph with 4 vertices and 4 edges:


4
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0


## Compilation

To compile the code, use a C compiler (e.g., GCC):

```bash
gcc main.c greedy_coloring.c backtracking_coloring.c -o graph_coloring

Execution
To run the compiled program:

./graph_coloring input.txt

The program will output the color assignments for each vertex using both the greedy and backtracking algorithms, as well as the number of colors used by each method.

Algorithm Details
Greedy Algorithm
The greedy algorithm works as follows:

It iterates through the vertices of the graph in a sequential manner.

For each vertex, it tries to assign the smallest possible color that has not been used by any of its neighbors.

It keeps track of the colors used by neighboring vertices to determine the available colors.

The algorithm is simple and fast, but it does not guarantee an optimal solution (i.e., it may use more colors than necessary).

Key Characteristics:

Time Complexity: O(V^2), where V is the number of vertices.

Space Complexity: O(V), to store the color assignment for each vertex.

Optimality: Not guaranteed to be optimal.

Backtracking Algorithm
The backtracking algorithm is a brute-force approach that explores all possible color assignments to find a valid solution.  It works as follows:

It starts by assigning a color to the first vertex.

It then recursively tries to assign colors to the remaining vertices, one by one.

Before assigning a color to a vertex, it checks if that color is safe to use (i.e., if it is not used by any of its neighbors).

If a color is safe, it assigns the color and moves on to the next vertex.

If no safe color can be found, it backtracks to the previous vertex and tries a different color.

The algorithm continues until a valid color assignment is found for all vertices, or all possibilities have been exhausted.

This implementation uses a naive approach, trying all possible combinations, and thus can be very inefficient.

Key Characteristics:

Time Complexity: O(k^V), where k is the number of possible colors and V is the number of vertices.  This is exponential.

Space Complexity: O(V), to store the color assignment for each vertex and the recursion stack.

Optimality: Guarantees an optimal solution (i.e., it will find the minimum number of colors needed).

Usage Example
Create an input.txt file with the graph representation.

Compile the code using the gcc command.

Run the executable with the input file as an argument.

Observe the color assignments for each vertex, and the number of colors used by each algorithm.

Notes
The backtracking algorithm's runtime can grow exponentially with the number of vertices, making it impractical for large graphs.

The greedy algorithm is very fast, but does not guarantee optimal solutions.

The code uses basic C structures and functions and can be improved with better memory management and error handling.

A voice record in arabic is attched to explain both of algorithms.
