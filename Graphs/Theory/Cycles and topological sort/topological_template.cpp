#include<bits/stdc++.h>
using namespace std;

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
list<T> topological(unordered_map<T,list<T> > &adj){
    // make a visited array and initialise
    map< T,bool> visited;
    for(auto k:adj){
        T node = k.first;
        visited[node] = false;
    }

    list <T> ordering;
    for(auto k:adj){
        T node = k.first;
        if(visited[node] == false)
            dfs_topo(node,visited,adj,ordering);
    }
    // this is gonna be one of the topological
    // ordering for my graph
    // dependencies resolved! :D
    return ordering;
}
int main(){
    ios::sync_with_stdio(0);
    int cases=1;
    int n=-1;
    cin>>n;
    while(n!=-1){
    string c,s,e;
    unordered_map< string, list<string> > adj;
    for(int i=0;i<n;i++)
        {cin>>c;
        adj[c].push_back(c);}
    // this question is simply based on topological
    // sorting and requires its implementation only
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
        {
            cin>>s>>e;
            adj[s].push_back(e);
        }
    list <string> order = topological(adj);
    cout<<"Case #"<<cases<<": Vivek should drink beverages in this order: ";
    int size = order.size();
    int last = size;
    for(auto k:order){
        if(last!=1)
        cout<<k<<" ";
        else
        cout<<k<<".";
        last--;}
    cout<<endl;
    cases++;
    n=-1;
    cin>>n;
    }
    return 0;
}
