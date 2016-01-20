#include <bits/stdc++.h>
#define ll long long
#define INF 1000000007
#define M 1000000007
#define MAX 100000
#define PI 3.14
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (ll int i=l;i<=r;i+=x)
#define forj(l,r,x) for (ll int j=l;j<=r;j+=x)
using namespace std;

int heap[MAX],heapsize;

int max_heapify(int a[],int i){
	if (i>=heapsize) return 0;
	int l = 2*i+1;
	int r = l+1;
	int mx=i;
	if (a[l]>a[mx]) mx=l;
	if (a[r]>a[mx]) mx=r;
	if (mx!=i){
		swap(a[i],a[mx]);
		max_heapify(a,mx);
	}
	return 0;
}

int build_max_heap(int a[]){
	for(int i=heapsize/2;i>=0;i--) max_heapify(a,i);
	fori(0,heapsize-1,1) cout << a[i] << " ";
	cout << endl;
	return 0;
}

int init(){
	int n;
	scanf("%d",&n);
	fori(0,n-1,1) scanf("%d",&heap[i]);
	heapsize=n;
	build_max_heap(heap);
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
