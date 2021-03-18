#include<bits/stdc++.h>
using namespace std;
template <typename T>
void BFSshortest(T src, T dest, map <T,list<T> > adj){
    map< T,bool > visited;
    visited[src] = true;
    queue<T> q;
    q.push(src);
    map < T,T > parent;// important
    map < T,int > distance;
    distance[src]= 0;
    parent[src] = src;
    while(!q.empty()){
        T curr = q.front();
        for(auto k: adj[curr]){
            if(visited[k] == false){
                parent[k] = curr;// as soon as you discover
                // mark its parent as the current node.
                visited[k] = true;
                distance[k] = distance[curr] + 1;
                q.push(k);
            }
        }
        q.pop();
    }
    T i = dest;
    int dist = 1;
    while(i!=parent[i]){
        cout<<i<<"->";
        i = parent[i];
        dist++;
    }
    cout<<i;
    cout<<"\nLength is :"<<dist;
    for(auto f:adj){
        T node = f.first;
        int d = distance[node];
        cout<<"Ditance of "<<node<<" from "<<src<<" is "<<d<<endl;
    }
    return;
}
int main(){
    cout<<"Single source shortest path with BFS.\n";
    cout<<"Enter the number of vertices :";
    int n;
    cin>>n;
    cout<<"Enter the number of edges :";
    int E,s,e;
    cin>>E;
    map < int, list<int> > adj;
    // can be unordered too.
    while(E--)
    {
        cout<<"S:";
        cin>>s;
        cout<<"E:";
        cin>>e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    int start,end;
    cout<<"Enter the starting vertex :";
    cin>>start;
    cout<<"Enter the ending vertex :";
    cin>>end;
    cout<<"The shortest path is :";
    BFSshortest(start,end,adj);
    return 0;
}
