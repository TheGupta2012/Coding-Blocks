#include<bits/stdc++.h>
using namespace std;
void BFS (int n, int v, vector <int> adj[]){
    bool visited[n+1]={false};
    queue <int> q;
    visited[v] = true;
    // breadth first from starting vertex s.
    q.push(v);
    while(!q.empty()){
            int curr = q.front();
            for(auto k:adj[curr])
                {
                    if(visited[k]==false)
                        {q.push(k);
                        visited[k] = true;}
                }
            cout<<curr<<" ";
            q.pop();
    }
    return ;
}
template <typename T> // important for a generic BFS
// algorithm which is independent of the type of
// vertex name.
void GeneralBFS(int n,T v, map< T, list<T> > adj){
    map < T,bool > visited;
    visited[v] = true;// important
    queue<T> q;
    q.push(v);
    while(!q.empty()){
        T curr = q.front();
        for(auto k:adj[curr]){
            if(visited[k]== false){
                visited[k] = true;
                q.push(k);
            }
        }
        cout<<curr<<" ";
        q.pop();
    }
    return ;
}
int main(){

    cout<<"BREADTH FIRST TRAVERSAL.\n";
    cout<<"Enter no. of vertices :";
    int n,s,e;
    cin>>n;
    map<int,list<int> > adj;
    cout<<"Enter number of edges :";
    int E;
    cin>>E;
    while(E--){
        cout<<"Start : ";
        cin>>s;
        cout<<"End : ";
        cin>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    cout<<"Enter the starting vertex :";
    int v;
    cin>>v;
    cout<<"\nYour breadth first search from "<<v<<" is :\n";
    GeneralBFS(n,v,adj);
    return 0;
}
