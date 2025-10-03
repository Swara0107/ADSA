#include <stdio.h>

#define INF 99999  // A large value representing "infinity"
#define V 4        // Number of vertices in the graph

// Function to print the shortest distance matrix
void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");  // If distance is INF, print "INF"
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall Algorithm implementation
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Adding all vertices one by one as intermediate vertices
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist);
}

// Main function
int main() {
    /* Example graph represented as adjacency matrix.
       INF means there is no direct edge between those vertices. */
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
