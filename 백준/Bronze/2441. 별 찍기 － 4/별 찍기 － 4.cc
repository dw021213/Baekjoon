#include <stdio.h>

int main(void)
{
    int num=0;
    scanf("%d",&num);  
    for(int i=0;i<num;i++)
    {
        for(int j=i;j>0;j--)
        {
            printf(" ");
        }
        for(int j=i;j<num;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}