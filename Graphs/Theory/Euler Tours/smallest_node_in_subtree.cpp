#include<bits/stdc++.h>
#define for0(m) for(lli i=0;i<m;i++)
using namespace std;
typedef long long int lli;
#define umap unordered_map
/* For appending to the normal template...*/
template <typename T>
void makeGraph(lli n,lli m,bool both,umap<T,list<T> > &adj){
    T s,e;
    for0(m){
        cin>>s>>e;
        adj[s].push_back(e);
        if(both==true)
            adj[e].push_back(s);
    }
}
lli dp[100000];
// returns the minimum value in subtree of
// src...
lli min_subtree(lli src,map<lli,bool> &visited, umap<lli,list<lli> > &adj){
    visited[src] = true;
    dp[src] = src;// initialise
    for(auto k:adj[src]){
        if(visited[k]==false){
            // the value is min of dp, min_subtree of k.
            // FIRST calculate dp and then do the minimum operation...
            if(dp[k]==1e10)
                 dp[k] = min_subtree(k,visited,adj);
            dp[src] = min(dp[src],dp[k]);
        }
    }
    return dp[src];
}
void solveMinimum(umap <lli,list<lli> > &adj){
    map <lli,bool> visited;
    // recurrence is -> dp[i] = min(i,dp[j]) for j in adj[i]
    dp[1] = min_subtree(1LL,visited,adj);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    //init
    for0(10000){
        dp[i]=1e10;
    }
    lli n,m;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter total edges:";
    cin>>m;
    umap <lli,list<lli> > adj;
    makeGraph<lli>(n,m,true,adj);
    // assuming tree rooted at 1 always...
    solveMinimum(adj);
    cout<<"Enter number of queries :";
    lli q;
    cin>>q;
    while(q--){
        cout<<"\nEnter vertex :";
        lli v;
        cin>>v;
        cout<<"Minium node is "<<dp[v];
    }
    return 0;
}
