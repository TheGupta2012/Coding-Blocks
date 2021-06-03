#include <bits/stdc++.h>
using namespace std;

int LPS(string s)
{

    string rev = s;


    // heart of the algorithm...
    reverse(rev.begin(), rev.end());

    // now we have 2 strings
    int n = s.size();
    int m = rev.size();

    //init
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // code
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == rev[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    ios::sync_with_stdio(0);
    cout << "Longest palindromic subsequence in given string...\n";

    cout << "Enter the string :";
    string s;
    cin >> s;
    int ans = LPS(s);
    cout << "The length of the longest palindromic subsequence is :";
    cout << ans;

    return 0;
}