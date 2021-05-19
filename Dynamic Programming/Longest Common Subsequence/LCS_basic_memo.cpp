#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    else
    {
        if (dp[n][m] != -1)
            return dp[n][m];
        else
        {
            if (x[n - 1] == y[m - 1])
            {
                dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
            }
            else
            {
                dp[n][m] = max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
            }

            return dp[n][m];
        }
    }
}
string getLCS(string x, string y, int n, int m)
{
    int i = n;
    int j = m;
    list<char> ans;

    while (i >= 0 && j >= 0)
    {
        if (x[i] == y[j])
        {
            ans.push_front(x[i]);
            i -= 1;
            j -= 1;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i -= 1;
            else if (dp[i - 1][j] < dp[i][j - 1])
                j -= 1;
            else
                i -= 1;
        }
    }

    string res = "";
    for (auto k : ans)
        res += k;

    return res;
}
int main()
{
    string x, y;
    ios::sync_with_stdio(0);
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
    cout << " \nLCS is :" << getLCS(x, y, n, m);
    return 0;
}
