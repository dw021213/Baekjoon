#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

int binsearch(int* B,int b,int a){
    int left=0;
    int right=b-1;
    while(left<=right){
        int middle=(left+right)/2;
        if(B[middle]==a){
            return 1;
        }
        if(B[middle]<a){
            left=middle+1;    
        }
        if(B[middle]>a){
            right=middle-1;
        }
    }
    return 0;
}

int main(void){
    int a,b,i;
    int count=0;
    scanf("%d %d",&a,&b);
    int* A=(int*)malloc(sizeof(int)*a);
    int* B=(int*)malloc(sizeof(int)*b);
    for(i=0;i<a;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<b;i++){
        scanf("%d",&B[i]);
    }
    qsort(A,a,sizeof(int),compare);
    qsort(B,b,sizeof(int),compare);
    int* list=(int*)malloc(sizeof(int)*a);

    for(i=0;i<a;i++){
        if(!binsearch(B,b,A[i])){
            list[count++]=A[i];
        }
    }

    printf("%d\n",count);
    for(i=0;i<count;i++){
        printf("%d ",list[i]);
    }
}