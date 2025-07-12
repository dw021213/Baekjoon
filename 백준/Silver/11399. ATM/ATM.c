#include<stdio.h>
#include<stdlib.h>

void insert(int* list,int num,int i){
    list[0]=num;
    while(num<list[i]){
        list[i+1]=list[i];
        i--;
    }
    list[i+1]=num;
}

void insertion(int* list,int num){
    int temp;
    for(int j=2;j<=num;j++){
        temp=list[j];
        insert(list,temp,j-1);
    }
}

int main(void){
    int num;
    int sum=0;
    int total=0;
    scanf("%d",&num);
    num++;
    int* list=(int*)malloc(sizeof(int)*num);
    for(int i=1;i<num;i++){
        scanf("%d",&list[i]);
    }
    insertion(list,num-1);
    sum=list[1];
    total=list[1];
    for(int i=2;i<num;i++){
        sum=sum+list[i];
        total+=sum;
    }
    printf("%d",total);
}