#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define in(x) \
    lli x;    \
    cin >> x
// namespace
using namespace std;
// typdefs
typedef long long int lli;
typedef vector<lli> vi;

lli dp[1005][1005];
map<pair<lli, lli>, int> P;

lli Partition_Palindrome(string s, lli i, lli j)
{

    // base case
    if (i >= j)
    {
        dp[i][j] = 0LL;
    }

    // check for dp
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // if not checked
    if (P[{i, j}] == -1)
    {
        string t = s.substr(i, j - i + 1);
        string rev = t;
        reverse(all(rev));

        if (rev == t)
            P[{i, j}] = 1;
        else
            P[{i, j}] = 0;
    }

    // check for palindrome
    if (P[{i, j}] == 1) // means it is a palindrome
        return dp[i][j] = 0LL;

    // here
    // not even stored answer and not even palindrome

    lli s1, s2, temp, ans = 1e18;
    for (int k = i; k < j; k++)
    {
        s1 = Partition_Palindrome(s, i, k);
        s2 = Partition_Palindrome(s, k + 1, j);
        temp = s1 + s2 + 1LL;
        ans = min(ans, temp);
    }

    return dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(0);
    cout << "Enter a string :";
    string s;
    cin >> s;
    lli n = s.size();
    // init
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            P[{i, j}] = -1;
        }
    }

    lli ans = Partition_Palindrome(s, 0LL, n - 1);
    cout << "The minimum number of partitions required :";
    cout << ans;
    return 0;
}
