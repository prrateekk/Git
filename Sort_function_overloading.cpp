#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define M 15
#define MAX 65536
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//Sort generalization(In this case,with strings)

struct node{
	char sen[1000];
};
node x[1000];

bool operator <(node a,node b){
	if (strcmp(a.sen,b.sen)<0) return true;
	else return false;
}

int init(){
	int n;
	scanf("%d",&n);
	char s[n][1000];
	fori(0,n-1,1) cin>>s[i];
	fori(0,n-1,1) strcpy(x[i].sen,s[i]);
	sort(x,x+n);
	fori(0,n-1,1) cout << x[i].sen << endl;
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
