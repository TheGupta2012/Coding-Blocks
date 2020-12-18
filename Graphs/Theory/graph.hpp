#define umap unordered_map
template <typename T>
void makeGraph(lli n,lli m,bool both,umap<T,list<T> > &adj){
    T s,e;
    for0(m){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
}
template <typename T>
umap < T, list < pair<T,lli > > > makeGraphWeight(lli n,lli m,bool both){
    umap <T,list<T> > adj;
    T s,e;
    lli w;
    for0(m){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
    return adj;
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
