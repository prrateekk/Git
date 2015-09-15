#include <iostream>
#define N 10000
using namespace std;

struct node{
    struct node* parent;
    struct child* head;
    struct child* tail;
};
struct node* root;
struct node* x[N];

struct child{
    int n;
    struct child* next;
};

int insert_edge(int ,int );
int display();
int max_ht(struct node* ,int );
int maxht2(struct node* );

int ht=0;
int main(){
    int par,ch;
    for (int i=0;i<6;i++){
        cin >>par >>ch;
        insert_edge(par,ch);
    }
    root=x[0];
    max_ht(root,0);
    cout << ht;
    cout << maxht2(root);
    return 0;
}

struct node* getnode(){
    struct node* temp=new node();
    temp->parent=NULL;
    temp->head=NULL;
    return temp;
}

int insert_edge(int par,int ch){
    if (x[par]==NULL) x[par]=getnode();
    if (x[ch]==NULL){
        x[ch]=getnode();
        x[ch]->parent=x[par];
    }
    struct child* temp=new child();
    temp->n=ch;
    temp->next=NULL;
    if (x[par]->head==NULL){
        x[par]->head=temp;
        x[par]->tail=temp;
    }
    else{
        (x[par]->tail)->next=temp;
        x[par]->tail=temp;
    }
    return 0;
}
//method 1
int max_ht(struct node* croot,int c){
    if (croot->head==NULL){
        if (c>ht) ht=c;
        return 0;
    }
    struct child* temp=croot->head;
    while (temp!=NULL){
        max_ht(x[temp->n],c+1);
        temp=temp->next;
    }
    return 0;
}
//method 2
int maxht2(struct node* croot){
    if (croot->head==NULL) return 0;
    struct child* temp=croot->head;
    int c=0;
    while (temp!=NULL){
        int h=maxht2(x[temp->n]);
        if (h>c) c=h;
        temp=temp->next;
    }
    return c+1;
}

/*
int display(){
    for (int i=0;i<5;i++){
        cout << endl<< "Parent:" << i<<endl;
        struct child* temp=x[i]->head;
        while (temp!=NULL){
            cout << temp->n<<" ";
            temp=temp->next;
        }
    }
    return 0;
}
*/

