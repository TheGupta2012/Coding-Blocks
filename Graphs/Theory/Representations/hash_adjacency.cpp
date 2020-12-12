#include<bits/stdc++.h>
using namespace std;
class Graph{
    public : map < string, list<pair <string,int> > > adj;
        // adj is simply a list of pairs.
        // hashed with the start vertex value.
          void addEdge(string u,string v,int w, char type){
              if(type=='U'){
                  adj[u].push_back({v,w});
                  adj[v].push_back({u,w});
                  cout<<"Undirected Edge : {"<<u<<","<<v<<"}{"<<w<<"} inserted!\n";
              }
              else{
                  adj[u].push_back({v,w});
                  cout<<"Directed Edge : {"<<u<<","<<v<<"}{"<<w<<"} inserted!\n";
              }
          }
          void displayGraph(){
              cout<<"Your graph is ...\n";
              for(auto j:adj){
                  cout<<j.first<<":";
                  for(auto k:j.second){
                      cout<<k.first<<","<<k.second<<" ";
                  }
                  cout<<endl;
              }
          }
};
int main(){
    ios::sync_with_stdio(0);
    cout<<"Making graphs....Enter start as -1 to break\n";
    cout<<"Enter type of graph (U:undirected, D:directed) :";
    char type;
    cin>>type;
    string s,e;
    int w;
    Graph g;
    while(true){
        cout<<"S:";
        cin>>s;
        cout<<"E:";
        cin>>e;
        cout<<"W:";
        cin>>w;
        if(s=="-1")
            break;
        else
            g.addEdge(s,e,w,type);
    }
    g.displayGraph();
    return 0;
}
