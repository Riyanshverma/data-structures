#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countingSort(int arr[], int n, int pos){
    int freq[10]={0};
    int ans[n];
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        freq[i]=freq[i]+freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[--freq[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}
void radixSort(int arr[], int n){
    int ele=*max_element(arr,arr+n);
    for(int pos=1;ele/pos;pos*=10){
        countingSort(arr, n, pos);
    }
}
int main(){
    int arr[]={999,1,456,23,78,567,324,89,100};
    radixSort(arr, 9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}