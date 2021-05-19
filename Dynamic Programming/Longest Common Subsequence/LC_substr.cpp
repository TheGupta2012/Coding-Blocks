#include<bits/stdc++.h>
using namespace std;
int dp[105][105];

int LCstr(string x, string y, int n,int m){

    // init dp 
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // code

    // dp[i][j] represents the len of the 
    // longest common substr ending at index i
    // of string x and index j of string y 

    // that is why we can actually write 1 + dp[i-1][j-1] 
    // at the equality condition 
    int ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];

                ans = max(ans,dp[i][j]);
            }
            else 
                dp[i][j] = 0;
        }
    }

    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"Enter two strings :";
    cout<<"\nString s1 :";
    string x;
    cin>>x;
    cout<<"String s2 :";
    string y;
    cin>>y;
    int n = x.size(), m =y.size();
    cout<<"Longest common substring is :"<<LCstr(x,y,n,m);

    return 0;
}