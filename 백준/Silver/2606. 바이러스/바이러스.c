/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

typedef struct node* link;
typedef struct node{
    int data;
    link next;
}node;

int cnt=1;

void add(link* list,int from,int to){
    link temp=(link)malloc(sizeof(node));
    link cur=list[from];
    temp->data=to;
    temp->next=NULL;
    if(list[from]==NULL){
        list[from]=temp;
        return;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
    }
    cur->next=temp;
}

void dfs(int* visited,link* list, int num,int start){
    visited[start]=cnt++;
    link temp=list[start];
    for(;temp;temp=temp->next){
        if(visited[temp->data]==0){
            dfs(visited,list,num,temp->data);
        }
    }
}

int main()
{
    int num;
    int count;
    int min=0;
    scanf("%d %d",&num,&count);
    int from,to;
    num++;
    link* list=(link*)malloc(sizeof(link)*num);
    for(int i=0;i<count;i++){
        scanf("%d %d",&from,&to);
        add(list,from,to);
        add(list,to,from);
    }
    int* visited=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        visited[i]=0;
    }
    dfs(visited,list,num-1,1);
    for(int i=1;i<num;i++){
        if(min<visited[i]){
            min=visited[i];
        }
    }
    printf("%d",min-1);
}








