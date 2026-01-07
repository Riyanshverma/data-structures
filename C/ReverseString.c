#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100];
    gets(s);
    int k,i=0,j=0;
    for(k=0;k<strlen(s);k++){
        if(s[k]==' '){
            j=k-1;
            while(i<=j){
                char ch = s[i];
                s[i] = s[j];
                s[j] = ch;
                i++;
                j--;
            }
            i=k+1;
        }
    }
    k--;
    while(i<=k){
        char ch = s[i];
        s[i] = s[k];
        s[k] = ch;
        i++;
        k--;
    }
    return 0;
}