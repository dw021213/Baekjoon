#include<stdio.h>

int main(void){
    int num=0;
    float sum=0;
    int max=0;
    int i=0;
    scanf("%d",&i);
    for(int j=0;j<i;j++){
        scanf("%d",&num);
        sum+=num;
        if(num>max){
            max=num;
        }
    }
    printf("%f",sum/(i*max)*100);
    return 0;
}