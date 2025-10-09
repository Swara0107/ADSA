#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int graph[MAX][MAX];
int path[MAX];
bool visited[MAX];
int n;
// Function to check if vertex v can be added to the Hamiltonian cycle
bool isSafe(int v, int pos) {
    // Check if there is an edge from the last vertex in path to v
    if (graph[path[pos - 1]][v] == 0)
        return false;
    // Check if vertex v has already been included
    if (visited[v])
        return false;
    return true;
}
// Utility function to solve Hamiltonian Cycle problem
bool hamCycleUtil(int pos) {
    // Base case: all vertices are in the path
    if (pos == n) {
        // Check if there is an edge from the last to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    // Try different vertices as next candidate
    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            visited[v] = true;
            // Recur to construct the rest of the path
            if (hamCycleUtil(pos + 1))
                return true;
            // Backtrack
            visited[v] = false;
            path[pos] = -1;
        }
    }
    return false;
}
// Function to find Hamiltonian Cycle
void hamiltonianCycle() {
    // Start at vertex 0
    for (int i = 0; i < n; i++) {
        path[i] = -1;
        visited[i] = false;
    }
    path[0] = 0;
    visited[0] = true;
    if (hamCycleUtil(1)) {
        printf("\nHamiltonian Cycle Found:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]); // return to start
    } else {
        printf("\nNo Hamiltonian Cycle found.\n");
    }
}
// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix of the graph (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCycle();
    return 0;
}
