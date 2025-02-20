#include<stdio.h>

int num[9]={0,};
int stack[9]={0,};
int Max=0;
void func(int N,int M);

int main(void){
    int N;
    int M;
    scanf("%d %d",&N,&M);
    Max=M;
    func(N,M);
    return 0;
}

void func(int N,int M){
    if(M==1){
        for(int j=1;j<=N;j++){
            if(num[j]==0){
                for(int z=Max;stack[z]!=0;z--){
                    printf("%d ",stack[z]);
                }
                printf("%d\n",j);
            }
            else{
                continue;
            }
        }
        return;
    }
    for(int i=1;i<=N;i++){
        if(num[i]==1){
            continue;
        }
        else{
            num[i]=1;
            stack[M]=i;
            func(N,M-1);
            num[i]=0;
            stack[M]=0;
            }
        }
    
}