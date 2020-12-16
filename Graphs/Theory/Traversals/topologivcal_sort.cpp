#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
void dfs(int source, umap <int,list<int> > &adj,map<int,bool> &visited,list<int> &ans){
    visited[source] = true;
    // come to the node and mark the node as visited
    for(auto k:adj[source]){
        if(!visited[k])
        {
            dfs(k,adj,visited,ans);
        }
    }
    // at the point when we have visited all the children
    // of the node, push the node to the front as you have resolced the
    // dependent nodes for source
    ans.push_front(source);
}
list <int> topological(int v,umap <int,list<int> > &adj){
    // start a dfs
    map< int,bool> visited;
    list<int> answer;
    for(auto k:adj){
        int node = k.first;
        if(visited[node]==false){
            dfs(node,adj,visited,answer);
        }
    }
    return answer;
}
int main(){
    cout<<"TOPOLOGICAL SORTING...";
    cout<<"No. of vertices :";
    int v,e,start,end;
    cin>>v;
    cout<<"No. of edges :";
    cin>>e;
    umap<int, list<int> > adj;
    while(e--){
        cin>>start>>end;
        adj[start].push_back(end);
    }
    list <int> order= topological(v,adj);
    for(auto k:order)
        cout<<k<<"->";
    return 0;
}
