#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define mod 1000000007
#define asc_ord_set tree< lli , null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define desc_ord_set tree< lli , null_type, greater<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define key_position(k,o) o.order_of_key(k)
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef unordered_map <lli,lli> umap;
typedef priority_queue<lli> pq;
typedef pair <lli, lli> pi;
bitset<10000000> p;
bool sieve_made = false;
lli fast_power(lli a,lli b)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res*= p;
        p= p*p;
        b= b>>1;
    }
    return res;
}
void sieve()
{   sieve_made=true;
    p[0] = p[1] = 0;
    p[2] = 1;
    for(lli i=4;i<=1000000;i+=2)
        p[i] = 0;
    for(lli i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(lli j=i*i;j<=1000000;j+=i)
                p[j] = 0;
        }
    }
}
bool prime(lli n)
{
    if(sieve_made==true)
    {
        if(n<10000000)
            return (p[n]);
        else{
             for(int i=2;i<=sqrt(n);i++)
                    if(n%i==0) return false;
            return true;
        }
    }
    for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
    return true;
}
map <lli,lli> factor;
void prime_fact(lli n)
{
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                {
                    factor[i]++;
                    n = n/i;
                }
        }
    }
    if(n!=1) factor[n] = 1;
}

template <typename T>
void dfs_topo(T source, map<T,bool> &visited,unordered_map<T,list<T> > &adj,list<T> &answer){
    // visit the source
    visited[source] = true;
    for(auto k:adj[source]){
        if(!visited[k]){
            dfs_topo(k,visited,adj,answer);
        }
    }
    // at this point i have traversed
    // all the dependent children,
    // i can add my current node to the
    // front of my list/ordering
    answer.push_front(source);
}

template <typename T>
void bfs_topo(unordered_map< T,list<T> > &adj,list<T> &answer){
   map<T,int> indeg;
   for(auto k:adj){ // initialise
       indeg[k.first] = 0;
   }
   for(auto k:adj){ // update
       T node = k.first;
       for(auto y:k.second){
           indeg[y]++;
       }
   }

   // code starts
   queue<T> q;
   for(auto k:indeg){
       if(k.second==0)
            q.push(k.first);
        else
            break;
   }
   // got the queue initialised
   while(!q.empty()){

       T curr = q.front();
       for(auto k:adj[curr]){
           indeg[k] -=1;
           if(indeg[k]==0)
                q.push(k);
       }
       answer.push_back(curr);
       q.pop();
   }
   return;
}

template <typename T>
list<T> topological(unordered_map<T,list<T> > &adj){
    list <T> ordering;
    // DFS
    //make a visited array and initialise
    map< T,bool> visited;
    for(auto k:adj){
        T node = k.first;
        visited[node] = false;
    }

    for(auto k:adj){
        T node = k.first;
        if(visited[node] == false)
            dfs_topo(node,visited,adj,ordering);
    }
    // this is gonna be one of the topological
    // ordering for my graph
    // dependencies resolved! :D

    // BFS
    bfs_topo(adj,ordering);

    return ordering;
}
int main()
{   ios::sync_with_stdio(false);
    in(n);
    lli arr[n];
    for0(n)
        cin>>arr[i];
    // first -1 gives the position of the largest number ...

    return 0;
}
