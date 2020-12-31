#include<bits/stdc++.h>
#define umap unordered_map
#define for0(m) for(lli i = 0;i<m;i++)
using namespace std;
typedef long long int lli;
// #define umap unordered_map
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
void euler_1(lli src,lli *time,map<lli,bool> &visited,umap<lli,list<lli> > &adj){
    visited[src] = true;
    in[src] = *time;
    *time = *time+1;
    cout<<src<<" ";//entering
    for(auto k:adj[src]){
        if(visited[k]==false){
            euler_1(k,time,visited,adj);
        }
    }
    // incremented time here
    out[src] = *time;
    *time = *time + 1;
    cout<<src<<" "; // exiting
    return;
}
void calculate_times(umap<lli,list<lli>> &adj){
    map <lli,bool > visited;
    for(auto k:adj){// initialise
        lli node = k.first;
        visited[node] = 0;
    }
    lli time = 1LL;
    euler_1(1LL,&time,visited,adj);
    return;

}
bool same_path(lli v1,lli v2){
    if(v1==v2) return true;
    if(in[v1] < in[v2] && out[v2] < out[v1])
        return true;
    else if (in[v2] < in[v1] && out[v1] < out[v2])
        return true;
    else
        return false;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"Finding if the nodes lie in the same path or not\n";
    lli n,m;
    cout<<"Euler tour 2: Printing a node when we enter it and when we exit it.\n";
    cout<<"Enter the number of vertices in the graph :";
    cin>>n;
    cout<<"Enter the number of edges in the graph :";
    cin>>m;
    cout<<"Enter edges : (S,E)\n";
    umap <lli,list<lli> > adj;
    makeGraph<lli>(n,m,true,adj);
    map<lli,lli> time_in,time_out;
    calculate_times(adj);
    cout<<"\nIn times of all vertices :";
    for(auto k:in){
        cout<<k.first<<":"<<k.second<<endl;
    }
    cout<<"\nOut times of all vertices :";
    for(auto k:out){
        cout<<k.first<<":"<<k.second<<endl;
    }
    cout<<"Enter the number of queries :";
    lli q;
    cin>>q;
    lli v1,v2;
    while(q--){
        cout<<"Enter v1:";
        cin>>v1;
        cout<<"Enter v2:";
        cin>>v2;
        if(same_path(v1,v2))
            cout<<"Yes same path!\n";
        else
            cout<<"Sorry, not the same path.\n";
    }
    return 0;
}
