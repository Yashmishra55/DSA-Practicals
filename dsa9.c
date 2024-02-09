#include <stdio.h>
#include <stdlib.h>

// Structure for representing a node in adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure for representing adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for representing the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to create a new node in adjacency list
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function for Depth-First Search (DFS)
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->array[v].head;
    while (temp != NULL) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function for Breadth-First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    struct Node* queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    queue[rear++] = graph->array[startVertex].head;

    while (front < rear) {
        struct Node* temp = queue[front++];
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                printf("%d ", adjVertex);
                visited[adjVertex] = 1;
                queue[rear++] = graph->array[adjVertex].head;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V = 6; // Number of vertices in the graph
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("Depth-First Search (DFS) traversal starting from vertex 0: ");
    int visitedDFS[V];
    for (int i = 0; i < V; ++i) {
        visitedDFS[i] = 0;
    }
    DFS(graph, 0, visitedDFS);
    printf("\n");

    printf("Breadth-First Search (BFS) traversal starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}
