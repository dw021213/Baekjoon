#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;
typedef struct node{
    link next;
    int data;
}node;

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
    visited[start]=1;
    for(;temp;temp=temp->next){
        if(visited[temp->data]==0){
            dfs(list,num,temp->data,visited);
        }
    }
}

int main(void){
    int num;
    int count;
    int cycle=0;
    int start;
    int from,to;
    link* list;
    int* visited;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf(" %d",&num);
        num++;
        list=(link*)malloc(sizeof(link)*num);
        for(int i=0;i<num;i++){
            list[i]=0;
        }
        for(int i=1;i<num;i++){
            scanf(" %d",&from);
            add(list,i,from);
        }
        visited=(int*)malloc(sizeof(int)*num);
        for(int i=0;i<num;i++){
            visited[i]=0;
        }
        for(int i=1;i<num;i++){
            if(visited[i]==0){
                dfs(list,num,i,visited);
                cycle++;
            }
        }
        printf("%d\n",cycle);
        cycle=0;
        free(visited);
        free(list);
    }

}