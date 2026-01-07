#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data=val;
        this->next=NULL;
    }
};
class Queue{
    public:
    Node * front;
    Node * rear;
    Queue(){
        front=rear=NULL;
    }
    bool empty(){
        return rear==NULL;
    }
    void push(int val){
        Node * temp = new Node(val);
        if(temp==NULL){
            cout<<"Memory Overflow";
            return ;
        }
        rear->next=temp;
        rear=temp;
    }
    void pop(){
        if(!empty()){
            Node * temp = front->next;
            front->next=temp->next;
            delete temp;
        }
        else{
            cout<<"Queue Empty";
        }
    }
    int getFront(){
        if(empty()){
            cout<<"Queue Empty\n";
            return -1;
        }
        return front->next->data;
    }
};