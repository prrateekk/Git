#include <stdio.h>
int a[10];
int top = -1;
int main(){
    int x;
    printf("Enter element to push into the stack:");
    scanf("%d",&x);
    push(x);
    scanf("%d",&x);
    push(x);
    scanf("%d",&x);
    push(x);
    scanf("%d",&x);
    push(x);
    print();
    pop();
    print();
    return 0;
}
int print(){
    int i;
    for (i=0;i<=top;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
int push(int x){
    if (top==9) printf("Stack overflow!");
    else
    a[++top]=x;
    return 0;
}
int pop(){
    if (top==-1) printf("Stack underflow");
    else
    top--;
    return 0;
}

int top(){
    return a[top];
}

int is_empty(){
    if (top==-1) return 1;
    else
        return 0;
}
