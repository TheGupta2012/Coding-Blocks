#include <bits/stdc++.h>
using namespace std;

string LP_substr(string s)
{
    int n = s.size();
    bool dp[n][n];
    // init
    // dp[i][j] represents whether s[i] to s[j] is
    // a palindrome or not
    memset(dp, false, sizeof(dp));

    // all 1 length strings are palindromes
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    // 2 length palindromes
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = true;
    }

    //code

    // remember the dp is very nice
    // dp[i][j] = true if s[i] == s[j] and dp[i+1][j-1] == true

    // need to start from ahead

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {

            if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                dp[i][j] = true;

            else
                dp[i][j] = false;
        }
    }
    int max = 0;
    int left, right;
    // now find the largest index difference
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == true)
            {
                if (abs(j - i) > max)
                {
                    left = i;
                    right = j;
                    max = abs(j - i);
                }
            }
        }
    }

    // that's it
    // now find the string
    string ans = "";

    for (int i = left; i <= right; i++)
    {
        ans += s[i];
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cout << "Enter the string :";
    string s;
    cin >> s;
    string ans = LP_substr(s);
    cout << "The longest palindromic substring is :";
    cout << ans;
    return 0;
} // namespace std;
