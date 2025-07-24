#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top;
char stack[1000];

int is_balanced(char str[]){
    top=-1;
    for(int i=0;str[i]!='\n';i++){
        char temp=str[i];
        if(temp=='('||temp=='['){
            stack[++top]=temp;
        }
        if(temp==')'){
            if(top==-1||stack[top]=='['){
                return 0;
            }
            top--;
        }
        if(temp==']'){
            if(top==-1||stack[top]=='('){
                return 0;
            }
            top--;
        }
    }
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    char str[1000];
    while(1){
        fgets(str,sizeof(str),stdin);
        if(strcmp(str,".\n")==0){
            break;
        }
        if(is_balanced(str)==1){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}