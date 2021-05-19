#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int  LCS(string x, string y, int n, int m)
{
    // init the DP
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {   // this is us using the base condition of the 
            // the RECURSION to init the dp
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // code 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // the n and the m variables are actually 
            // replaced by the indices of the loops 

            // n changes to i 
            // m changes to j 


            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    //return ans
    return dp[n][m];
}
int main()
{
    ios::sync_with_stdio(0);

    string x, y;

    cout << "Enter string 1 :";
    cin >> x;
    cout << "Enter string 2 :";
    cin >> y;
    int n = x.size();
    int m = y.size();

    memset(dp, -1, sizeof(dp));
    int ans = LCS(x, y, n, m);
    cout << " Length of longest common subsequence is :";
    cout << ans;

    return 0;
}