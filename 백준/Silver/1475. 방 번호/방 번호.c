    #include<stdio.h>

    int main(void){
        int num[10]={0,0,0,0,0,0,0,0,0,0};
    int inp=0;
    int s=0;
    int max=0;
    scanf("%d",&inp);
    for(;inp!=0;){
        s=inp%10;
        num[s]+=1;
        inp/=10;
    }
    s=0;
    s=(num[6]+num[9]+1)/2;
    for(int i=0;i<6;i++){
        if(max<num[i]){
            max=num[i];
        }
    }
    for(int i=7;i<9;i++){
       if(max<num[i]){    
           max=num[i];
        }
    }
    if(max<s){
        max=s;
    }

    printf("%d",max);
    return 0;
}