#include <stdio.h>
int top=-1;
char a[20];
int push(char);
int main(){
    int n,i,flag=0;
    char c;
    scanf("%d",&n);
    fflush(stdin);
    for (i=0;i<n;i++){
        scanf("%c",&c);
        if (c=='('||c=='{'||c=='['){
            push(c);
        }
        else if ((c==')'&&a[top]=='(')||(c=='}'&&a[top]=='{')||(c==']'&&a[top]=='[')){
            pop();
        }
        else{
            printf("Not Balanced");
            flag=1;
            break;
        }
    }
    if (flag==0) printf("Balanced");
    return 0;
}
int pop(){
    top--;
    return 0;
}

int push(char x){
    a[++top]=x;
    return 0;
}
