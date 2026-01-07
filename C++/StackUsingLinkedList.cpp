#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node(int data=0){
        val=data;
        this->next=NULL;
    }
};
class Stack{
    public:
    Node * top;
    Stack(){
        top=NULL;
    }
    bool empty(){
        return top==NULL;
    }
    void push(int data){
        Node * temp = new Node(data);
        if(temp==NULL){
            std::cout<<"Memory Overflow";
            return;
        }
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(!empty()){
            Node * temp = top;
            top=top->next;
            free(temp);
        }
        else{
            std::cout<<"Stack Empty";
        }
    }
    int getTop(){
        if(empty()){
            std::cout<<"Stack Empty\n";
            return -1;
        }
        return top->val;
    }
};
int main(){
    Stack s;
    // std::cout<<s.getTop();
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
}