#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
typedef long long int lli;
template <typename T>
void makeGraph(lli n,lli m,bool both,umap <T,list<pair<T,lli> > > &adj){
    T s,e;
    lli w;
    for(int i = 0 ; i < m;i++){
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
        if(both==true)
            adj[e].push_back({s,w});
    }
}
typedef pair<lli,lli> pi;
lli prims(lli n,umap<lli, list<pi> > adj){
    // store {w,y} in your priority queue
    // so that min heap is made by default
    priority_queue < pi, vector<pi>, greater<pi> > Q;
    // You need to make an MST set
    // true is visited array means vertex in
    // MST Set
    map<lli,bool> visited;
    // just push the first node with a weight value = 0.
    Q.push({0,0});
    lli ans = 0;
    lli v,w,weight,vertex;
    map < lli,bool > MST_set;
    while(!Q.empty()){
        // get the minimum weight edge
        pi edge= Q.top();
        v = edge.second;
        w = edge.first;
        Q.pop();
        if(MST_set[v] == false){
            // means v is not in mst set
            ans+= w;
            cout<<"Edge with end "<<v<<" and weight "<<w<<" included\n";
            MST_set[v] = true;
            for(auto k:adj[v]){
                vertex = k.first;
                weight = k.second;
                    // note queue is build reversed as
                    // we want default building of the
                    // queue
                if(visited[vertex]==false)
                    Q.push({weight,vertex});
            }
        }

    }
    return ans;
}
//correct...
int main(){
    ios::sync_with_stdio(0);
    lli n,m;
    cout<<"Enter the number of vertices :";
    cin>>n;
    cout<<"Enter the number of edges :";
    cin>>m;
    umap<lli,list<pair<lli,lli> > > adj;
    makeGraph<lli>(n,m,true,adj);
    cout<<prims(n,adj);
    return 0;
}
