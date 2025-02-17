#include<stdio.h>

int main(void){
    int num;
    int i=1;
    int cnt=0;
    int numbers[500001]={0,};
    scanf("%d",&num);
    for(;;){
        if(cnt==num-1){
            for(int j=1;j<=num;j++){
                if(numbers[j]==0){
                    printf("%d",j);
                }
            }
            break;
        }
        if(numbers[i]==0){
            numbers[i]=1;
            cnt++;
            for(;;){
                i++;
                if(i>num){
                    i=1;
                }
                if(numbers[i]==0){
                    i++;
                    if(i>num){
                        i=1;
                    }
                    break;
                }
            }
            continue;
        }
        i++;
        if(i>num){
            i=1;
        }
    }
}