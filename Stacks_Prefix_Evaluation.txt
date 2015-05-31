#include <stdio.h>
#include <string.h>
int a[11],top=-1,len;
int main(){                 //Prefix Evaluation using stacks
    char exp[21];
    int i,x;
    printf("Enter an expression:");
    scanf("%s",exp);
    len=strlen(exp);
    printf("Enter the values of the respective variables in the postfix(in reverse order):");
    for (i=len-1;i>=0;i--){

        if (exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            if (exp[i]=='+'){
                x=a[top]+a[top-1];
                a[--top]=x;
            }
            else if (exp[i]=='-'){
                x=a[top]-a[top-1];
                a[--top]=x;
            }
            else if (exp[i]=='*'){
                x=a[top]*a[top-1];
                a[--top]=x;
            }
            if (exp[i]=='/'){
                x=a[top]/a[top-1];
                a[--top]=x;
            }
        }
        else{
            push();
        }
    }
    printf("%d",a[top]);
    return 0;
}

int push(){
    int n;
    scanf("%d",&n);
    a[++top]=n;
    return 0;
}

