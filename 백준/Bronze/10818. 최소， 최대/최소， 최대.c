#include<stdio.h>

int main(void){

    int i=0;
    int num=0;
    int max=-1000000;
    int min=1000000;
    int a=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&a);
        if(a>max)
            max=a;
        if(a<min)
            min=a;
    }
    printf("%d %d",min,max);
    return 0;
}