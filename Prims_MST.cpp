//============================================================================
// Name        : Prim's_MST.cpp
// Author      : Prateek Agarwal
// Institution : NIT Jalandhar
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define INF 1000000000

//adjacency list representation of graph
struct adj{
	int v,wt;
	adj *next;
};

struct graph{
	adj *head;
};

graph src[MAX];

int vt,e;
int mark[MAX];

struct edge{
	int from,to,wt;
};

edge heap[MAX];
edge mst[MAX];

int heap_in[MAX],heapsize;
int c = 0;

int flip(int i,int j){
	swap(heap[i],heap[j]);
	heap_in[heap[i].to] = i;
	heap_in[heap[j].to] = j;
	return 0;
}

int bubble_up(int i){
	int p = (i-1)/2;
	while(heap[p].wt > heap[i].wt){
		flip(i,p);
		i = p;
		p = (i-1)/2;
	}
	return 0;
}

int bubble_down(int i){
	int l = 2*i+1;
	int r = l+1;
	int smallest = i;
	if (l<heapsize && heap[l].wt<heap[smallest].wt) smallest = l;
	if (r<heapsize && heap[r].wt<heap[smallest].wt) smallest = r;
	if (smallest!=i){
		flip(i,smallest);
		bubble_down(smallest);
	}
	return 0;
}

edge extract_min(){
	edge node = heap[0];
	flip(0,heapsize-1);
	heapsize--;
	bubble_down(0);
	return node;
}

int build_heap(){
	heapsize = vt;
	for(int i=0;i<vt;i++){
		heap[i].to = i;
		heap_in[i] = i;
		heap[i].wt = INF;
	}
	heap[0].wt = heap[0].from = 0;
	return 0;
}

//display MST
int display(int n,edge x[]){
	for(int i=1;i<n;i++){
		cout << mst[i].from << "-" << mst[i].to << ":" << mst[i].wt << endl;
	}
	return 0;
}

int disp_list(){
	for(int i=0;i<vt;i++){
		cout << i << ":";
		adj *temp = src[i].head;
		while(temp!=NULL){
			cout << temp->v << "(" << temp->wt << ")" << " ";
			temp = temp -> next;
		}
		printf("\n");
	}
	return 0;
}

int input(){
	cin >> vt >> e;
	for(int i=0;i<e;i++){
		int u,v,w;
		cin >> u >> v >> w;

		adj * temp1 = new adj();
		adj * temp2 = new adj();

		temp1->v = v;
		temp1->wt = w;
		temp1->next  = src[u].head;
		src[u].head = temp1;

		temp2->v = u;
		temp2->wt = w;
		temp2->next  = src[v].head;
		src[v].head = temp2;
	}
	return 0;
}

int prim_MST(){

	build_heap();

	while(heapsize){

		edge mn = extract_min();
		mark[mn.to] = 1;
		adj *t = src[mn.to].head;

		while(t!=NULL){
			if (mark[t->v]==0){
				int x = heap_in[t->v];
				if (heap[x].wt > t->wt){
					heap[x].wt = t->wt;
					heap[x].from = mn.to;
					bubble_up(x);
				}
			}
			t = t->next;
		}

		mst[c++] = mn;
	}
	return 0;
}

int main() {
	input();
	prim_MST();
	display(c,mst);
	return 0;
}

/*
Test Case - 
9 14
0 1 4
0 7 8
1 7 11
7 8 7
1 2 8
6 7 1
2 8 2
6 8 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
Output - 
6-7:1
2-8:2
6-5:2
0-1:4
2-5:4
2-3:7
0-7:8
3-4:9
*/
