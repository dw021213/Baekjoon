#include <stdio.h>

int solution(int n, int w, int num) {
    int answer = 0;
    int i=0;
    int j=0;
    int cnt=0;
    int arr[n/w+1][w];
    for (i = 0; i < n / w + 1; i++) {
        for (j = 0; j < w; j++) {
            arr[i][j]=0;
        }
    }
    j=0;
    i=0;
    for(;;){
        if(cnt==n)break;
        arr[i][j++]=++cnt;
        if(cnt==n)break;
        if(j==w){
            j--;
            i++;
            for(;;){
                arr[i][j--]=++cnt;
                if(cnt==n)break;
                
                if(j==-1){i++;j++;break;}
            }
            
        }
    }
    
    for(int i=0;i<n/w+1;i++){
        for(int j=0;j<w;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<n/w+1;i++){
        for(int j=0;j<w;j++){
            if(arr[i][j]==num){
                for(int z=i;z!=n/w+1&&arr[z][j]!=0;z++){
                    answer++;
                }
            break;
            }
        }
    }
    return answer;
}