#include<bits/stdc++.h>
using namespace std;
bool cycleCheckOdd(int src,int v,map<int,bool> &visited,vector<int> adj[],int parent,int *length){
    // -> length is denoting the number of vertices in the cycle
    visited[src] = true;

    for(auto k: adj[src]){
        if(visited[k] == false){
            *length = *length + 1;
           bool f = cycleCheckOdd(k,v,visited,adj,src,length);
           if(f==true)
              return true; // only then, nhi to
              // loop break ho jaega
        }
        else if(visited[k] == true){
            // means visited[k] == true
            // *length = *length + 1;
            if(k!= parent){
                // cycle is present for sure
                // *length = *length + 1;
                if(*length %2 == 1 && *length>1){
                    cout<<"\nCurrent vertex: "<<src;
                    cout<<"\nNeighbour: "<<k<<endl;
                    cout<<"Parent:"<<parent<<endl;
                    cout<<"Cycle of length "<<*length<<" present in graph!";
                    return true;
                }
                else{
                    cout<<"Current vertex: "<<src;
                    cout<<"\nNeighbour: "<<k<<endl;
                    cout<<"Parent:"<<parent<<endl;
                    cout<<"\nCycle of length "<<*length<<" present in graph!";
                    cout<<"\nChecking more...";
                }
            }
        }
    }
    return false;
}
void BIPARTITE(int v,vector<int> adj[]){
    map < int,bool > visited;
    for(int i=1;i<=v;i++)
        visited[i] = false;
    for (int i=1;i<=v;i++){
        // // cycle condition is
        // -> if the node you are visiting is already visited and
        // -> is not the parent of the current node, then there is a cycle.
        if(visited[i] == false){
        int count =1;
        if(cycleCheckOdd(i,v,visited,adj,-1,&count)==true){
            cout<<"\nYour graph is not BIPARTITE...";
            return;
        }
    }
    }
    cout<<"\nYou have a BIPARTITE graph...";
}
int main(){
    cout<<"\nBIPARTITE GRAPH CHECK...\n To check if odd length cycle present in graph or not\n";
    int v,e,s;
    cout<<"Enter number of vertice :";
    cin>>v;
    cout<<"Enter the number of edges :";
    cin>>e;
    int end;
    vector<int> adj[v+1];
    for(int i=0;i<e;i++){
        cout<<"Start:";
        cin>>s;
        cout<<"End:";
        cin>>end;
        adj[s].push_back(end);
        adj[end].push_back(s);
    }
    cout<<"Checking for BIPARTITE GRAPH....";
    BIPARTITE(v,adj);
    return 0;
}
