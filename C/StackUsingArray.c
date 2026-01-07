#include<stdio.h>
#define max 100
struct Stack{
    int top;
    int arr[max];
};
void initialise(struct Stack *s){
    s->top=-1;
}
int isEmpty(struct Stack *s){
    return s->top==-1;
}
int isFull(struct Stack *s){
    return s->top==max-1;
}
void push(struct Stack *s, int data){
    if(!isFull(s)){
        s->arr[++s->top]=data;
    }
    else{
        printf("Stack Overflow");
    }
}
void pop(struct Stack *s){
    if(!isEmpty(s)){
        s->top--;
    }
    else{
        printf("Stack Underflow");
    }
}
int getData(struct Stack *s){
    return s->arr[s->top];
}
int main(){
    struct Stack s;
    initialise(&s);
    printf("%d\n",isEmpty(&s));
    push(&s,5);
    printf("%d",getData(&s));
    pop(&s);
    printf("%d",top(&s));

}