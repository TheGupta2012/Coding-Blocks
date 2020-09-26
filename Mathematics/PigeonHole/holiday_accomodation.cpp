#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli total;
// DFS signature is just returning the size of the subgraph for the node at which you are at
lli DFS(lli n,lli node,bool *visited,lli *count,vector< pair<lli,lli> > adj[])
{
    // mark the node as visited
    visited[node] = true;
    count[node] = 1;
    lli v,w;
    for(auto k:adj[node])
    {
        v = k.first;
        w = k.second;
        if(!visited[v]) // at this point i need to visit the node v and update the current
                        // node's count by the size of the count of the node v
        {
            count[node]+= DFS(n,v,visited,count,adj);
            // at this point i would have returned from visiting the node v.
            // Let us now add the edge contribution to the total
            total += (2*min(count[v],n-count[v])*w);
        }
    }
    return count[node]; // return my current node's subgraph total
}
int main()
{   ios::sync_with_stdio(0);
    lli t;
    cin>>t;
    lli m = 1;
    while(t--)
    {   total = 0;
        lli n,s,e,w;
        cin>>n;
        vector< pair< lli,lli> > adj[n+1];
        for(int i=0;i<n-1;i++)
        {
            cin>>s>>e>>w;
            adj[s].push_back({e,w});
            adj[e].push_back({s,w});
        }
        // graph is created at this point
        bool visited[n+1] = {false};
        lli count[n+1] = {0};
        // no vertex visited currently
        // let us keep a global total which takes cares of the
        // total value
        lli size = DFS(n,1,visited,count,adj);
        cout<<"Case #"<<m<<": "<<total<<endl;
        m++;
    }
    return 0;
}
