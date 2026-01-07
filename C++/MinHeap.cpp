#include<iostream>
using namespace std;
class MinHeap{
    public:
    int arr[100];
    int size;
    MinHeap(){
        arr[0]=-1;
        this->size=0;
    }
    void push(int val){
        arr[++size]=val;
        int index=size;
        int parent=index/2;
        while(index>1 && arr[index]<arr[parent]){
            swap(arr[index],arr[parent]);
            index=parent;
            parent=parent/2;
        }
    }

    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minindex=i;
        if(left<=size and arr[left]<arr[minindex]){
            minindex=left;
        }
        if(right<=size and arr[right]<arr[minindex]){
            minindex=right;
        }
        if(minindex!=i){
            swap(arr[i],arr[minindex]);
            heapify(minindex);
        }
        return ;
    }

    void pop(){
        arr[1]=arr[size];
        size--;
        heapify(1);
    }

    void heapArr(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        return ;
    }
    int getMin(){
        return arr[1];
    }

};
int main(){
    MinHeap h;
    h.push(80);
    h.push(100);
    h.push(110);
    h.push(50);
    h.push(70);
    h.push(90);
    h.push(35);
    h.push(60);
    h.heapArr();
    cout<<"\nMin Element: "<<h.getMin();
    h.pop();
    cout<<"\n";
    h.heapArr();
    h.pop();
    cout<<"\n";
    h.heapArr();

}