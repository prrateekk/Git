#include <stdio.h>
int front=-1,rear=-1,queue[10];
int is_empty();
int main(){
    int n,i,x;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    for (i=0;i<2;i++)
    dequeue();
    enqueue(5);
    print();
    return 0;
}
int enqueue(int x){
    if (front%10!=(1+rear)%10) queue[(++rear)%10]=x;
    else printf("Queue max!\n");
    if (front==-1) front++;
    return 0;
}
int dequeue(){;
    if (is_empty==1) printf("Empty Queue!\n");
    else
        front++;
    return 0;
}
int print(){
    int i;
    for (i=front;i<=rear;i++) printf("%d ",queue[i%10]);
    printf("\n");
}
int is_empty(){
    if (front>rear||rear==-1) return 1;
    else return 0;
}
