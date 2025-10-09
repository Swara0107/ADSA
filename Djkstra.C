#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define INF INT_MAX
#define MAX 20
// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];       // Array to store shortest distance from src
    bool visited[MAX];   // visited[i] = true if vertex i is included in shortest path tree
    // Initialize all distances as INF and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance from source to itself is always 0
    dist[src] = 0;
    //Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true; // Mark the chosen vertex as visited
        // Update dist[v] for all adjacent vertices of u
        for (int v = 0; v < n; v++) 
{
               if (!visited[v] && graph[u][v] && dist[u] != INF 
               && dist[u] + graph[u][v] < dist[v]) {
               dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print the shortest distances from src
    printf("Vertex   Distance from Source %d\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}
int main() {
    int n, src;
    int graph[MAX][MAX];
    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    // Input adjacency matrix
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // Input source vertex
    printf("Enter source vertex: ");
    scanf("%d", &src);
    // Run Dijkstra's Algorithm
    dijkstra(graph, src, n);
    return 0;
}
