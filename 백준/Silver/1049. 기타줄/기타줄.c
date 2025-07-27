#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,M;
    int min[2];
    int price=0;
    min[0]=1000;
    min[1]=1000;
    int temp1,temp2;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&temp1,&temp2);
        if(temp1<min[0]){
            min[0]=temp1;
        }
        if(temp2<min[1]){
            min[1]=temp2;
        }
    }
    while(N>0){
        if(N>=6){
            if(min[1]*6>min[0]){
                N=N-6;
                price+=min[0];
            }
            else{
                N=N-6;
                price=price+min[1]*6;
            }
        }
        else{
            if(N*min[1]>min[0]){
                N=N-6;
                price+=min[0];
            }
            else{
                price=price+min[1]*N;
                N=0;
            }
        }
    }
    printf("%d",price);
}