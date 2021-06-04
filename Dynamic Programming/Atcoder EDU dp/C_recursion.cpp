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
vi a,b,c;

lli solve(lli n, lli day,char last){
    // only one day 
    if(n == 1){
        return max(a[0],max(b[0],c[0]));
    }
    // day is one based...
    // now on last day, and atleast 2 days.. 
    if(day == n){
        if(last == 'a'){
            return max(b[n-1],c[n-1]);
        }
        if(last == 'b'){
            return max(a[n-1],c[n-1]);
        }
        if(last == 'c'){
            return max(a[n-1],b[n-1]);
        }
    }
    // works... memoize
    // main code 
    if(day == 1LL){
        // first day has 3 choices, 
        lli A = a[day-1] + solve(n,day+1,'a');
        lli B = b[day-1] + solve(n,day+1,'b');
        lli C = c[day-1] + solve(n,day+1,'c');

        return max(A,max(B,C));

    }
    else{
        if(last == 'a'){
            return max(b[day-1] + solve(n,day+1,'b'),c[day-1] + solve(n,day+1,'c'));
        }
        else if(last == 'b'){
            return max(a[day-1] + solve(n,day+1,'a'),c[day-1] + solve(n,day+1,'c'));

        }
        else{
            return max(b[day-1] + solve(n,day+1,'b'),a[day-1] + solve(n,day+1,'a'));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    in(n);
   
    a.reserve(n), b.reserve(n), c.reserve(n);
    for0(i,n){
        in(e1);
        a.pb(e1);
        in(e2);
        b.pb(e2);
        in(e3);
        c.pb(e3);
    }

    //init dp 

    // base case 


    // find maximum possible total points 
    // note that other than the first day, 
    // he has only two choices 

    // start with A on day 1
    //or start with B on day 1
    // or start with C on day 1.

    // Now, take the maximum of the total points 
    // you can gain from those three .
    lli ans = solve(n,1LL,'f');
    cout<<ans;
    return 0;
}