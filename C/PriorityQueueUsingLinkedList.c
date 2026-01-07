#include <stdio.h>
#include <stdlib.h>

struct node{
    int process;
    int priority;
    struct node * next;
};

struct priorityqueue{
    struct node *front;
};

int isempty(struct priorityqueue * pq){
    if(pq->front == NULL){
        return 1;
    }else{
        return 0;
    }
}

void initialize(struct priorityqueue * pq){
    pq->front = NULL;
}

struct node * createnode(int process, int priority){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->process = process;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

struct priorityqueue* createpriorityqueue(){
    struct priorityqueue* newpq = (struct priorityqueue*)malloc(sizeof(struct priorityqueue));
    initialize(newpq);
    return newpq;
}

void enqueue(struct priorityqueue * pq){
    int process,priority;
    printf("Enter the process: ");
    scanf("%d",&process);
    printf("Enter the priority: ");
    scanf("%d",&priority);
    struct node * new = createnode(process,priority);

    if(isempty(pq) || priority > pq->front->priority){
            new->next = pq->front;
            pq->front = new;
    }else{
        struct node * q = pq->front;
        while(q->next != NULL && q->next->priority > priority){
            q = q->next;
        }
        new->next = q->next;
        q->next = new;
    }
}

void dequeue(struct priorityqueue * pq){
    if(isempty(pq)){
        printf("Queue is Empty...\n");
    }else{
        struct node * temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
        printf("Node Deleted.....\n");
    }
}

void display(struct priorityqueue * pq){
    struct node * x = pq->front;
    while(x != NULL){
        printf("[%d,%d]-->",x->process,x->priority);
        x = x->next;
    }
    printf("\n");
}

int main(){
    struct priorityqueue * pq = createpriorityqueue();
    int choice;
    do{
        printf("1) Insert\n2) Delete\n3) Display\n4) Exit\n");
        printf("Enter a choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(pq);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("Exiting....\n");
                break;
        }
    }while(choice != 4);
    return 0;
}
