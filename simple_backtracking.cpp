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

//SIMPE BACKTRACKING

int c=0;
int func(int i,int mark[],char perm[]){
	if (i==3){
		cout << perm << endl;
		c++;
		return 0;
	}
	for(int j=0;j<26;j++){
		if (mark[j]==0){
			mark[j]=1;
			perm[i]=char(j+65);
			func(i+1,mark,perm);
			mark[j]=0;
		}
	}
	return 0;
}

int init(){
	int mark[50];
	set(mark,0);
	char a[50];
	func(0,mark,a);
	cout << endl << c << endl;
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
