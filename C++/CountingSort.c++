#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void counting(vector<int> arr){
    int maxele=*max_element(arr.begin(),arr.end());
    vector<int> freq(maxele+1,0);
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    int k=0;
    for(int i=1;i<freq.size();i++){
        while(freq[i]--){
            arr[k++]=i;
        }
    }
    for(int x : arr){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> arr{5,5,4,8,2,1,9,3,5,0,1,3,8,3,2};
    counting(arr);
    return 0;
}