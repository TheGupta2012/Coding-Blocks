#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
template <typename T>
void makeGraph(int n,int m,bool both,umap <T,list<T> > &adj){
    T s,e;
    for(int i=0;i<m;i++){
        cout<<"Edge "<<i+1<<":";
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
}
template <typename T>
bool dfs_stack(T source, map< T,bool > &visited,map<T,bool> &call_stack, umap <T,list<T> > &adj){

    visited[source] = true;
    call_stack[source] = true;
    // recursive calls
    for(auto k:adj[source]){
        if(visited[k]==false){
            bool flag = dfs_stack(k,visited,call_stack,adj);
            if(flag==true)
                return true;
        }
        else{
            if(call_stack[k]==true){
                //cout<<"Cycle found!";
                return true;
            }
        }
    }
    // leaving the node -> important
    call_stack[source] = false;
    return false;
}
// correct :D...
template <typename T>
bool cycleDetect(umap <T,list<T> > &adj){
    map < T,bool > visited;
    map<T,bool> call_stack;
    for(auto k:adj){
        visited[k.first] = false;
    }
    bool flag = false;
    // basic thought -> if the visited vertex is in the
    // call stack then there is a cycle , else no :D
    for(auto k: adj){
        T curr = k.first;
        for(auto k:adj){
            call_stack[k.first]  = false;
        }
        if(visited[curr] == false){
            flag = dfs_stack(curr,call_stack,visited,adj);
            if(flag==true)
                return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    cout<<"Enter the number of vertices and edges:";
    cin>>n>>m;
    bool both = false;
    umap < int,list<int> > adj;
    makeGraph(n,m,both,adj);
    bool flag = cycleDetect(adj);
    if(flag==false)
        cout<<"No cycle in your graph...";
    else
        cout<<"Cycle found!";
    return 0;
}
