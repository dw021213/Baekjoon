#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* a,const void* b){
    if(strlen(*(const char**)a)>strlen(*(const char**)b)){
        return 1;
    }else if(strlen(*(const char**)a)==strlen(*(const char**)b)){
        int temp1=0;
        int temp2=0;
        for(int i=0;i<strlen(*(const char**)a);i++){
            if('0'<=(*(const char**)a)[i]&&(*(const char**)a)[i]<='9'){
                temp1+=(*(const char**)a)[i]-'0';
            }
        }
        for(int i=0;i<strlen(*(const char**)b);i++){
            if('0'<=(*(const char**)b)[i]&&(*(const char**)b)[i]<='9'){
                temp2+=(*(const char**)b)[i]-'0';
            }
        }
        if(temp1==temp2){
            return strcmp((*(const char**)a),(*(const char**)b));
        }
        else{
            return temp1-temp2;
        }
    }
    else{
        return -1;
    }
}

int main(void){
    int N;
    scanf("%d",&N);
    char** list=(char**)malloc(sizeof(char*)*N);
    for(int i=0;i<N;i++){
        list[i]=(char*)malloc(sizeof(char)*51);
    }
    for(int i=0;i<N;i++){
        scanf("%s",list[i]);
    }
    qsort(list,N,sizeof(char*),compare);
    for(int i=0;i<N;i++){
        printf("%s\n",list[i]);
    }
}