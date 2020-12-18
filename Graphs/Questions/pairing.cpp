#include<bits/stdc++.h>
#include<unordered_map>
#define for0(m) for(lli i=0;i<m;i++)
#define umap unordered_map
using namespace std;
typedef long long int lli;
// correct ...
template <typename T>
void makeGraph(lli n,lli m,bool both, umap <T,list<T> > &adj){
    T s,e;
    for0(m){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
    return;
}
template <typename T>
lli dfs(T node, map < T,bool > &visited,umap <T,list<T> > &adj){
    visited[node] = true;
    //... something
    lli size = 1;
    for(auto k:adj[node])
    {
        if(visited[k] == false){
            size += dfs(k,visited,adj);
        }
    }
    return size;
}
template <typename T>
lli DFS(lli n,umap <T,list<T> > &adj){
    map < T,bool > visited;
    lli ans = n*(n-1)/2 ;
    lli c;
    for(auto k: adj){
        T curr = k.first;
        if(visited[curr]==false){
            c = dfs(curr,visited,adj);
            ans -= c*(c-1)/2;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    lli n,m;
    cin>>n>>m;
    umap< lli, list<lli> > adj;
    makeGraph(n,m,true,adj);
    for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==0)
                adj[i].push_back(i);
        }
    // answer-> nC2 - (c1C2 + c2C2 + c3C2...)
    // where ci is the size of the ith connected component
    lli ans = DFS(n,adj);
    cout<<ans;
    return 0;
}
