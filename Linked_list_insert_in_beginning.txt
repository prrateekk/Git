#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
int main(){
    head=NULL;
    printf("Enter number of elements:");
    int n,i,x;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter an element:");
        scanf("%d",&x);
        insert(x);
        print();
    }
    return 0;
}
int insert(int a){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = a;
    temp->next=head;
    head = temp;
    return 0;
}
int print(){
    struct node* temp = head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
