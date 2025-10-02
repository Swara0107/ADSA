#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX   // Define infinity as maximum integer value

// Function to find the vertex with the minimum key value 
// from the set of vertices not yet included in MST
int findMinKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        // If vertex v is not yet in MST and its key is smaller than the current minimum
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST and its total cost
void printMST(int parent[], int graph[20][20], int V) {
    int totalCost = 0;

    printf("\nEdge   Weight\n");
    for (int i = 1; i < V; i++) {
        // parent[i] - i is an edge in MST
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]]; // add weight to total cost
    }
    printf("Total cost of MST: %d\n", totalCost);
}

// Function that constructs MST using Prim’s algorithm
void primMST(int graph[20][20], int V) {
    int parent[20];   // Array to store MST (parent of each vertex)
    int key[20];      // Key values used to pick minimum weight edge
    bool mstSet[20];  // To represent set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;      // Initially all vertices are "unreachable"
        mstSet[i] = false; // None of the vertices are included in MST
        parent[i] = -1;    // Parent of each vertex is unknown at start
    }

    // Always include the first vertex in MST (start with vertex 0)
    key[0] = 0;  // Weight of first vertex = 0, so it is picked first

    // Construct MST with (V - 1) edges
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex u not yet in MST with the minimum key value
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true; // Include u in MST set

        // Update key value and parent of adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // If weight of edge u-v is smaller than the current key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;        // u becomes parent of v
                key[v] = graph[u][v]; // Update key value
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[20][20];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Input adjacency matrix
    printf("Enter adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0; // No self-loops
            }
        }
    }

    // Call Prim’s algorithm
    primMST(graph, V);

    return 0;
}
