#include <stdio.h>
int addedge(int ,int ,int );
struct node{
    int wt;
    int dest;
    struct node* next;
};
struct node* head[100000];
struct node* tail[100000];

int main(){
    memset(head,NULL,sizeof(head));
    memset(tail,NULL,sizeof(tail));
    int n,i,src,dest,wt;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d%d%d",&src,&dest,&wt);
        addedge(src,dest,wt);
    }

    return 0;
}

int addedge(int src,int dest,int wt){
    struct node* temp=malloc(sizeof(struct node));
    temp->next=NULL;
    temp->dest=dest;
    temp->wt=wt;
    if (head[src]==NULL){
        head[src]=temp;
    }
    else{
        tail[src]->next=temp;
        tail[src]=temp;
    }
    tail[src]=temp;
    return 0;
}


