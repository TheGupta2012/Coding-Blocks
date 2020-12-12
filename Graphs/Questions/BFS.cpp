#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void BFS(lli s,lli n,const vector<lli> adj[]){
    bool visited[n+1] = {false};
    lli dist[n+1];
    for(int i=0;i<=n;i++)
        dist[i] = 0;
    queue <lli> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        lli curr = q.front();
        for(auto h:adj[curr]){
            if(visited[h]==false){
                q.push(h);
                visited[h] = true;
                dist[h] = dist[curr] + 1;
            }
        }
        q.pop();
    }
    for(lli i=1;i<=n;i++){
        if(dist[i]==0){
            if(i==s)
                continue;
            else
                cout<<-1<<" ";
        }
        else
            cout<<dist[i]*6<<" ";
    }
    cout<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    lli q;
    cin>>q;
    while(q--){
        lli n,m,s,e,start;
        cin>>n>>m;
        vector <lli> adj[n+1];
        while(m--){
            cin>>s>>e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        cin>>start;
        BFS(start,n,adj);
    }
    return 0;
}
