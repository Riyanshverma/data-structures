#include<iostream>
using namespace std;
class MaxHeap{
    public:
    int arr[100];
    int size;
    MaxHeap(){
        arr[0]=INT16_MAX;
        this->size=0;
    }
    void push(int val){
        arr[++size]=val;
        int index=size;
        int parent=index/2;
        while(index>1 and arr[index]>arr[parent]){
            swap(arr[index],arr[parent]);
            index=parent;
            parent/=2;
        }
    }

    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int maxindex=i;
        if(left<=size and arr[left]>arr[maxindex]){
            maxindex=left;
        }
        if(right<=size and arr[right]>arr[maxindex]){
            maxindex=right;
        }
        if(maxindex!=i){
            swap(arr[i],arr[maxindex]);
            heapify(maxindex);
        }
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
    int getMax(){
        return arr[1];
    }

};

int main(){
    MaxHeap h;
    h.push(80);
    h.push(100);
    h.push(110);
    h.push(50);
    h.push(70);
    h.push(90);
    h.push(35);
    h.push(160);
    h.heapArr();
    cout<<"\nMax Element: "<<h.getMax();
    // h.pop();
    // cout<<"\n";
    // h.heapArr();
    // h.pop();
    // cout<<"\n";
    // h.heapArr();
    // h.pop();
    // cout<<"\n";
    // h.heapArr();
    // cout<<"\n";

}