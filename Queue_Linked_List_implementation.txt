#include <stdio.h>
struct node{
    int data;
    struct node* next;
};
struct node* head,*rear;
int main(){
    head=rear=NULL;
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    dequeue();
    dequeue();
    print();
    return 0;
}
int enqueue(int x){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = x;
    if (head==NULL){
        head=temp;
    }
    else{
        rear->next = temp;
    }
    temp->next = NULL;
    rear=temp;
    return 0;
}
int dequeue(){
    if (is_empty()==1) rear=NULL;
    struct node* temp = head;
    head=temp->next;
    free(temp);
    return 0;
}
int is_empty(){
    if (head==NULL) return 1;
    else
    return 0;
}
int print(){
    struct node* temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
