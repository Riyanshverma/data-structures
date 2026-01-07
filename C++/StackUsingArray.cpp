#include<iostream>
// #include<vector>

using namespace std;
class Stack{
    int *arr,stacktop,maxsize;
    public:
    Stack(int size=100){
        maxsize=size;
        arr = new int[maxsize]; 
        stacktop=-1;
    }
    bool isEmpty(){
        return stacktop==-1;
    }
    bool isFull(){
        return stacktop==maxsize-1;
    }
    void push(int data){
        if(!isFull()){
            arr[++stacktop]=data;
        }
        else{
            cout<<"Stack Overflow";
        }
    }
    void pop(){
        if(!isEmpty()){
            stacktop--;
        }
        else{
            cout<<"Stack Underflow";
        }
    }
    int top(){
        return arr[stacktop];
    }

};