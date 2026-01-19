#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number(n): ";
    cin>>n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n+i;j++) {
            if(i+j+1>n-1) {
                if((i%2==0 && j%2==0) || (i%2==1 && j%2==1)) {
                    cout<<i+1<<" ";
                }
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}