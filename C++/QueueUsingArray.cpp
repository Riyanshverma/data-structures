#include<iostream>
using namespace std;
class Queue{
    int currentsize,maxsize,front,rear,*arr;
    public:
    Queue(int size=100){
        currentsize=0;
        maxsize=size;
        front=0;
        rear=-1;
        arr = new int [size];
    }
    bool isFull(){
        return currentsize==maxsize;
    }
    bool isEmpty(){
        return currentsize==0;
    }
    void push(int data){
        if(!isFull()){
            arr[++rear]=data;
            currentsize++;
        }
        else{
            cout<<"Queue is Full";
        }
    }
    void pop(){
        if(!isEmpty()){
            front++;
            currentsize--;
        }
    }
    int getFront(){
        return arr[front];
    }
};