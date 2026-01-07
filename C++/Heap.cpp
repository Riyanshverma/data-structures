#include<iostream>
#include<vector>
using namespace std;

// The code for Min Heap using Vector
class MinHeap{
    vector<int> arr;
    public:
    MinHeap(int size=10){
        arr.reserve(size+1);
        arr.push_back(INT8_MIN);
    }
    void push(int data){
        arr.push_back(data);
        int idx=arr.size()-1;
        int parent=idx/2;
        while(idx>1 && arr[idx]<arr[parent]){
            swap(arr[idx],arr[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minidx=i;
        if(left<arr.size() && arr[left]<arr[minidx]){
            minidx=left;
        }
        if(right<arr.size() && arr[right]<arr[minidx]){
            minidx=right;
        }
        if(minidx!=i){
            swap(arr[i],arr[minidx]);
            heapify(minidx);
        }
    }
    void pop(){
        int idx=arr.size()-1;
        swap(arr[1],arr[idx]);
        arr.pop_back();
        heapify(1);
    }
   void heapArr(void){
        for(auto x : arr){
            cout<<x<<" ";
        }
    }
    int getmin(void){
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
    cout<<"\n"<<h.getmin();
}