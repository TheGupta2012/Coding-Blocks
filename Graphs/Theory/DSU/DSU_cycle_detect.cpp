#include<bits/stdc++.h>
#define for0(x) for(lli i=0;i<x;i++)
#define umap unordered_map
using namespace std;
typedef long long int lli;
template <typename T>
T Find(T u, map<T,T> &parent){
    while(parent[u]!=u)
        u = parent[u];
    return u;
}
template <typename T>
bool Union(T u, T v, map<T,T> &parent){
    T p1 = Find(u,parent);
    T p2 = Find(v,parent);
    if(p1!=p2){
        // if different components then return okay
        parent[p2] = p1;
        return true;
    }
    else{
        // else you have a cycle in your graph...
        cout<<u<<" and "<<v<<" are in the same set!\n";
        return false;
    }
}
template <typename T>
bool checkCycle(umap <T,list<T>> &adj,list<pair<T,T> > &edges){
    map<T,T> parent;
    for(auto k:edges)
        parent[k.first] = k.first;
    for(auto k:edges)
    {
        T u = k.first;
        T v = k.second;
        if(Union(u,v,parent)==true)
            continue;
        else
            return true;
    }
    return false;
}
template <typename T>
void makeGraph(lli n,lli m,bool both, umap<T,list<T>> &adj,list<pair<T,T> > &edges){
    T s,e;
    for0(m){
        cin>>s>>e;
        adj[s].push_back(e);
        edges.push_back({s,e});
        if(both==true)
            adj[e].push_back(s);
    }
}
int main(){
    cout<<"CYCLE CHECK USING DSU...\n";
    cout<<"Enter total vertices :";
    lli n;
    cin>>n;
    cout<<"Enter total edges :";
    lli e;
    cin>>e;
    umap <lli,list<lli>> adj;
    list < pair<lli,lli> > edges;
    makeGraph(n,e,true,adj,edges);
    cout<<"Checking for cycles....\n";
    if(checkCycle(adj,edges)==true){
        cout<<"Contains a cycle!.";
    }
    else{
        cout<<"No cycle...";
    }
}
