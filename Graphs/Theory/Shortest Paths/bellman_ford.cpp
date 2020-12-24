#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pi;
void BELLMAN_FORD(lli src,lli v,vector < pair< pi, lli > > edges){
    //1. initialising the distance map
    map <lli,lli> D;
    for(int i=1;i<=v;i++){
        D[i] = 1e10;
    }
    map <lli,lli> parent;
    parent[src] = -1;
    lli s,e,w,d,node;
    D[src] = 0;
    for(int i=0;i<v-1;i++){
        // 2. relax all edges
        for(auto k:edges){
            s = k.first.first;
            e = k.first.second;
            w = k.second;
            if(D[s] == 1e10)
                continue;
            else{
                if(D[e] > D[s] + w){
                    parent[e] = s;
                    D[e] = D[s] + w;
                }
            }
        }
    }
    // 3. checking once, does the graph contain a -ve weight
    // cycle.
    for(auto k:edges){
        s = k.first.first;
        e = k.first.second;
        w = k.second;
        if(D[s] == 1e10)
            continue;
        else{
            if(D[e] > D[s] + w){
                cout<<"\nNegative weight cycle present.";
                cout<<"\nShortest paths impossible.";
                return;
            }
        }
    }
    cout<<"All the distances are :\n";
    for(auto k:D){
        node = k.first;
        d = k.second;
        if(d==1e10)
            cout<<node<<": inf \n";
        else
            cout<<node<<":"<<d<<"\n";
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"BELLMAN FORD ALGORITHM...";
    lli n,m,start,end,weight;
    cout<<"\nEnter the number of vertices :";
    cin>>n;
    cout<<"Enter the number of edges :";
    cin>>m;
    cout<<"Enter edges (S,E,W)\n";
    vector < pair< pi, lli > > edges;
    for(int i=0;i<m;i++)
    {
        cin>>start>>end>>weight;
        edges.push_back({{start,end},weight});
    }
    cout<<"Enter the source vertex :";
    lli s;
    cin>>s;
    BELLMAN_FORD(s,n,edges);
    return 0;
}
