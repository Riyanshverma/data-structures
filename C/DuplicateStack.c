#include <stdio.h>
struct Stack
{
    int top, arr[100];
};

void initialise(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == 99;
}

void push(struct Stack *s, int temp)
{
    if (!isFull(s))
    {
        s->arr[++(s->top)] = temp;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int top(struct Stack *s)
{
    return s->arr[s->top];
}

void pop(struct Stack *s)
{
    if (!isEmpty(s))
    {
        s->top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}
void duplicate(struct Stack *s1, struct Stack *s2)
{
    struct Stack s3;
    initialise(&s3);
    while (!isEmpty(s1))
    {
        push(s2, top(s1));
        push(&s3, top(s1));
        pop(s1);
    }
    while (!isEmpty(s2))
    {
        push(s1, top(s2));
        pop(s2);
    }
    while (!isEmpty(&s3))
    {
        push(s2, top(&s3));
        pop(&s3);
    }
}

void check(struct Stack *s1, struct Stack *s2)
{
    int flag = 1;
    while (!isEmpty(s1) && !isEmpty(s2))
    {
        if (top(s1) != top(s2))
        {
            flag = 0;
        }
        pop(s1);
        pop(s2);
    }
    if (flag)
    {
        printf("\nStack Duplicated");
    }
    else
    {
        printf("\nNot");
    }
}
int main()
{
    struct Stack s1, s2;
    initialise(&s1);
    initialise(&s2);
    for (int i = 0; i < 5; i++)
    {
        push(&s1, i + 1);
    }
    duplicate(&s1, &s2);
    printf("Stack 1:\n");
    while (!isEmpty(&s1))
    {
        printf("%d ", top(&s1));
        pop(&s1);
    }
    printf("\nStack 2:\n");
    while (!isEmpty(&s2))
    {
        printf("%d ", top(&s2));
        pop(&s2);
    }
    check(&s1, &s2);
    return 0;
}
