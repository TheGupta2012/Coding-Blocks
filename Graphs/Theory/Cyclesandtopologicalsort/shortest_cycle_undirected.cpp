#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
lli cycleBFS(lli src, vi adj[]){
    // now mark the src as visited
    cout<<"Source is "<<src<<endl;
    map<lli,bool> visited;
    map<lli,lli> parent;
    map<lli,lli> dist;
    parent[src] = -1;
    dist[src] = 0;
    lli ans = 100;
    queue<lli> q;
    q.push(src);
    while(!q.empty()){
        lli curr = q.front(); // get the current vertex
        visited[curr] = true; //visit it
        for(auto k:adj[curr]){
            if(visited[k]==false){
                // visiting a normal unvisited vertex
                parent[k] = curr;
                dist[k] = dist[curr] + 1;
                q.push(k);
            }
            else{
                // -> only checks here, no manipulations
                // visiting an already visited vertex
                // if back edge found (edge to visited vertex which is not parent)
                if(k!=parent[curr]){
                    // a probable cycle in our graph , maybe right, maybe wrong,
                    lli len = dist[k] + dist[curr] + 1;
                    cout<<"Cycle detected with length -> "<<len<<endl;
                    cout<<"Back edge from "<<curr<<" to "<<k<<endl;
                    ans= min(ans,len);
                }
            }
        }
        q.pop();
    }
    return ans;
}
lli shortestCycle(lli n,vi adj[]){
    // for each vertex, call a bfs
    lli ans = 100;
    for(int i=1;i<=n;i++){
        ans = min(ans,cycleBFS(i,adj));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int v,e;
    cout<<"SHORTEST CYCLE LENGTH....";
    cout<<"\nEnter number of vertices :";
    cin>>v;
    cout<<"Enter the number of edges :";
    cin>>e;
    lli start,end;
    cout<<"Enter edges...\n";
    vi adj[v+1];
    while(e--){
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    lli ans = shortestCycle(v,adj);
    cout<<"Shortest cycle length is :"<<ans;
    return 0;
}
