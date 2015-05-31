#include <stdio.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;

int main(){
    head=NULL;
    int n,x,i;
    printf("Enter number of elements to push into the stack:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&x);
        push(x);
        print();
    }
    pop();
    print();
    printf("%d\n",top());
    printf("%d",is_empty());
    return 0;
}

int push(int a){
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
    struct node* temp = head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
int pop(){
    if (head==NULL) printf("Stack underflow!");
    else{
        struct node* temp=head;
        while (temp->next!=NULL){
            temp = temp->next;
        }
        struct node* temp1=head;
        while (temp1->next!=temp){
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        free(temp);
    }
    return 0;
}
int top(){
    if (head==NULL) printf("NULL\n");
    else{
        struct node* temp=head;
        while (temp->next!=NULL){
            temp = temp->next;
        }
        return temp->data;
    }
}

int is_empty(){
    if (head==NULL)
        return 1;
    else
        return 0;
}
