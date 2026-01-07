#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int currentsize, maxsize, front, rear, *arr;
};
void initialise(struct Queue *q, int size)
{
    q->currentsize = 0;
    q->maxsize = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = -1;
}
int full(struct Queue *q)
{
    return q->currentsize == q->maxsize;
}
int empty(struct Queue *q)
{
    return q->currentsize == 0;
}
int getFront(struct Queue *q)
{
    if (empty(q))
    {
        printf("Queue Empty\n");
        return -1;
    }
    return q->arr[q->front];
}
void push(struct Queue *q, int data)
{
    if (!full(q))
    {
        q->rear = (q->rear + 1) % q->maxsize;
        q->arr[q->rear] = data;
        q->currentsize++;
    }
    else
    {
        printf("Queue Full\n");
    }
}
void pop(struct Queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % q->maxsize;
        q->currentsize--;
    }
    else
    {
        printf("Queue Empty");
    }
}
int main()
{
    struct Queue q;
    initialise(&q, 5);
    for (int i = 1; i <= 5; i++)
    {
        push(&q, i);
    }
    printf("%d\n", getFront(&q));
    push(&q, 6);
    pop(&q);
    printf("%d\n", getFront(&q));
    push(&q, 6);
    while (!empty(&q))
    {
        printf("%d ", getFront(&q));
        pop(&q);
    }
}