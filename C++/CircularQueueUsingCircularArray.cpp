#include<iostream>
using namespace std;
class Queue{
    int currentsize,maxsize,front,rear,*arr;
    public:
    Queue(int size=5){
        currentsize=0;
        maxsize=size;
        front=0;
        rear=-1;
        arr = new int [size];
    }
    bool full(){
        return currentsize==maxsize;
    }
    bool empty(){
        return currentsize==0;
    }
    void push(int data){
        if(!full()){
            rear=(rear+1)%maxsize;
            arr[rear]=data;
            currentsize++;
        }
        else{
            cout<<"Queue is Full.\n";
        }
    }
    void pop(){
        if(!empty()){
            front=(front+1)%maxsize;
            currentsize--;
        }
        else{
            cout<<"Queue is Empty.\n";
        }
    }
    int getFront(){
        return arr[front];
    }
};
int main(){
    Queue q(7);
    for(int i=1;i<=7;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getFront()<<" ";
    q.push(6);
    while(!q.empty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }
}