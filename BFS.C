#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;  // Queue for BFS
int visited[MAX];                        // Visited array

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1) {
        return -1;  // Queue empty
    }
    int vertex = queue[front];
    if (front >= rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return vertex;
}

// Function to perform BFS on the graph
void BFS(int graph[MAX][MAX], int startVertex, int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;  // Initialize all vertices as unvisited
    }

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");
    
    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal
    BFS(graph, startVertex, vertices);

    return 0;
}
