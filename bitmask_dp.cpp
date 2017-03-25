#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n,a[12],p[12],dp[12][5000][12][12];

int DP(int i,int mask,int px,int pp){
    if (i==n) return 0;
    if (dp[i][mask][px][pp]) return dp[i][mask][px][pp];
    int ans = INF;
    for (int j=0;j<n;j++){
        if (!(mask&(1<<j))){
            int extra = i>=2?(a[j]^a[px]^a[pp])*p[i]:0;
            ans = min(ans,DP(i+1,mask|(1<<j),j,px)+extra);
        }
    }
    return dp[i][mask][px][pp] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> p[i];
        cout << DP(0,0,0,0) << endl;
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
