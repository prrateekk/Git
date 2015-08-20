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

struct queue{
    int data;
    struct queue* next;
};
struct queue* t=NULL;
struct queue* h=NULL;

int enqueue(int data){
    if (done[data]==1) return 0;
    struct queue *temp=malloc(sizeof(struct queue));
    temp->data=data;
    temp->next=NULL;
    done[data]=1;
    if (t==NULL){
        h=temp;
    }
    else{
        t->next=temp;
    }
    t=temp;
    return 0;
}

int dequeue(){
    struct queue* temp=h;
    if (h==t) t=NULL;
    h=h->next;
    free(temp);
    return 0;
}

int isempty(){
    if (h==NULL&&t==NULL) return 1;
    else return 0;
}

int main(){
    memset(head,NULL,sizeof(head));
    memset(tail,NULL,sizeof(tail));
    int n,i,src,dest,wt;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d%d",&src,&dest);
        addedge(src,dest,1);
    }
    breadth_traversal(2);
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

int breadth_traversal(int src){
    enqueue(src);
    done[src]=1;
    while (!isempty()){
        printf("%d ",h->data);
        struct node* temp=head[h->data];
        while (temp!=NULL){
            enqueue(temp->dest);
            temp=temp->next;
        }
        dequeue();
    }
    return 0;
}
