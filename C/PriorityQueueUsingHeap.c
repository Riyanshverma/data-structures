#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int priority;
};

struct PriorityQueue {
    struct Task *heap;
    int capacity;
    int size;
};

void enqueue(struct PriorityQueue *pq, struct Task task);
void heapifyUp(struct PriorityQueue *pq, int index);
void dequeue(struct PriorityQueue *pq);
void heapifyDown(struct PriorityQueue *pq, int index);

int main() {
    struct PriorityQueue pq;
    pq.capacity = 100;
    pq.heap = (struct Task *)malloc(pq.capacity * sizeof(struct Task));
    pq.size = 0;

    int choice;

    do {
        printf("1- Enqueue a task--\n");
        printf("2- Dequeue a task-\n");
        printf("3- exit\n");
        printf("enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1: {
                struct Task newTask;
                printf("Enter task ID- ");
                scanf(" %d", &newTask.id);
                printf("Enter priority- ");
                scanf(" %d", &newTask.priority);
                enqueue(&pq, newTask);
                break;
            }
            case 2:
                dequeue(&pq);
                break;
            case 3:
                printf("exiting  program.\n");
                break;
            default:
                printf("invalid choice\n");
        }
    } while (choice != 3);

    free(pq.heap);
    return 0;
}

void swap(struct Task *a, struct Task *b) {
    struct Task temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(struct PriorityQueue *pq, struct Task task) {
    if (pq->size < pq->capacity) {
        pq->heap[pq->size] = task;
        heapifyUp(pq, pq->size);
        pq->size++;
        printf("enqueued successfully.\n");
    } else {
        printf("priority queue is full.\n");
    }
}

void heapifyUp(struct PriorityQueue *pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->heap[index].priority > pq->heap[parent].priority) {
            swap(&pq->heap[index], &pq->heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void dequeue(struct PriorityQueue *pq) {
    if (pq->size > 0) {
        printf("Task id %d with priority %d dequeued.\n", pq->heap[0].id, pq->heap[0].priority);
        pq->heap[0] = pq->heap[pq->size - 1];
        pq->size--;
        heapifyDown(pq, 0);
    } else {
        printf("Priority queue is empty.\n");
    }
}

void heapifyDown(struct PriorityQueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->heap[leftChild].priority > pq->heap[largest].priority) {
        largest = leftChild;
    }

    if (rightChild < pq->size && pq->heap[rightChild].priority > pq->heap[largest].priority) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}