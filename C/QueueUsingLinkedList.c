#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Queue{
    struct Node * front;
    struct Node * rear;
};
void initialise(struct Queue *q){
    q->front=q->rear=NULL;
}
int empty(struct Queue *q){
    return q->rear==NULL;
}
void push(struct Queue *q, int val){
    struct Node * dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->data=val;
    if(empty(q)){
        q->rear=dummy;
        q->front=dummy;
    }
    else{
        q->rear->next=dummy;
        q->rear=dummy;
    }
}
void pop(struct Queue *q){
    if(!empty(q)){
        struct Node * temp = q->front;
        q->front=q->front->next;
        free(temp);
    }
    else{
        printf("Queue Empty\n");
    }
}
int getFront(struct Queue *q){
    if(empty(q)){
        printf("Queue Empty\n");
        return -1;
    }
    return q->front->data;
}
int main(){
    struct Queue q;
    initialise(&q);
    pop(&q);
    for(int i=1;i<=5;i++){
        push(&q,i);
    }
    printf("%d ",getFront(&q));
    pop(&q);
    pop(&q);
    printf("%d ",getFront(&q));

}