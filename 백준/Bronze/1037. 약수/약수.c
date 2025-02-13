#include<stdio.h>

int main(void){
    int num=0;
    int value=0;
    int max=1;
    int min=1000001;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&value);
        if(value>max){
            max=value;
        }
        if(value<min){
            min=value;
        }
    }
    printf("%d\n",min*max);
    return 0;
}