#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

int Queue[max];
int rear = -1, front = -1;

struct Graph {
    int vertices;
    int edges;
    int **Adj;      // Adjacency Matrix
    char **nodeValues; // Array to store node values
};

struct Graph* initGraph();
void addNode(struct Graph *G, const char *nodeName);
void deleteNode(struct Graph *G, const char *nodeName);
void addEdge(struct Graph *G, const char *from, const char *to);
void deleteEdge(struct Graph *G, const char *from, const char *to);
void DFSTraversal(struct Graph *G, int *visited);
void DFS(struct Graph *G, int u, int *visited);
void BFSTraversal(struct Graph *G, int *visited);
void BFS(struct Graph *G, int u, int *visited);
void Enqueue(int root);
int Dequeue();
int isEmptyQueue();
int isInQueue(int key);

int main() {
    struct Graph *G = initGraph();
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Add Edge\n");
        printf("4. Delete Edge\n");
        printf("5. BFS Traversal\n");
        printf("6. DFS Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) break;

        char node1[20], node2[20];
        switch (choice) {
            case 1:
                printf("Enter node value: ");
                scanf("%s", node1);
                addNode(G, node1);
                break;
            case 2:
                printf("Enter node to delete: ");
                scanf("%s", node1);
                deleteNode(G, node1);
                break;
            case 3:
                printf("Enter edge (from to): ");
                scanf("%s %s", node1, node2);
                addEdge(G, node1, node2);
                break;
            case 4:
                printf("Enter edge to delete (from to): ");
                scanf("%s %s", node1, node2);
                deleteEdge(G, node1, node2);
                break;
            case 5: {
                // Dynamically allocate visited array based on the number of vertices
                int *visited = (int *)calloc(G->vertices, sizeof(int));

                BFSTraversal(G, visited);
                free(visited); // Free visited array after traversal
                break;
            }
            case 6: {
                // Dynamically allocate visited array based on the number of vertices
                int *visited = (int *)calloc(G->vertices, sizeof(int));

                DFSTraversal(G, visited);
                free(visited); // Free visited array after traversal
                break;
            }
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Initialize graph with 0 vertices and 0 edges
struct Graph* initGraph() {
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph)); // Memory Allocation for the graph node

    if (!G) {
        printf("\nMemory Error");
        return NULL;
    }

    G->vertices = 0;
    G->edges = 0;

    // Memory Allocation for Adjacency Matrix (Initially 0x0)
    G->Adj = NULL;

    // Memory Allocation for Node Values (Initially NULL)
    G->nodeValues = NULL;

    return G;
}

// Add Node Dynamically to the Graph
// realloc() not working correctly if we are using directly on G->Adj, so using new variables and assigning those to original
void addNode(struct Graph *G, const char *nodeName) {
    if (G->vertices >= max) {
        printf("Cannot add more nodes, max limit reached.\n");
        return;
    }

    G->vertices++;

    // Resize adjacency matrix to accommodate the new node
    int **newAdj = realloc(G->Adj, G->vertices * sizeof(int *));
    if (newAdj == NULL) {
        printf("Memory allocation failed for adjacency matrix rows!\n");
        exit(1);
    }
    G->Adj = newAdj;

    // Resize each row of the adjacency matrix
    for (int i = 0; i < G->vertices; i++) {
        int *newRow = realloc(G->Adj[i], G->vertices * sizeof(int));
        if (newRow == NULL) {
            printf("Memory allocation failed for adjacency matrix columns!\n");
            exit(1);
        }
        G->Adj[i] = newRow;
    }

    // Initialize the new row and column to 0
    for (int i = 0; i < G->vertices; i++) {
        G->Adj[G->vertices - 1][i] = 0; // Initialize the new row
        G->Adj[i][G->vertices - 1] = 0; // Initialize the new column
    }

    // Resize node values array to accommodate the new node
    char **newNodeValues = realloc(G->nodeValues, G->vertices * sizeof(char *));
    if (newNodeValues == NULL) {
        printf("Memory allocation failed for node values array!\n");
        exit(1);
    }
    G->nodeValues = newNodeValues;

    // Allocate memory for the new node value
    G->nodeValues[G->vertices - 1] = malloc(20 * sizeof(char));
    if (G->nodeValues[G->vertices - 1] == NULL) {
        printf("Memory allocation failed for node value!\n");
        exit(1);
    }

    // Copy the node name into the new node value
    strcpy(G->nodeValues[G->vertices - 1], nodeName);

    printf("Node %s added.\n", nodeName);
    printf("Current number of vertices: %d\n", G->vertices); // Debugging line
}

// Delete Node from the Graph
void deleteNode(struct Graph *G, const char *nodeName) {
    int index = -1;
    for (int i = 0; i < G->vertices; i++) {
        if (strcmp(G->nodeValues[i], nodeName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Node not found.\n");
        return;
    }

    // Remove the row and column in the adjacency matrix
    for (int i = index; i < G->vertices - 1; i++) {
        for (int j = 0; j < G->vertices; j++) {
            G->Adj[i][j] = G->Adj[i + 1][j];
        }
    }
    for (int j = index; j < G->vertices - 1; j++) {
        for (int i = 0; i < G->vertices; i++) {
            G->Adj[i][j] = G->Adj[i][j + 1];
        }
    }

    free(G->nodeValues[index]);
    for (int i = index; i < G->vertices - 1; i++) {
        G->nodeValues[i] = G->nodeValues[i + 1];
    }

    G->vertices--;
    printf("Node %s deleted.\n", nodeName);
}

// Add Edge between two nodes
void addEdge(struct Graph *G, const char *from, const char *to) {
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < G->vertices; i++) {
        if (strcmp(G->nodeValues[i], from) == 0) fromIndex = i;
        if (strcmp(G->nodeValues[i], to) == 0) toIndex = i;
    }

    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid node values.\n");
        return;
    }

    G->Adj[fromIndex][toIndex] = G->Adj[toIndex][fromIndex] = 1;
    printf("Edge added between %s and %s.\n", from, to);
}

// Delete Edge between two nodes
void deleteEdge(struct Graph *G, const char *from, const char *to) {
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < G->vertices; i++) {
        if (strcmp(G->nodeValues[i], from) == 0) fromIndex = i;
        if (strcmp(G->nodeValues[i], to) == 0) toIndex = i;
    }

    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid node values.\n");
        return;
    }

    G->Adj[fromIndex][toIndex] = G->Adj[toIndex][fromIndex] = 0;
    printf("Edge deleted between %s and %s.\n", from, to);
}

// DFS Algorithm to visit nodes
void DFS(struct Graph *G, int u, int *visited) {
    // Mark the current node as visited and print it
    visited[u] = 1;
    printf("%s ", G->nodeValues[u]);

    // Explore all unvisited adjacent vertices
    for (int v = 0; v < G->vertices; v++) {
        if (!visited[v] && G->Adj[u][v]) {
            DFS(G, v, visited);
        }
    }
}

// DFS Traversal of the Graph
void DFSTraversal(struct Graph *G, int *visited) {

    for (int i = 0; i < G->vertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS for each unvisited vertex
    for (int i = 0; i < G->vertices; i++) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }
}

// BFS Traversal of the Graph
void BFSTraversal(struct Graph *G, int *visited) {
    for (int i = 0; i < G->vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < G->vertices; i++) {
        if (!visited[i])
            BFS(G, i, visited);
    }
}

// BFS Algorithm to visit nodes
void BFS(struct Graph *G, int u, int *visited) {
    Enqueue(u);
    visited[u] = 1;

    while (!isEmptyQueue()) {
        int current = Dequeue();
        printf("%s ", G->nodeValues[current]);

        for (int i = 0; i < G->vertices; i++) {
            if (G->Adj[current][i] && !visited[i] && !isInQueue(i)) {
                visited[i] = 1;
                Enqueue(i);
            }
        }
    }
}

// Queue Functions
void Enqueue(int root) {
    if (rear == max - 1) return;

    if (front == -1) front = 0;
    Queue[++rear] = root;
}

int Dequeue() {
    if (isEmptyQueue()) return -1;

    int temp = Queue[front++];
    if (front > rear) front = rear = -1;

    return temp;
}

int isEmptyQueue() {
    return front == -1;
}

int isInQueue(int key) {
    for (int i = front; i <= rear; i++) {
        if (Queue[i] == key) return 1;
    }
    return 0;
}
