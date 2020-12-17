#include<bits/stdc++.h>
using namespace std;
void dfs(int source, map < int,bool > &visited, unordered_map < int,list<int> > adj){
    visited[source] = true;
    cout<<source<<" ";
    for(auto k :adj[source]){
        if(visited[k] == false)
            dfs(k,visited,adj);
    }
    return;
}
void components(int n,unordered_map < int,list<int> > adj){
    map < int,bool > visited;
    for(auto k:adj){
        visited[k.first] = false;
    }
    int number = 1;
    for(auto k:adj){
        int u = k.first;
        if(visited[u] == false) // univisted node
        {
            cout<<"Component "<<number<<": ";
            dfs(u,visited,adj);
            number+=1;
            cout<<endl;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    int n,s,e;
    cin>>n;
    cout<<"Edges :(S,E), (-1,-1 for break)\n";
    unordered_map < int, list<int> > adj;
    int count =0;
    while(true){
        cin>>s>>e;
        if(s==-1)
            break;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    components(n,adj);
    return 0;
}
