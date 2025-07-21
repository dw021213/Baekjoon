#include<stdio.h>
#include<stdlib.h>

void cantor(int start, int end){
    if (end - start == 1) {
        printf("-");
        return;
    }
    int len = (end - start) / 3;
    cantor(start, start + len);       
    for (int i = 0; i < len; i++)      
        printf(" ");
    cantor(start + 2 * len, end); 
}

int main(void){
    int num;
    while(scanf("%d",&num)!=EOF){
        int len=1;
        for(int i=0;i<num;i++){
            len*=3;
        }
        cantor(0,len);
        printf("\n");
    }
}