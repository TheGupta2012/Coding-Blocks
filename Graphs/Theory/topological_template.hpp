#include<bits/stdc++.h>
using namespace std;

template <typename T>
void dfs_topo(T source, map<T,bool> &visited,unordered_map<T,list<T> > &adj,list<T> &answer){
    // visit the source
    visited[source] = true;
    for(auto k:adj[source]){
        if(!visited[k]){
            dfs_topo(k,visited,adj,answer);
        }
    }
    // at this point i have traversed
    // all the dependent children,
    // i can add my current node to the
    // front of my list/ordering
    answer.push_front(source);
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
    // DFS
    //make a visited array and initialise
    map< T,bool> visited;
    for(auto k:adj){
        T node = k.first;
        visited[node] = false;
    }

    for(auto k:adj){
        T node = k.first;
        if(visited[node] == false)
            dfs_topo(node,visited,adj,ordering);
    }
    // this is gonna be one of the topological
    // ordering for my graph
    // dependencies resolved! :D

    // BFS
    bfs_topo(adj,ordering);

    return ordering;
}
