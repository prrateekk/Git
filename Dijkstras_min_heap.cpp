#include <bits/stdc++.h>
#define ll long long
#define scan(n) scanf("%d",&n)
#define INF 1000000000
#define M 1000000
#define MAX 100000
#define X 6
#define LIM 10
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//SPOJ-http://www.spoj.com/problems/SHPATH/

//1-base indexing used

int heap[10001],heap_in[10001],v_in[10001],spt[10001];
//v_in[i] --> vertex residing in heap index i
//heap_in[i] --> heap index of vertex i
int heapsize;
int edge[10001][10001],top[10001],w[10001][10001],n;
map <string,int> m;
//correct
int swap(int x,int y){
	int temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
	temp = v_in[x];
	v_in[x] = v_in[y];
	v_in[y] = temp;
	heap_in[v_in[x]] = x;
	heap_in[v_in[y]] = y;
	return 0;
}
//correct
int bubble_down(int i){
	int l = 2*i;
	int r = l+1;
	int mn = i;
	if (l<=heapsize && heap[l]<heap[mn]) mn = l;
	if (r<=heapsize && heap[r]<heap[mn]) mn = r;
	if (mn!=i){
		swap(mn,i);
		bubble_down(mn);
	}
	return 0;
}
//correct
int bubble_up(int i){
	while(i!=1){
		int p = i/2;
		if (heap[i]<heap[p]){
			swap(i,p);
			i=p;
		}
		else break;
	}
	return 0;
}
//correct
int build_heap(){
	fori(1,heapsize,1){
		heap[i] = INF;
		v_in[i] = heap_in[i] = i;
		spt[i]=0;
	}
	return 0;
}
//correct
int extract_min(){
	int v = v_in[1];
	swap(1,heapsize);
	heapsize--;
	bubble_down(1);
	return v;
}

int dijkstra(int src,int dst){
	heapsize = n;
	build_heap();
	heap[src] = 0;
	bubble_up(src);
	while(1){
		int mn = extract_min();
		spt[mn] = heap[heap_in[mn]];
		if (mn==dst) return spt[mn];
		fori(1,top[mn],1){
			int neighbor = edge[mn][i];
			if (spt[neighbor]>0||neighbor==src) continue;
			int wt = w[mn][neighbor]+spt[mn];
			if (wt<heap[heap_in[neighbor]]){
				heap[heap_in[neighbor]] = wt;
				bubble_up(heap_in[neighbor]);
			}
		}
	}
	return 0;
}

int init(){
	int t;
	scan(t);
	while(t--){
		scan(n);
		char s[20];
		fori(1,n,1){
			scanf("%s",s);
			m[s] = i;
			scan(top[i]);
			forj(1,top[i],1){
				scan(edge[i][j]);
				scan(w[i][edge[i][j]]);
			}
		}
		int q;
		scan(q);
		while(q--){
			char src[20],dst[20];
			scanf("%s%s",src,dst);
			cout << dijkstra(m[src],m[dst]) << endl;
		}
	}
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
