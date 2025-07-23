#include<stdio.h>
#include<stdlib.h>

int is_onenum(int N){
    int n1=N%10;
    int n2=(N/10)%10;
    int n3=(N/100)%10;
    int n4=(N/1000)%10;
    if(n4!=0){
        if((n4-n3)==(n3-n2)&&(n3-n2)==(n2-n1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(n3!=0){
        if((n3-n2)==(n2-n1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 1;
    }
}

int main(void){
    int num;
    int count=0;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        if(is_onenum(i)){
            count++;
        }
    }
    printf("%d",count);
}