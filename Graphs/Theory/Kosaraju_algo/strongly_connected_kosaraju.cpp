#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void dfs(int src,bool *visited, vector<int> adj[],list<int> &order){
    visited[src] = true;
    for(auto k:adj[src]){
        if(visited[k] == false){
            dfs(k,visited,adj,order);
        }
    }
    // at this point i finish for the source and go back
    order.push_back(src);
    return;
}
list<int> dfs_finish(int v,vector<int> adj[]){
    bool visited[v+1] = {false};
    list <int> order;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
                dfs(i,visited,adj,order);
            }
        }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            order.push_back(i);
            // these correspond to the vertices which were
            // not connected to any other vertex.
        }
    }
    return order;
}
void KOSARAJU(int v,vector<int> adj[],vector<int> reverse[]){
    // First, get the ordering
    list <int> order = dfs_finish(v,adj);
    cout<<"Ordering is :";
    for(auto k:order)
        cout<<k<<" ";
    cout<<endl;
    // Second, reverse the graph, done already

    // Third, start making dfs call from the ordering
    int n = order.size();
    bool visited[v+1] = {false}; // again make visited array
    int count = 1;
    map<int, list<int> > components;
    for(auto it = order.rbegin();it!=order.rend();it++){
        int node = *it;
        if(visited[node] == false){
            // a probable connected component
            dfs(node,visited,reverse,components[count]);
            count++;
        }
    }
    for(auto k:components){
        cout<<k.first<<":";
        for(auto j:k.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return ;
}
// correct :D
int main(){
    // FINDING the sizes and elements of ALL CONNECTED
    // components
    // 1. Do a dfs and get the ordering in increasing order
    // of finishing times
    // 2. Reverse the graph
    // 3. Call dfs again on the reverse graph with the
    // vertices from the ordering .
    cout<<"KOSARAJU'S Algorithm to find all connected components in directed graph\n";
    cout<<"Enter number of vertices :";
    int v;
    cin>>v;
    cout<<"Enter number of edges :";
    int edges;
    cin>>edges;
    cout<<"Enter edges (S E)\n";
    int start,end;
    vector < int > adj[v+1];
    vector < int > reverse[v+1];
    while(edges--){
        cin>>start>>end;
        adj[start].push_back(end);
        reverse[end].push_back(start);
    }
    cout<<"Finding out the connected components ....\n";
    _sleep(1000);
    KOSARAJU(v,adj,reverse);

    return 0;
}
