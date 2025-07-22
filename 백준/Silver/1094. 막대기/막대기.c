#include<stdio.h>
#include<stdlib.h>

int count(int X){
    int sum=0;
    int temp=64;
    while(X!=0){
        while(X-temp<0){
            temp=temp/2;
        }
        X=X-temp;
        sum++;
    }
    return sum;
}

int main(void){
    int X;
    scanf("%d",&X);
    printf("%d",count(X));
}