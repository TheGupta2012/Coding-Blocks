#include<bits/stdc++.h>
#define for0(m) for(lli i=0;i<m;i++)
#define umap unordered_map
using namespace std;
typedef long long int lli;
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
map<lli,lli> in,out;
void euler_tour(lli src,map<lli,bool> &visited, lli *time, umap<lli, list<lli> > &adj){
    visited[src] = true;
    in[src] = *time + 1;
    *time = *time + 1; // incremented only when entering a node.
    for(auto k:adj[src]){
        if(visited[k]==false)
            euler_tour(k,visited,time,adj);
    }
    out[src] = *time;
    return;
}
void timings(lli n,umap <lli, list<lli> > &adj){
    map<lli,bool> visited;
    lli time = 0;
    euler_tour(1LL,visited,&time,adj);
    return;
}
vector<lli> tree(40000);
void buildTree(lli s,lli e,lli ind,lli *arr){
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    lli mid = (s+e)/2;
    buildTree(s,mid,2*ind,arr);
    buildTree(mid+1,e,2*ind+1,arr);
    // just storing the sum from [s,e] in tree[ind]
    tree[ind]= tree[2*ind] + tree[2*ind+1];
    return;
}
lli queryTree(lli s,lli e,lli qs,lli qe,lli ind){
    if(qe<s || qs>e){
        return 0;
    }
    if(s>=qs&& e<=qe){
        return tree[ind];
    }
    lli mid = (s+e)/2;
    lli left = queryTree(s,mid,qs,qe,2*ind);
    lli right = queryTree(mid+1,e,qs,qe,2*ind+1);
    return left + right;
}
// correct man :D
int main(){
    ios::sync_with_stdio(0);
    cout<<"CALCULATING THE SUM OF ALL THE VERTICES IN SUBTREE OF X";
    lli n,m;
    cout<<"\nEnter the number of vertices :";
    cin>>n;
    cout<<"\nEnter the number of edges :";
    cin>>m;
    cout<<"Enter edges(S,E)";
    umap <lli,list<lli> > adj;
    makeGraph<lli> (n,m,true,adj);
    timings(n,adj);
    cout<<"Timings generated :\n";
    cout<<"Time - in:\n";

    lli arr[n+1];// creating the array
    // indices -> time values
    // elements -> node values

    for(auto k:in){
        cout<<k.first<<":"<<k.second<<endl;
        arr[k.second] = k.first;
    }

    cout<<"Time - out\n";
    for(auto k:out){
        cout<<k.first<<":"<<k.second<<endl;
    }

    buildTree(1LL,n,1LL,arr);
    lli q;
    cout<<"Enter the number of queries :";
    cin>>q;
    lli v;
    while(q--){
        cout<<"Enter the vertex number :";
        cin>>v;
        // left is actually the range start(starting time)
        // right is the range end(ending time)
        lli l = in[v];// left index
        lli r = out[v];//right index
        cout<<"Sum of all vertices in its subtree is :"<<queryTree(1LL,n,l,r,1LL)<<endl;
    }

    return 0;
}
