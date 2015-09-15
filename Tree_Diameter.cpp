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
int diameter(struct node*);
int display();
int maxht(int );

int ht=0;
int hts[10001];
int main(){
    int par,ch,in;
    cin >> in;
    if (in==1){
        cout <<"0";
        return 0;
    }

    for (int i=0;i<in-1;i++){
        cin >>par >>ch;
        insert_edge(par,ch);
    }
    maxht(1);
    cout << diameter(x[1]);
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

int maxht(int p){
    struct node* croot=x[p];
    if (croot->head==NULL){
        hts[p]=0;
        return 0;
    }
    struct child* temp=croot->head;
    int c=0;
    while (temp!=NULL){
        int h=maxht(temp->n);
        if (h>c) c=h;
        temp=temp->next;
    }
    hts[p]=c+1;
    return c+1;
}

int diameter(struct node* croot){
    if (croot->head==NULL) return 0;
    struct child* temp=croot->head;
    int max1,max2;
    max1=max2=0;
    int maximum=0;
    while (temp!=NULL){
        if ((1+hts[temp->n])>max1){
            max2=max1;
            max1=hts[temp->n]+1;
        }
        else if ((hts[temp->n]+1)>max2){
            max2=hts[temp->n]+1;
        }
        maximum=max1+max2;
        temp=temp->next;
    }
    temp=croot->head;
    while (temp!=NULL){
        int c=diameter(x[temp->n]);
        if (c>maximum) maximum=c;
        temp=temp->next;
    }
    return maximum;
}
