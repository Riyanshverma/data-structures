
// A priority queue is an abstract data type that stores elements, each associated with a priority,
// and allows for efficient retrieval of the element with the highest (or lowest) priority. The key 
// characteristic of a priority queue is that elements are removed from the queue based on their priority 
// rather than their order of arrival. The element with the highest priority is dequeued first.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct PriorityQueue{
    int size;
    int *process;
    int *priority;
    int front,rear;
};
void initialize(struct PriorityQueue * pq){
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    pq->size = size;
    pq->process = (int *)malloc(sizeof(int)*size);
    pq->priority = (int *)malloc(sizeof(int)*size);
    pq->front = pq->rear = -1;
}
int isempty(struct PriorityQueue * pq){
    if(pq->rear== pq->front){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct PriorityQueue *pq){
    if(pq->rear == (pq->size - 1)){
        return 1;
    }else{
        return 0;
    }
}

void insertbypriority(struct PriorityQueue*pq,int value,int priority){
        int i = pq->rear;
        while(i >=pq->front && priority >= pq->priority[i]){
            pq->process[i+1] = pq->process[i];
            pq->priority[i+1] = pq->priority[i];
            i--;
        }
        pq->process[i+1] = value;
        pq->priority[i+1] = priority;
}

void enqueue(struct PriorityQueue* pq){
    if(isfull(pq)){
        printf("Queue is Full. Cannot insert......\n");
    }else{
        pq->rear++;
        int value;
        printf("Enter the value of the element: ");
        scanf("%d",&value);
        int priority;
        printf("Enter the priority of %d: ",value);
        scanf("%d",&priority);
        insertbypriority(pq,value,priority);
    }
}

void dequeue(struct PriorityQueue * pq){
    if(isempty(pq)){
        printf("Queue is Empty. Cannot delete......\n");
    }else{
        pq->front ++;
    }
}

void display(struct PriorityQueue *pq){
    if (isempty(pq)) {
        printf("Queue is Empty\n");
    } else {
        printf("Priority Queue elements: ");
        for (int i = pq->front; i <= pq->rear; i++) {
            printf("(%d, %d) ", pq->process[i], pq->priority[i]);
        }
        printf("\n");
    }
}

int main(){
    struct PriorityQueue pq;
    initialize(&pq);
    int choice;
    do{
        printf("1)Insert \n2) Delete\n3)Display\n4)Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(&pq);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting Program....\n");
                break;
            default:
                printf("Invalid Choice. Enter a correct choice......\n");
        }
    }while(choice != 4);
    return 0;
}
