//============================================================================
// Name        : Kruskal_MST.cpp
// Author      : Prateek Agarwal
// Institution : NIT Jalandhar
//============================================================================

#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100000

struct DSU{
	int parent,rank;
};

DSU set[MAX];

struct edge{
	int src,dst,wt;
};

edge a[MAX];
edge mst[MAX];

int v,e;

bool operator <(edge a,edge b){
	return a.wt<b.wt?true:false;
}

int get_root(int x){
	while(set[x].parent!=x) x = set[x].parent;
	return x;
}

int union_edge(int rx,int ry){
	if (set[rx].rank>=set[ry].rank){
		set[ry].parent = rx;
		set[rx].rank++;
	}
	else{
		set[rx].parent = ry;
		set[ry].rank++;
	}
	return 0;
}

int input(){
	cin >> v >> e;
	for (int i=0;i<v;i++){
		set[i].parent = i;
		set[i].rank = 0;
	}
	for (int i=0;i<e;i++){
		cin >> a[i].src >> a[i].dst >> a[i].wt;
	}
	return 0;
}

int kruskal_MST(){
	sort(a,a+e);
	int c = 0;
	for (int i=0;i<e;i++){
		int rx = get_root(a[i].src);
		int ry = get_root(a[i].dst);
		if (rx!=ry){
			union_edge(rx,ry);
			mst[c].src = a[i].src;
			mst[c].dst = a[i].dst;
			mst[c].wt = a[i].wt;
			c++;
		}
	}
	for(int i=0;i<c;i++){
		cout << mst[i].src << "-" << mst[i].dst << ":" << mst[i].wt << endl;
	}
	return 0;
}

int main() {
	input();
	kruskal_MST();
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

*/
