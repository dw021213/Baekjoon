#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;
typedef struct node{
    link next;
    int data;
}node;

int count=1;

void add(link* list,int from,int to){
    link temp=(link)malloc(sizeof(node));
    link cur;
    temp->data=to;
    temp->next=NULL;
    if(list[from]==NULL||list[from]->data<to){
        temp->next=list[from];
        list[from]=temp;
        return;
    }
    else{
        cur=list[from];
        while(cur->next&&cur->next->data>to){
            cur=cur->next;
        }
        temp->next=cur->next;
        cur->next=temp;
    }
}

void dfs(link* list,int num,int start,int* visited){
    link temp=list[start];
    int flag=0;
    visited[start]=count++;
    for(;temp;temp=temp->next){
        if(visited[temp->data]==0){
            flag=1;
            dfs(list,num,temp->data,visited);
        }
    }
}

int main(void){
    int num;
    int count;
    int start;
    int from,to;
    scanf("%d %d %d",&num,&count,&start);
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
    dfs(list,num,start,visited);
    for(int i=1;i<num;i++){
        printf("%d\n",visited[i]);
    }
}