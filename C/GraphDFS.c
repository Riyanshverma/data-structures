#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int numVertices;
    int* visited;
    int* adjacencyList;
} graph;

graph* createGraph(int numVertices) {
    graph* graph1 = (graph*)malloc(sizeof(graph));
    graph1->numVertices = numVertices;
    graph1->visited = (int*)calloc(numVertices, sizeof(int));
    graph1->adjacencyList = (int*)calloc(numVertices * numVertices, sizeof(int));
    return graph1;
}

void addEdge(graph* graph, int src, int dest) {
    graph->adjacencyList[(src * graph->numVertices) + dest] = 1;
    graph->adjacencyList[(dest * graph->numVertices) + src] = 1;
}

void DFS(graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyList[(startVertex * graph->numVertices) + i] == 1 && graph->visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

int main() {
    int numVertices = 5;
    graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("DFS traversal: ");
    DFS(graph, 0);
    free(graph);

    return 0;
}