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
template <typename T>
void makeGraph(lli n,lli m,bool both,umap<T,list<T> > &adj){
    T s,e;
    for0(i,m){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
}
template <typename T>
void makeGraphWeight(lli n,lli m,bool both,umap < T, list< pair<T,lli> > > &adj){
    T s,e;
    lli w;
    for0(i,m){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
}
template <typename T>
void dfs(T node, map < T,bool > &visited,umap <T,list<T> > &adj){
    visited[node] = true;
    //... something
    for(auto k:adj[node])
    {
        if(visited[k] == false){
            dfs(k,visited,adj);
        }
    }
    return;
}
template <typename T>
void DFS(T source,umap <T,list<T> > &adj){
    map< T,bool > visited;
    visited[source] = true;
    //...something
    dfs(source,visited,adj);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    // code up....
    return 0;
}