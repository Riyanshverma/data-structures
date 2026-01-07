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
        return front==NULL;
    }
    void push(Queue *q, int data){
        Node * temp = new Node(data);
        if(q->front=NULL){
            q->front=temp;
        }
        else{
            q->rear->next=temp;
        }
        q->rear=temp;
        q->rear->next=q->front;
    }
    int getFront(Queue *q){
        return q->front->data;
    }
    void pop(Queue *q){
        if(front==NULL){
            printf("Queue Empty");
            return ;
        }
        if(q->front==q->rear){
            delete q->front;
            q->front=q->rear=NULL;
        }
        else{
            Node * temp = front;
            q->front=q->front->next;
            q->rear->next=q->front;
            delete temp;
        }
    }
};