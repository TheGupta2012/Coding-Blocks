#include<bits/stdc++.h>
using namespace std;
template <typename T>
void DFS_real(T source,int n,map <T,bool> &visited,unordered_map <T, list<pair<T,int> > > adj){
    // making the DFS call for a custom typeT
    for(auto k:adj[source]){
        T vertex = k.first;
        if(visited[vertex]==false)
            {
                visited[vertex] = true;
                cout<<vertex<<" ";
                DFS_real(vertex,n,visited,adj);
            }
    }
    return;
}
template <typename T>
void DFS(T source,int n,unordered_map <T, list<pair<T,int> > > adj){
    map < T,bool > visited;
    cout<<"DEPTH FIRST SEARCH...\n";
    visited[source] = true;
    cout<<source<<" ";
    DFS_real(source,n,visited,adj);
    cout<<endl;
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cout<<"Enter the number of vertices :";
    int v;
    cin>>v;
    cout<<"Enter the edges one by one :";
    cout<<"\nSYNTAX : S, E, W(S=-1 for breaking)\n";
    string s,e;
    int w;
    unordered_map < string , list < pair <string,int> > > adj;
    int count = 1;
    do{ cout<<"Edge "<<count<<":";
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        adj[e].push_back({s,w});
        count++;
    }while(s!="-1");
    cout<<"Enter the source vertex :";
    string starter;
    cin>>starter;
    DFS(starter,v,adj);
    return 0;
}
