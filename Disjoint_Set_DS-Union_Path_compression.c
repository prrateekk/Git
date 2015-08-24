#include <stdio.h>
struct sets{
    int data;
    int rank;
    struct sets *parent;
};
struct sets *s[100000];
int arr[100000],n;
int main(){
    int i;
    scanf("%d",&n);
    makeset(n);
    unionsets(1,2);
    unionsets(2,3);
    unionsets(4,5);
    unionsets(4,7);
    unionsets(4,6);
    displaytrial();
    return 0;
}

int makeset(int n){
    int i,val;
    for (i=0;i<n;i++){
        scanf("%d",&val);
        struct sets* temp=malloc(sizeof(struct sets));
        temp->data=val;
        temp->rank=0;
        temp->parent=temp;
        s[val]=temp;
        arr[i]=val;
    }
    return 0;
}

int unionsets(int x,int y){         // O(log(n)) TIME IMPROVISED BY PATH COMPRESSION.
    struct sets *r_x,*r_y;
    r_x=getrank(x);
    r_y=getrank(y);
    if (r_x->rank==r_y->rank){
        r_y->parent=r_x;
        r_x->rank+=1;
    }
    else if (r_x->rank>r_y->rank){
        r_y->parent=r_x;
        r_x->rank+=1;
    }
    else{
        r_y->parent=r_x;
        r_x->rank+=1;
    }
    return 0;
}

int getrank(int x){
    struct sets* temp=s[x];
    while (temp->parent!=temp){
        temp=temp->parent;
    }
    s[x]->parent=temp;      //PATH COMPRESSION
    return temp;
}

int displaytrial(){
    int i;
    for (i=0;i<n;i++){
        printf("%d ",s[arr[i]]->rank);
    }
    return 0;
}
