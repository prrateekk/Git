#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
int main(){
    head=NULL;
    printf("Enter number of elements to enter:");
    int n,i,x;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&x);
        insert(x);
        print();
    }
    return 0;
}

int insert(int a){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    if (head==NULL) head=temp;
    else{
        struct node* temp1=head;
        while (temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return 0;
}

int print(){
    struct node* temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
