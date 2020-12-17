#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
typedef long long int lli;
template <typename T>
map <T,list<T> > makeGraph(lli n,lli m,bool both){
    map <T,list<T> > adj;
    T s,e;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
    return adj;
}
template <typename T>
auto makeGraphWeight(lli n,lli m,bool both){
    map <T,list<T> > adj;
    T s,e;
    lli w;
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
    return adj;
}
template <typename T>
void dfs(T node, map < T,bool > &visited,map <T,list<T> > &adj){
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
bool cycle_helper(lli node,map <lli,bool> &visited,map <lli,list<lli> > &adj,lli parent){
    for(auto k:adj[node]){
        if(visited[k] == true && parent != k)
        // this is the main code -> if you have found a neighbour
        // which is actually visited before and that neighbour
        // the parent in this current call , this means it is
        // a cycle vertex...
            return true;
        if(visited[k]==false){
            visited[k] = true;
            return cycle_helper(k,visited,adj,node);
            // parent is the node as for that only we called
            // the original function
            // 0 -> 1... 0 has called
            // cycle_helper(0,visited,adj,-1)
            // now 1 is unvisited and thus
            // cycle_helper(1,visited,adj,0) is called
            // yes correct
        }
    }
    return false;
}
bool cycle_detect(map <lli,list<lli> > adj){
    map < lli,bool > visited;
    visited[0] = true;
    // we can even implement with a parent array

    return cycle_helper(0,visited,adj,-1);
}
int main(){
    lli n;
    cout<<"No. of vertices :";
    cin>>n;
    cout<<"No. of edges :";
    lli m;
    cin>>m;
    map < lli, list<lli> > adj;
    bool both = true;
    lli s,e;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
    cout<<"Checking for the cycle...";
    bool present = cycle_detect(adj);
    if(present == true)
        cout<<"Cycle is present!";
    else
        cout<<"No cycles";
    return 0;
}
