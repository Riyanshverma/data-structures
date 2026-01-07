#include<stdio.h>
struct Queue
{
    int currentsize,maxsize,front,rear,arr[100];
};

void initialize(struct Queue *q){
    q->currentsize=0;
    q->maxsize=100;
    q->front=0;
    q->rear=-1;
}
int full(struct Queue *q){
    return q->currentsize==q->maxsize;
}
int empty(struct Queue *q){
    return q->currentsize==0;
}
int getFront(struct Queue *q){
    return q->arr[q->front];
}
void push(struct Queue *q, int temp){
    if(!full(q)){
        q->arr[++q->rear]=temp;
        q->currentsize++;
    }
    else{
        printf("Queue Full");
    }
}
void pop(struct Queue *q){
    if(!empty(q)){
        q->front++;
        q->currentsize--;
    }
    else{
        printf("Queue Empty");
    }
}
int main(){
    struct Queue q;
    initialize(&q);
    for(int i=0;i<100;i++){
        push(&q, i+1);
    }
    while (!empty(&q))
    {
        /* code */
        printf("%d ",getFront(&q));
        pop(&q);
    }
    
}