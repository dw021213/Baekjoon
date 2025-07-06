#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int queue[1001];
int front=0;
int rear=0;

int popq(void){
    if(front==rear){
        return 0;
    }
    return queue[front++];
}

void addq(int data){
    queue[rear++]=data;
}

void add(node** list, int from,int to){
    node* temp = (node*)malloc(sizeof(node));
    temp->data=to;
    temp->next=NULL;
    if (list[from] == NULL || list[from]->data > to) {
        temp->next = list[from];
        list[from] = temp;
        return;
    }

    node* cur = list[from];
    while (cur->next && cur->next->data < to) {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
}

void dfs(node** list,int num,int i,int* visit){
    node* temp;
    if(!visit[i]){
        printf("%d ",i);
        visit[i]=1;
    }
    for(temp=list[i];temp;temp=temp->next){
        if(!visit[temp->data]){
            dfs(list,num,temp->data,visit);
        }
    }
}

void bfs(node** list,int num,int i,int* visit){
    int temp;
    node* cur;
    printf("%d ",i);
    visit[i]=1;
    addq(i);
    while(front!=rear){
        temp=popq();
        for(cur=list[temp];cur;cur=cur->next){
            if(!visit[cur->data]){
                printf("%d ",cur->data);
                addq(cur->data);
                visit[cur->data]=1;
            }
        }
    }
    
}

int main(void){
    int num, count, start;
    int from, to;
    scanf("%d %d %d",&num,&count,&start);
    num++;
    node** list=(node**)malloc(sizeof(node*)*num);
    for(int i=0;i<num;i++){
        list[i]=NULL;
    }
    for(int i=0;i<count;i++){
        scanf("%d %d",&from,&to);
        add(list,from, to);
        add(list,to, from);
    }
    int* visit=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        visit[i]=0;
    }
    dfs(list,num,start,visit);
    for(int i=0;i<num;i++){
        visit[i]=0;
    }
    printf("\n");
    bfs(list,num,start,visit);
}