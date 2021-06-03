#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
// correct
lli dp[1005][1005];
set<int> indices;
lli LRS(string x, string y, lli n, lli m)
{
    // init the DP
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        { // this is us using the base condition of the
            // the RECURSION to init the dp
            if (i == 0 || j == 0)
                dp[i][j] = 0LL;
        }
    }

    // code

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // the n and the m variables are actually
            // replaced by the indices of the loops

            // n changes to i
            // m changes to j

            // main change in the code is that the
            // equal letters must NOT BE AT THE SAME INDICES...

            if (x[i - 1] == y[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    //return ans
    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(0);
    cout << "Enter the string :";
    string s;
    cin >> s;
    int n = s.size();
    string a, b;
    a = s;
    b = s;
    cout << "Longest Repeating Subsequence length is :" << LRS(a, b, n, n);
    // cout << "\nThe LRS is :";
    // for (auto k : indices)
    //     cout << s[k];

    return 0;
}