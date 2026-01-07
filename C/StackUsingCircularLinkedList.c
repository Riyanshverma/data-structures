#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;
};

struct Stack{
    struct Node* last;
};

void initialize( struct Stack *p){
    p->last=NULL;
}
void push(struct Stack *p, int x){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp ->data = x; 
    temp ->next = NULL;
    if(p->last == NULL){
        p->last =temp;
        temp->next = temp;
    }
    else{
        temp->next = p->last->next;
        p->last ->next = temp;
    }
}
int pop(struct Stack *p){
    struct Node *temp;
    int x;
    if(p->last == NULL){
        printf("Can't pop");
        return -1;
    }
    else{
        x = p->last->next->data;
    }
    if(p->last == p->last->next){
        free(p->last);
        p->last = NULL;
    }
    else{
        temp = p->last->next;
        p->last->next = temp->next;
        free(temp);
    }
    return x;
}
int main(){
    struct Stack s;
    initialize(&s);
    push(&s,5);
    printf("%d",pop(&s));
}