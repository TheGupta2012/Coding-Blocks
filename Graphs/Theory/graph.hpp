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
template <typename T>
// DSU<lli> dsu(v); -> for initialising...
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
