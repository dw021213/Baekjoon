#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void* a, const void* b){
    return (*(int*)a-*(int*)b);
}

int count[8001];

int main(void){
    int num;
    int N;
    int min=4000;
    int max=-4000;
    int count_max=0;
    int sum=0;
    int count_num;
    int flag=0;
    scanf("%d",&num);
    int* list=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d",&N);
        list[i]=N;
        count[N+4000]++;
        sum+=N;
        if(N<min){
            min=N;
        }
        if(N>max){
            max=N;
        }
    }
    printf("%d\n",(int)round((double)sum/num));
    qsort(list,num,sizeof(int),compare);
    printf("%d\n",list[num/2]);
    for(int i=0;i<8001;i++){
        if(count[i]>count_max){
            count_max=count[i];
        }
    }
    for(int i=0;i<8001;i++){
        if(count[i]==count_max){
            if(flag==0){
                flag=1;
                count_num=i;
            }
            else{
                printf("%d\n",i-4000);
                flag=2;
                break;
            }
        }
    }
    if(flag==1){
        printf("%d\n",count_num-4000);
    }
    printf("%d",max-min);
}