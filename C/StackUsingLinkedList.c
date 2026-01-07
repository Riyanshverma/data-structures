#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Stack{
    struct Node * top;
};
void initialise(struct Stack *s){
    s->top=NULL;
}
int empty(struct Stack *s){
    return s->top==NULL;
}
void push(struct Stack *s, int val){
    struct Node * dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->data=val;
    dummy->next=s->top;
    s->top=dummy;
}
void pop(struct Stack *s){
    if(empty(s)){
        printf("Stack Empty\n");
        return ;
    }
    struct Node * temp = s->top;
    s->top=s->top->next;
    free(temp);
}
int getTop(struct Stack *s){
    if(empty(s)){
        printf("Stack Empty\n");
        return -1; 
    }
    return s->top->data;
}
int main(){
    struct Stack s;
    initialise(&s);
    // pop(&s);
    for(int i=1;i<=5;i++){
        push(&s,i);
    }
    while(!empty(&s)){
        printf("%d ",getTop(&s));
        pop(&s);
    }
}