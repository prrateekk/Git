#include <stdio.h>
int push(char);
int n;
char a[20],b[20];
int top=-1;
int main(){
    char c;
    printf("How many characters?\n");
    int i;
    scanf("%d",&n);
    for (i=0;i<=n;i++){
        scanf("%c",&c);
        push(c);
    }
    reverse();
    print();
    return 0;
}
int push(char c){
    if (top==19) printf("Stack overflow!");
    else
    a[++top]=c;
    return 0;
}

int reverse(){
    int i;
    for (i=0;i<n;i++){
        b[i]=sendtop();
        pop();
    }
    return 0;
}

int sendtop(){
    return a[top];
}

int pop(){
    top--;
    return 0;
}

int print(){
    int i;
    for (i=0;i<=n;i++)
        printf("%c",b[i]);
    return 0;
}
