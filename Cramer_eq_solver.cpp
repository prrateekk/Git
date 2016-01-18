#include <bits/stdc++.h>
#define ll long long
#define INF 1000000007
#define M 1000000007
#define MAX 100000
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

ll int solve_del(ll int mat[][1000],int n){
	ll int det = 0;
	fori(0,n-1,1){
		int s = i;
		ll int p = 1,p2 = 1;
		forj(0,n-1,1){
			p*=(mat[j][(s+j)%3]);
			p2*=(mat[n-j-1][(s+j)%3]);
		}
		det+=(p-p2);
	}
	return det;
}

double res[1000];

int solve_eqs(int n,ll int rhs[]){	//n variable n equations
	ll int mat[n][1000];  //matrix lhs
	fori(0,n-1,1){    //can be inputted
		forj(0,n-1,1){
			mat[i][n-1-j] = pow(i+1,j);
		}
	}
	//Solving the matrix
	ll int del = solve_del(mat,n);
	fori(0,n-1,1){
		ll int temp[n];
		forj(0,n-1,1) temp[j] = mat[j][i];
		forj(0,n-1,1) mat[j][i] = rhs[j];
		ll int del_t = solve_del(mat,n);
		res[i] = double(del_t)/del;
		forj(0,n-1,1) mat[j][i]=temp[j];
	}
	return 0;
}

int init(){
	ll int rhs[]={1,8,27};
	solve_eqs(3,rhs);
	fori(0,2,1) cout << res[i] << endl;
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

