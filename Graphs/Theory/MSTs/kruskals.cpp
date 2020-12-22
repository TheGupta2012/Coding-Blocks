#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
template <typename T>
// DSU<lli> dsu(v); -> for initialising...
class DSU{
    map <T,T> parent;
    map <T,lli> rank;
    public : DSU(lli n){
        for(int i=0;i<n+1;i++){
            parent[i] = -1; // each node is self parent
            rank[i] = 1; // each vertex is in same set
        }
    }
    // make a find function
    T find(T v){
        T temp = v;
        while(parent[temp]!=-1)
            temp = parent[temp];
        if(parent[v]!=-1)
            parent[v] = temp;
        return temp;
    }
    // make a union function
    void Union(T u,T v){
        T p1 = find(u);
        T p2 = find(v);
        if(p1!=p2){
            if(rank[p1] < rank[p2]){
                rank[p2]+= rank[p1];
                parent[p1] = p2;// combine the heads
            }
            else{
                rank[p1]+= rank[p2];
                parent[p2] = p1;
            }
        }
    }
};
bool comp(pair< pair<lli,lli> , lli > &a,pair< pair<lli,lli> , lli > &b){
    return a.second < b.second;
}
class Graph{
    lli v;
    vector< pair< pair<lli,lli> , lli > > edges;
    public : Graph(lli n,lli e){
        this->v = n;
        lli start,weight,end;
        cout<<"Enter edges (S,E,W):\n";
        for(int i=0;i<e;i++){
            cin>>start>>end>>weight;
            edges.push_back({{start,end},weight});
        }
    }

    lli MST_kruskal(){
        sort(edges.begin(),edges.end(),comp);
        //Initialise
        DSU<lli> dsu(v);
        lli answer = 0;
        // edges have been sorted
        lli u,v,w;
        cout<<"Your graph is :\n";
        for(auto k: edges){
            u = k.first.first;
            v = k.first.second;
            w = k.second;
            if(dsu.find(u)!= dsu.find(v)){
                cout<<u<<","<<v<<":"<<w<<endl;
                dsu.Union(u,v);
                answer+= w;
            }
        }
        return answer;
    }
};
// correct ...
int main(){
    ios::sync_with_stdio(0);
    cout<<"KRUSKAL's algorithm for MST\n";
    lli n,e;
    cout<<"Enter number of vertices :";
    cin>>n;
    cout<<"Enter number of edges :";
    cin>>e;
    Graph g(n,e);
    cout<<g.MST_kruskal();
    return 0;
}
