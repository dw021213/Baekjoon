#include<stdio.h>

int main(void){
    int  num=0;
    int res=0;
    int min=101;
    for(int i=0;i<7;i++){
        scanf("%d",&num);
        if(num%2==1)
        {
            res+=num;
            if(num<min){
                min=num;
            }
        }
    }
    if(min==101){
        printf("-1\n");
    }
    else{
        printf("%d\n%d\n",res,min);
    }
    return 0;
}