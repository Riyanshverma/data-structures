#include<iostream>
using namespace std;
int main(){
    int arr[]={2,6,7,10,14,19,20};
    int n=7;
    int diff[n-1];
    for(int i=0;i<n-1;i++){
        diff[(2*i+1)/2]=arr[i+1]-arr[i];
    }
    int minval=*min_element(diff,diff+n-1);
    cout<<minval<<"\n";
    for(int i=0;i<n-1;i++){
        if(diff[i]==minval){
            cout<<arr[i]<<" "<<arr[i+1]<<endl;
            break;
        }
    }
}

