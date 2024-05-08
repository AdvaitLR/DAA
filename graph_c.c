#include <stdio.h>

#define V 4

void printSolution(int color[]) {
    printf("Solution:\n");
    for (int i = 0; i < V; i++)
        printf("V%d -> %d\n", i + 1, color[i]);
}

int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < v; i++)
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    return 1;
}

void graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        printSolution(color);
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            graphColoringUtil(graph, m, color, v + 1);
        }
    }

    color[v] = 0; // If no color is available then backtrack
}

void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    graphColoringUtil(graph, m, color, 0);
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                      {1, 0, 1, 0},
                      {1, 1, 0, 1},
                      {1, 0, 1, 0}};

    graphColoring(graph, 3);

    return 0;
}