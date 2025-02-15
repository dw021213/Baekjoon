#include<stdio.h>

int main(void){
    int i;
    int k;
    int num;
    int res=1;
    int m[1001][3]={0,};
    scanf("%d %d",&i,&k);
    for(int j=0;j<i;j++){
        scanf("%d",&num);
        for(int z=0;z<3;z++){
            scanf("%d",&m[num][z]);
        }
    }
    for(int j=1;j<=i;j++){
        if(j==k){
            continue;
        }
        if(m[j][0]>m[k][0]){
            res++;
        }
        if(m[j][0]==m[k][0]){
            if(m[j][1]>m[k][1]){
                res++;
            }
            if(m[j][1]==m[k][1]){
                if(m[j][2]>m[k][2]){
                    res++;
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}