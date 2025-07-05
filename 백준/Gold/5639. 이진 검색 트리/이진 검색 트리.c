#include<stdio.h>
#include<stdlib.h>

typedef struct node* treepointer;
typedef struct node{
    treepointer left;
    treepointer right;
    int data;
}node;

void postorder(treepointer route){
    if(route){
        postorder(route->left);
        postorder(route->right);
        printf("%d\n",route->data);
    }
}

int main(void){
    int num;
    treepointer route=NULL;
    while(scanf("%d",&num)==1){
        treepointer cur=route;
        treepointer temp=(treepointer)malloc(sizeof(node));
        temp->data=num;
        temp->left=NULL;
        temp->right=NULL;
        if(!route){
            route=temp;
        }
        else{
            while(1){
                if(cur->data<temp->data){
                    if(cur->right==NULL){
                        cur->right=temp;
                        break;
                    }
                    cur=cur->right;
                }
                if(cur->data>temp->data){
                    if(cur->left==NULL){
                        cur->left=temp;
                        break;
                    }
                    cur=cur->left;
                }
                
            }
        }
    }
    postorder(route);
}
