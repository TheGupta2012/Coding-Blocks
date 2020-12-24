#define umap unordered_map
/* For appending to the normal template...*/
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
/*
Disjoint Set Union...
*/
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
/* topological sort template */
/* Returns topological order for graph in a LIST for the graph
given as umap */
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
