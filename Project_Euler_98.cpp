#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 15
#define MAX 1000000
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

ifstream inf("abc.txt");
ofstream of("abcout.txt");
char data[2000][20];
char pr[100][2][20];
int m=0;

int compute(int in){
	int l = strlen(pr[in][0]);
	l=pow(10,l-1);
	int i=1;
	while(i*i<l)i++;
	int lb = i;
	l*=10;
	while(i*i<l)i++;
	int ub = (i-1);
	fori(lb,ub,1){
		int x = i*i;
		int mark[10];
		int s[100];
		set(mark,0);
		set(s,0);
		int l = strlen(pr[in][0]);
		int j;
		for(j=l-1;j>=0;j--){
			if (s[pr[in][0][j]]==0){
				if (mark[x%10]==1) break;
				else{
					s[pr[in][0][j]]=x%10;
					mark[x%10]=1;
				}
			}
			else if (s[pr[in][0][j]]!=(x%10)) break;
			x/=10;
		}
		if (j!=-1||s[pr[in][1][0]]==0) continue;
		int sum=0;
		forj(0,l-1,1) sum=sum*10+s[pr[in][1][j]];
		int sr = sqrt(sum);
		if (sr*sr==sum){
			m=max(m,max(sum,i*i));
		}
	}
	return 0;
}

int init(){
	int i=0;
	char ch,v;
	while(inf.eof()!=1){
		inf>>ch>>v;
		int j=0;
		while(v!='"'){
			data[i][j++]=v;
			inf>>v;
		}
		inf>>ch;
		i++;
	}
	int n = i-1;
	int cn=0;
	fori(0,n-1,1){
		int s[100];
		set(s,0);
		int l = strlen(data[i]);
		forj(0,l-1,1) s[int(data[i][j])]++;
		int f=0;
		forj(i+1,n-1,1){
			if (strcmp(data[i],data[j])==0) continue;
			int s1[100];
			set(s1,0);
			l=strlen(data[j]);
			for(int k=0;k<l;k++) s1[int(data[j][k])]++;
			int k;
			for(k=65;k<=90;k++) if (s1[k]!=s[k]) break;
			if (k==91){
				if (f==0) of << data[i] << endl;
				of << data[j] << endl;
				strcpy(pr[cn][0],data[i]);
				strcpy(pr[cn][1],data[j]);
				cn++;
				f++;
			}
		}
		if (f!=0) of << endl;
	}
	fori(0,cn-1,1) compute(i);
	cout << m << endl;
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
