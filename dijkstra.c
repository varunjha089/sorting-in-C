#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_NODES 6

// Function to find the shortest path from source to all other vertices using Dijkstra's algorithm
void dijkstra(int graph[NUM_NODES][NUM_NODES], int src) {
    int dist[NUM_NODES]; // array to store the shortest distance from the source to each vertex
    int visited[NUM_NODES]; // array to keep track of visited vertices

    // initialize the arrays
    for (int i = 0; i < NUM_NODES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // set the distance of the source vertex to 0
    dist[src] = 0;

    // loop through all vertices
    for (int i = 0; i < NUM_NODES - 1; i++) {
        // find the vertex with the smallest distance that has not been visited
        int min_dist = INT_MAX, min_index;
        for (int j = 0; j < NUM_NODES; j++) {
            if (visited[j] == 0 && dist[j] <= min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        // mark the vertex as visited
        visited[min_index] = 1;

        // update the distance of the adjacent vertices of the current vertex
        for (int j = 0; j < NUM_NODES; j++) {
            if (graph[min_index][j] && visited[j] == 0 && dist[min_index] != INT_MAX && dist[min_index] + graph[min_index][j] < dist[j]) {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }

    // print the shortest distance from the source to each vertex
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < NUM_NODES; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[NUM_NODES][NUM_NODES] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
