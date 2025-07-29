#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct number{
    int num;
    char str[20];
}number;

char* num_str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int compare(const void* a,const void* b){
    return strcmp(((number*)a)->str,((number*)b)->str);
}

int main(void){
    int M,N;
    scanf("%d %d",&M,&N);
    number* list=(number*)malloc(sizeof(number)*(N-M+1));
    for(int i=M;i<=N;i++){
        list[i-M].num=i;
        if(i<10){
            strcpy(list[i-M].str,num_str[i]);
        }
        else{
            sprintf(list[i-M].str,"%s %s",num_str[(i/10)],num_str[(i%10)]);
        }
    }
    qsort(list,N-M+1,sizeof(number),compare);
    for(int i=0;i<N-M+1;i++){
        if(i!=0&&i%10==0){
            printf("\n");
        }
        printf("%d ",list[i].num);
    }
}