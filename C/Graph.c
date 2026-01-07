#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void insertNode(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void deleteNode(struct Graph* graph, int src) {
    struct Node* temp = graph->adjList[src];
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    graph->adjList[src] = NULL;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertice %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    insertNode(graph, 0, 1);
    insertNode(graph, 0, 2);
    insertNode(graph, 0, 4);
    insertNode(graph, 1, 3);
    insertNode(graph, 3, 5);
    insertNode(graph, 1, 5);
    printf("Adjacency list representation of the graph: \n");
    printGraph(graph);
    deleteNode(graph, 0);
    printf("After deleting node 0: \n");
    printGraph(graph);
    return 0;
}