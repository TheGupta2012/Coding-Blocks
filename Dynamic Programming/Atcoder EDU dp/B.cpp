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
lli solve(lli i, lli n, lli k, lli *arr)
{   if(n == 2)
        return abs(arr[0] - arr[1]);
    // think of the base case
    lli dp[n];
    memset(dp,0,sizeof(dp));

    // dp[i] represents the minimum cost we would require to 
    // reach from i to the last element

    // init 
    dp[n-1] = 0LL;
    dp[n-2] = abs(arr[n-1] - arr[n-2]);

    //code...
    lli curr_ans;
    for(int i=n-3;i>=0;i--){
        curr_ans = 1e16;
        for(int j=1;j<=k && i+j<n;j++){
            curr_ans = min(curr_ans, abs(arr[i] - arr[i+j]) + dp[i+j]);
        } 
        dp[i] = curr_ans;
    }

    return dp[0];
}
int main()
{
    ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    in(n);
    in(k);
    lli arr[n];

    for0(i, n)
        cin >> arr[i];

    // okay, the frog can jump with jumps
    // of 1 or 2
    lli ans = solve(0, n, k, arr);

    cout <<ans;
    
    return 0;
}