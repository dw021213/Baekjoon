#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

int binarySearch(int* B, int M, int target) {
    int left = 0, right = M;
    while (left < right) {
        int mid = (left + right) / 2;
        if (B[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main(void){
    int T,N,M;
    int count;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        count=0;
        scanf("%d %d",&N,&M);
        int* A=(int*)malloc(sizeof(int)*N);
        int* B=(int*)malloc(sizeof(int)*M);
        for(int j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        for(int j=0;j<M;j++){
            scanf("%d",&B[j]);
        }
        qsort(A,N,sizeof(int),compare);
        qsort(B,M,sizeof(int),compare);
        for (int i = 0; i < N; i++) {
            count += binarySearch(B, M, A[i]);
        }
        free(A);
        free(B);
        printf("%d\n",count);
    }
}