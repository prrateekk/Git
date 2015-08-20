#include <stdio.h>
int addedge(int ,int ,int );
int done[100000];
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
        scanf("%d%d",&src,&dest);
        addedge(src,dest,1);
    }
    depth_first(2);
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
    }
    tail[src]=temp;
    return 0;
}

int depth_first(int start){
    printf("%d ",start);
    done[start]=1;
    traverse(head[start]);
    return 0;
}

int traverse(struct node* croot){
    if (croot==NULL) return 0;
    struct node* temp=croot;
    while (temp!=NULL){
        if (done[temp->dest]==0){
            printf("%d ",temp->dest);
            done[temp->dest]=1;
            traverse(head[temp->dest]);
        }
        temp=temp->next;
    }
    return 0;
}
