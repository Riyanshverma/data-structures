#include<stdio.h>

// Stack Implementation:
struct Stack{
    int top;
    int arr[100];
};

void initialize(struct Stack *s){
    s->top=-1;
}

int isFull(struct Stack *s){
    if(s->top==99){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack *s, int temp){
    if(!isFull(s)){
        s->arr[++s->top]=temp;
    }
    else{
        printf("Stack Overflow.");
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

int top(struct Stack *s){
    return s->arr[s->top];
}

int size(struct Stack *s){
    return s->top+1;
}

void popAtBottom(struct Stack *s){
    if(s->top==-1){
        return;
    }
    if(s->top==1){
        int flag=top(s);
        pop(s);
        pop(s);
        push(s,flag);
        return ;
    }
    else{
        int temp=top(s);
        pop(s);
        popAtBottom(s);
        push(s,temp);
    }
}

struct Queue{
    struct Stack s;
};



int main(){
    struct Stack s;
    initialize(&s);
    for(int i=0;i<7;i++){
        push(&s,i+1);
    }
    printf("%d\n",size(&s));
    popAtBottom(&s);
    printf("%d\n",size(&s));
    while (!isEmpty(&s))
    {
        printf("%d ",top(&s));
        pop(&s);
    }


    struct Queue q;
    return 0;
}