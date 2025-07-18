#include<stdio.h>
#include<stdlib.h>

long long mod(long long a, long long b, long long c) {
    if (b == 0) return 1;

    long long half = mod(a, b / 2, c);         // 분할
    long long result = (half * half) % c;      // 결합
    
    if (b % 2 == 1)                             // 홀수면 a 한 번 더 곱해줌
        result = (result * a) % c;

    return result;
}


int main(void){
    long long a,b,c;
    long long result;
    scanf("%lld %lld %lld",&a,&b,&c);
    result=mod(a,b,c);
    printf("%lld",result);
}