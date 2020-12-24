#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define mod 1000000007
#define umap unordered_map
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
void makeGraphWeight(lli n,lli m,bool both,umap < T, list< pair<T,lli> > > &adj){
    T s,e;
    lli w;
    for0(m){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
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
// for kruskal's
template <typename T>
class DSU{
    map <T,T> parent;
    map <T,lli> rank;
    public : DSU(lli n){
        for(int i=0;i<n+1;i++){
            parent[i] = -1; // each node is self parent
            rank[i] = 1; // each vertex is in same set
        }
    }
    // make a find function
    T find(T v){
        T temp = v;
        while(parent[temp]!=-1)
            temp = parent[temp];
        if(parent[v]!=-1)
            parent[v] = temp;
        return temp;
    }
    // make a union function
    void Union(T u,T v){
        T p1 = find(u);
        T p2 = find(v);
        if(p1!=p2){
            if(rank[p1] < rank[p2]){
                rank[p2]+= rank[p1];
                parent[p1] = p2;// combine the heads
            }
            else{
                rank[p1]+= rank[p2];
                parent[p2] = p1;
            }
        }
    }
};
bool comp( pair < pi , lli > &a, pair < pi , lli > &b){
    return a.second < b.second;
}
// make a minimal spanning tree for the negated edges
void kruskal_maxsolve(lli n,vector < pair <pi,lli> >  &edges, vector<lli> &order){
    // this function will make a maximal spanning tree for the
    // graph
    sort(all(edges),comp);
    DSU<lli> dsu(n);
    lli u,v,w;
    for(auto k:edges){
        u = k.first.first;
        v = k.first.second;
        w = k.second;
        if(dsu.find(u)!=dsu.find(v)){
            dsu.Union(u,v);
        }
        else{
            order.push_back(w);
        }
    }
}
// corect.... F :o
int main()
{   ios::sync_with_stdio(false);
    in(n);
    in(m);
    in(s);
    lli start,end,weight;
    vector < pair < pi,lli > > edges;
    for0(m){
        cin>>start>>end>>weight;
        edges.push_back({{start,end},-weight});
    }
    // basically make a maximal spanning tree for the graph
    // after that, you get a probable list
    // of edges
    // Now out of those edges, you need to
    // sort them by weight
    // and then keep on picking until you get the edge weights
    vector <lli> order;
    vector <lli> answer;
    kruskal_maxsolve(n,edges,order);
    for(auto k:order){
        answer.push_back(-k);
    }
    sort(all(answer));
    lli count,cost;
    count = cost = 0;
    for(auto k:answer){
        if(k+cost <= s){
            count++;
            cost+= k;
        }
        else
            break;
    }
    cout<<count<<" "<<cost;
    return 0;
}
