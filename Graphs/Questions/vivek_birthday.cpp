#include<bit/stdc++.h>
#define unordered_map umap;
using namespace std;
template <typename T>
umap <T,list<T> > makeGraph(lli n,lli m,bool both,umap <T,list<T> > &adj){
    T s,e;
    for0(m){
        cin>>s>>e;
        // modified input
        adj[e].push_back(s);
        if(both==true)
            adj[e].push_back(s);
    }
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
    ios::sync_with_stdio(0);
    lli n,m;
    cin>>n>>m;
    umap < lli , list<lli> > adj;
    makeGraph(n,m,false,adj);
    // cases
    // 1. if we have a person who is not dependent
    // on anyone of the persons, then vivek can just
    // invite him,
    // minimum answer is thus 1, when for any i, indeg(i) = 0
    map<lli,lli> indeg;
    for(auto k:adj){ // initialise
        indeg[k.first] = 0;
    }
    for(auto k:adj){ // update
        T node = k.first;
        for(auto y:k.second){
            indeg[y]++;
        }
    }
    for(auto k:indeg){
        if(k.second == 0)
        {
            cout<<1;
            return 0;
        }
    }
    // 2. This means we do not have any node
    // with indeg as 0 and thus we many cycles
    // present in out graph...
    // GOAL - > choose the minimum size directed dependency
    // path which contains a cycle
    // as any kind of vertex which is pendant
    // or not in a cycle will atleast have the
    // from your graph...




    return 0;
}
