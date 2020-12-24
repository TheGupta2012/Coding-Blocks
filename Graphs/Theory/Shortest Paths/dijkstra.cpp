#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pi;
template <typename T>
void makeGraphWeight(lli n,lli m,bool both,umap<T,list<pair<T,lli> > >&adj){
    T s,e;
    lli w;
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
}
// to - do...
void DIJKSTRA(lli src,lli v,umap< lli, list<pi> > adj){
    map< lli,lli > D;
    // 1. initialising the distance array ...
    bool visited[v+1];
    visited[0]= 0;
    set < pi > Q;
    for(int i=1;i<=v;i++)
        {D[i] = 1e12;
        visited[i] = false;
        }
    // 2. Make the distance of src as 0
    // and include it in the current graph
    D[src] = 0;
    visited[src]  = 1;
    Q.insert({0,src});
    lli d,u;
    while(!Q.empty()){
        // 3. choose the vertex with the least
        // current distance and which is not yet visited .
        auto A = (*Q.begin());
        // the minimum distance vertex
        d = A.first;
        u = A.second;
        visited[u] = true;
        Q.erase(Q.begin());

        for(auto i:adj[u]){
            // node -> destination
            // weight -> weight of edge
            lli node,weight;
            node = i.first;
            weight = i.second;
            if(visited[node]== false)
            {
            // d -> the distance of the parent node...
            if(D[node] > d + weight){
                // in set updation of particular node
                // not possible , remove old pair
                // and then remove
                auto f = Q.find({D[node] , node});
                if(f!=Q.end()) // most important steppppp!...
                    Q.erase(f);
                // update distance and insert
                D[node] = d + weight;
                Q.insert({D[node] , node});
                }
            }
        }
    }
    for(auto k:D){
        if(k.first==src)
            continue;
        else
            cout<<k.second<<" ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        umap < lli, list<pi> > adj;
        makeGraphWeight<lli>(n,m,true,adj);
        lli s;
        cin>>s;
        DIJKSTRA(s,n,adj);
    }
}
