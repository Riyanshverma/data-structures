#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} queue;

queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(queue* q, int value) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    if (q->front == -1) {
        q->front = q->rear;
    }
}

int dequeue(queue* q) {
    if (q->front == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

bool isQueueEmpty(queue* q) {
    return q->front == -1 && q->rear == -1;
}

typedef struct graph {
    int numVertices;
    int* visited;
    int* queue;
    int* adjacencyList;
} graph;

graph* createGraph(int numVertices) {
    graph* graph1 = (graph*)malloc(sizeof(graph));
    graph1->numVertices = numVertices;
    graph1->visited = (int*)calloc(numVertices, sizeof(int));
    graph1->queue = (int*)calloc(numVertices, sizeof(int));
    graph1->adjacencyList = (int*)calloc(numVertices * numVertices, sizeof(int));
    return graph1;
}

void addEdge(graph* graph, int src, int dest) {
    graph->adjacencyList[(src * graph->numVertices) + dest] = 1;
    graph->adjacencyList[(dest * graph->numVertices) + src] = 1;
}

void BFS(graph* graph, int startVertex) {
    queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyList[(currentVertex * graph->numVertices) + i] == 1 && graph->visited[i] == 0) {
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);
}

int main() {
    int numVertices = 5;
    graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("BFS traversal: ");
    BFS(graph, 0);
    free(graph);

    return 0;
}