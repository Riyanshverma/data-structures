#include<iostream>
using namespace std;

// Heap Sort using Max Heap function:
void heapify(int arr[], int size, int i){
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
        heapify(arr,size,maxindex);
    }
}

void heapSort(int arr[], int size){
    // Building a Max Heap First
    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }

    // Sorting the Max Heap
    for(int i=size;i>0;i--){
        swap(arr[1],arr[i]);
        heapify(arr,i-1,1);
    }
}
void print(int arr[], int size){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size=8;
    int arr[]={INT16_MAX,1,2,3,4,5,6,7,8};
    heapSort(arr,size);
    print(arr,size);
}
