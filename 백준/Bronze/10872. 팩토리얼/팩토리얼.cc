#include<stdio.h>

int main(void){
    int num=0;
    int fac=1;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        fac*=i;
    }
    printf("%d\n",fac);
    return 0;
}