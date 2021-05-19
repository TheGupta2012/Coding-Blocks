#include <bits/stdc++.h>
#include <cmath>
#define pb(x) push_back(x)
#define umap unordered_map
#define print_arr_like(x) \
    for (auto k : x)      \
    cout << k << " "
#define print_map_like(x) \
    for (auto k : x)      \
    cout << k.first << ":" << k.second << "\n"
#define make_lower(s) transform(all(s), s.begin(), ::tolower)
#define make_upper(s) transform(all(s), s.begin(), ::toupper)
#define tr(v, it) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define in(x) \
    lli x;    \
    cin >> x
#define all(v) v.begin(), v.end()
#define for0(i, n) for (lli i = 0; i < n; i++)
#define for1(i, n) for (lli i = 1; i <= n; i++)
#define mod 1000000007
#define get_bits(x) __builtin_popcountll(x)
#define asc_ord_set tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
#define desc_ord_set tree<lli, null_type, greater<lli>, rb_tree_tag, tree_order_statistics_node_update>
#define key_position(k, o) o.order_of_key(k)
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef priority_queue<lli> max_pq;
typedef priority_queue<lli, vi, greater<lli>> min_pq;
typedef pair<lli, lli> pi;
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{
    lli g = gcd(a, b);
    return (a * b) / g;
}
lli fast_power(lli a, lli b)
{
    lli p = a;
    lli res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= p;
        p = p * p;
        b = b >> 1;
    }
    return res;
}
// correct
int dp[105][105];

int LCS(string x, string y, int n, int m)
{
    // init the DP
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        { // this is us using the base condition of the
            // the RECURSION to init the dp
            if (i == 0 || j == 0)
                dp[i][j] = 0;
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

            if (x[i - 1] == y[j - 1])
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
int MinDelsNeeded(string x, string y, int n, int m)
{
    return n + m - 2 * LCS(x, y, n, m);
}
int main()
{
    ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    string x, y;
    cout << "Enter the strings :\n";
    cout << "String 1 :";
    cin >> x;
    cout << "String 2 :";
    cin >> y;
    int n = x.size(), m = y.size();
    cout << "Minimum deletions needed to convert string x into y is :";
    cout << MinDelsNeeded(x, y, n, m);
    return 0;
}