#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 1000000
#define MAX 10000000
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (ll int i=l;i<=r;i+=x)
#define forj(l,r,x) for (ll int j=l;j<=r;j+=x)
using namespace std;

int a[82][82],spt[82][82],dist[82][82];

//dijkstra's Algorithm Project_euler_83(0.149s)

int init(){
	ifstream inf("abc.txt");
	char ch;
	fori(1,80,1){
		forj(1,79,1) inf>>a[i][j]>>ch;
		inf>>a[i][80];
	}
	fori(1,80,1) forj(1,80,1) dist[i][j] = INF;
	fori(1,80,1) forj(1,80,1) spt[i][j] = 0;
	fori(0,81,1) a[i][81]=a[i][0]=a[0][i]=a[81][i]=INF;
	dist[1][1] = a[1][1];
	int cn = 0;
	while(cn!=6400){
		int m = INF,r,c;
		fori(1,80,1) forj(1,80,1) if (spt[i][j]==0&&dist[i][j]<m) m=dist[i][j],r=i,c=j;
		spt[r][c] = 1;
		dist[r-1][c] = min(dist[r-1][c],dist[r][c]+a[r-1][c]);
		dist[r+1][c] = min(dist[r+1][c],dist[r][c]+a[r+1][c]);
		dist[r][c-1] = min(dist[r][c-1],dist[r][c]+a[r][c-1]);
		dist[r][c+1] = min(dist[r][c+1],dist[r][c]+a[r][c+1]);
		cn++;
	}
	cout << dist[80][80] << endl;
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
