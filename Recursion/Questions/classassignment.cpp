#include<bits/stdc++.h>
using namespace std;
int find(int n,int *dp){
    if(dp[n]!=0) return dp[n];
    else{
        for(int i=2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
}
int main(){
    ios::sync_with_stdio(0);
    // exactly same as non_consec_ones 
    int t;
    cin>>t;
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 2;
    int m=1;
    while(t--)
    {
            int n;
            cin>>n;
            cout<<"#"<<m<<" : "<<find(n,dp)<<endl;
            m++;
    }
    return 0;
}
