#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
struct Point{
    int x;
    int y;
};
int findDistance(struct Point a, struct Point b);
void generatePoint(struct Point *a){
    int lower=0;
    int upper=10;
    int x=(rand()%(upper - lower + 1)) + lower;
    int y=(rand()%(upper - lower + 1)) + lower;
    a->x=x;
    a->y=y;
}
int main(){
    struct Point arr[5];
    for(int i=0;i<5;i++){
        generatePoint(&arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("x->%d : y->%d\n",arr[i].x,arr[i].y);
    }
    struct Point a;
    struct Point b;
    int minDistance=-1;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            int distance=findDistance(arr[i],arr[j]);
            minDistance=MIN(distance,minDistance);
        }
    }
}
int findDistance(struct Point a, struct Point b){

}