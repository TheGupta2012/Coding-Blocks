#include<bit/stdc++.h>
#define unordered_map umap;
using namespace std;
template <typename T>
umap <T,list<T> > makeGraph(lli n,lli m,bool both){
    umap <T,list<T> > adj;
    T s,e;
    for0(m){
        cin>>s>>e;
        // modified input
        adj[e].push_back(s);
        if(both==true)
            adj[e].push_back(s);
    }
    return adj;
}
template <typename T>
void bfs_topo(unordered_map< T,list<T> > &adj,list<T> &answer){
   map<T,int> indeg;
   for(auto k:adj){ // initialise
       indeg[k.first] = 0;
   }
   for(auto k:adj){ // update
       T node = k.first;
       for(auto y:k.second){
           indeg[y]++;
       }
   }

   // code starts
   queue<T> q;
   for(auto k:indeg){
       if(k.second==0)
            q.push(k.first);
        else
            break;
   }
   // got the queue initialised
   while(!q.empty()){

       T curr = q.front();
       for(auto k:adj[curr]){
           indeg[k] -=1;
           if(indeg[k]==0)
                q.push(k);
       }
       answer.push_back(curr);
       q.pop();
   }
   return;
}
template <typename T>
list<T> topological(unordered_map<T,list<T> > &adj){
    list <T> ordering;
    // BFS
    bfs_topo(adj,ordering);
    return ordering;
}
int main(){

}
