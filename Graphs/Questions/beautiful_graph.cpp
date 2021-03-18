#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define mod 998244353
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
            res = (res*p)%mod;
        p= (p*p)%mod;
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
lli type1,type2;
bool canPlace;
void cyclePresent(lli src,bool *visited,vi adj[],lli parent,lli *len,int type){
    // visit src
    visited[src] = true;
    if(type==1){
        type1++;
        type = 2;
    }
    else{
        type2++;
        type = 1;
    }
    for(auto k:adj[src]){
        if(visited[k]==false){
            *len = *len + 1;
            cyclePresent(k,visited,adj,src,len,type);
            if(canPlace==false)
                return;
        }
        else{
            if( k!= parent && (*len)%2==1 && *len>1){
                {canPlace = false;
                cout<<"Yes cycle of length "<<*len<<"with "<<k<<" as end and "<<src<<" as its parent\n";
                return;}
            }
        }
    }
    return;
}
lli bipartite(lli n,vi adj[]){
    bool visited[n+1] = {false};
    lli total = 1;
    for(lli i=1;i<=n;i++){
        if(visited[i]==false){
        lli len = 1;
        type1 = type2 = 0;
        canPlace = true;
        cyclePresent(i,visited,adj,-1LL,&len,1);
        cout<<"Type 1 "<<type1;
        cout<<"\nType 2 "<<type2<<endl;
        if(canPlace == true){
            total = (total*(fast_power(2LL,type1) + fast_power(2LL,type2)))%mod;
        }
        else{
            return 0; // agar ek mei nhi rkh skte to graph mei nhi rkh sktes
        }
    }
    }
    return total;
}
int main()
{   ios::sync_with_stdio(false);
    in(t);
    while(t--){
        in(n);
        in(m);
        vi adj[n+1];
        for0(m){
            in(u);
            in(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // if no odd cycle, answer ->
        // ans for connected comp1 * ans for connected comp2 * ans for connected comp3 * ....
        lli ans = bipartite(n,adj);
            // do more...
            // basically
            // if a vertex is painted even, other has to be has to be painted odd
            // wait... that's like coloring
            // where did i study two coloring problemt?
            // ohh! bipartite
            // what additional thing here? COUNT how many vertices of color 1
            // and how many of color 2
            // Now, for each vertex, if you chose let us say a C1 colored vertex
            // and placed an even number there, then all the vertices connected  to
            // that C1 colored vertex must have been painted with different color

            // So, all the different colored(colored as C2) vertices must contain odd number
            // and this argument can be extended to say that if we initially place a number
            // with even parity in a color c, that color c will always contain a number with
            // the same parity

            // Odd ki to we have 2 choices ...
            // and even ki only 1 choice.

            // So, if we initially assgin a color to an even number, then
            // it will always contain an even number because of the bi partiteness and the
            // question constraint.
            // similarly, the other color will always contain an odd number
            // so , choose C1 to contain an odd number and C2 to an even number
            // let us have C1 vertices of color c1 and C2 vertices of color c2
            // answer for it is 2 ^(C1). 1 ^(C2) ( C1 has odd number(2) choices )

            // but let us assign C1 an even number now
            // so answer is 2^(C2) . 1^(C1)
            // total = ans1 + ans2
            // final ans = final*(total) // for all the connected components
            cout<<ans<<endl;
    }
    return 0;
}
