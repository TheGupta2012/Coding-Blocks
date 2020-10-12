#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod = 1e9 + 7;
lli tiling(int n, int m, lli *dp)
// using dp to speed up
{   if(n<=m-1)
        { dp[n] = 1;
          return dp[n];}
    if(n==m)
        { return 2; }
    if(dp[n]!=0)
        return dp[n];
    dp[n] = (tiling(n-1,m,dp)%mod + tiling(n-m,m,dp)%mod)%mod;
    return dp[n];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    lli dp[n+10]={0};
    cout<<tiling(n,m,dp)<<endl;
    }
    return 0;
}
