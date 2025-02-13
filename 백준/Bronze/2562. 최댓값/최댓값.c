#include<stdio.h>

int main(void){
    int i=0;
    int j=0;
    int num=0;
    int max=0;
    int s=0;
    for(i=0;i<9;i++){
        scanf("%d",&num);
        j++;
        if(num>max){
            max=num;
            s=j;
        }
    }
    printf("%d\n%d",max,s);
    return 0;
}