#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

// A utility function to print a Hamiltonian Cycle
void printSolution(int path[])
{
    printf("Hamiltonian Cycle Found: ");
    for (int i = 0; i < V; i++)
        printf(" %d", path[i]);
    printf(" %d", path[0]);
    printf("\n");
}

// A utility function to check if the vertex has been visited
bool isVisited(int visited[], int vertex)
{
    return (visited[vertex] == 1);
}

// A utility function to mark the vertex as visited
void markVisited(int visited[], int vertex)
{
    visited[vertex] = 1;
}

// A utility function to mark the vertex as unvisited
void markUnvisited(int visited[], int vertex)
{
    visited[vertex] = 0;
}

// A utility function to check if the edge exists between two vertices
bool isEdge(int graph[V][V], int vertex1, int vertex2)
{
    return (graph[vertex1][vertex2] == 1);
}

// A utility function to find a Hamiltonian Cycle
bool hamCycleUtil(int graph[V][V], int path[], int pos, int visited[])
{
    // If the path has V vertices, it's a Hamiltonian Cycle
    if (pos == V)
    {
        // Check if the last vertex is connected to the first vertex
        if (isEdge(graph, path[pos-1], path[0]))
            return true;
        else
            return false;
    }

    // Try all vertices as a next candidate in Hamiltonian Cycle
    for (int v = 0; v < V; v++)
    {
        // Check if the vertex is not visited and there is an edge between the current vertex and the next vertex
        if (isVisited(visited, v) == false && isEdge(graph, path[pos-1], v))
        {
            // Mark the vertex as visited
            markVisited(visited, v);

            // Add the vertex to the path
            path[pos] = v;

            // Recursively check if the path can be extended to a Hamiltonian Cycle
            if (hamCycleUtil(graph, path, pos+1, visited) == true)
                return true;

            // If the path cannot be extended to a Hamiltonian Cycle, backtrack and remove the vertex from the path
            markUnvisited(visited, v);
        }
    }

    return false;
}

// The main function that returns true if there is a Hamiltonian Cycle in the given graph
bool hamCycle(int graph[V][V])
{
    int *path = (int *)malloc(V * sizeof(int));
    int *visited = (int *)malloc(V * sizeof(int));

    // Initialize the path and visited arrays
    for (int i = 0; i < V; i++)
    {
        path[i] = -1;
        visited[i] = 0;
    }

    // Try each vertex as a starting point for the Hamiltonian Cycle
    for (int v = 0; v < V; v++)
    {
        // Mark the vertex as visited
        markVisited(visited, v);

        // Add the vertex to the path
        path[0] = v;

        // Recursively check if the path can be extended to a Hamiltonian Cycle
        if (hamCycleUtil(graph, path, 1, visited) == true)
        {
            printSolution(path);
            return true;
        }

        // If the path cannot be extended to a Hamiltonian Cycle, backtrack and remove the vertex from the path
        markUnvisited(visited, v);
    }

    return false;
}

// Driver program to test above function
int main()
{
    /* Let us create the following graph
     * (0)--(1)--(2)
     *  |   |    |
     *  |   |    |
     *  |   |    |
     *  (3)--(4)--(5)
     */
    int graph[V][V] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1},
                       {0, 1, 0, 0, 1},
                       {1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 0},
                       {0, 0, 1, 1, 0}};

    if (hamCycle(graph) == false)
        printf("There is no Hamiltonian Cycle in the given graph\n");

    return 0;
}