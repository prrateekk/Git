#include <stdio.h>
#include <string.h>
char s[20],r[20],stack[10];
int len,top=-1,c=-1;
int push(char);
int main(){
    printf("Enter the expression:");
    scanf("%s",s);
    len=strlen(s);
    int i;
    for (i=0;i<len;i++){
        if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='('||s[i]==')'){
            if (is_empty()==1) push(s[i]);
            else if (s[i]=='(') push(s[i]);
            else if (stack[top]=='*'||stack[top]=='/'){
                empty_stack();
                push(s[i]);
            }
            else if (s[i]==')'){
                empty_stack();
                top--;
            }
            else
                push(s[i]);
        }
        else
        r[++c]=s[i];
    }
    empty_stack();
    for (i=0;i<len;i++) printf("%c",r[i]);
    return 0;
}
int is_empty(){
    if (top==-1) return 1;
    else return 0;
}
int push(char x){
    stack[++top]=x;
    return 0;
}
int empty_stack(){
    while (top!=-1){
    if (stack[top]=='(') break;
    r[++c]=stack[top--];
    }
    return 0;
}
