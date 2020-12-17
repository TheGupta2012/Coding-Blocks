#include<bits/stdc++.h>
using namespace std;
void topological(int v,map<int,int> &indeg,unordered_map <int , list<int> > &adj){
    // start with the lowest indegree vertex, i.e. 0
    queue<int> q;
    for(auto k:indeg){
        // this is because map is sorted by value
        if(k.second==0)
            q.push(k.first);
        else
            break;
    }
    if(q.empty()==true)
        {cout<<"Cycle present, no topological order...";
        return;}
    while(!q.empty()){
        // don't think so visited is required
        // as I am actually going from lower indeg
        // to higher indeg ...
        // "no repetitions" as backedge would mean cycle
        int curr = q.front();
        for(auto k:adj[curr]){
            indeg[k] -=1;
            if(indeg[k]==0)
                q.push(k);
        }
        cout<<curr<<" ";
        q.pop();
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"Enter number of vertices :";
    int v,edges,start,end;
    cin>>v;
    cout<<"Enter number of edges :";
    cin>>edges;
    map<int,int> indeg;
    for(int i=0;i<=v;i++)// to store indegrees 
        indeg[i] = 0;
    unordered_map <int , list<int> > adj;
    while(edges--){
        cin>>start>>end;
        indeg[end]+=1;
        adj[start].push_back(end);
    }
    cout<<"Indegrees :\n";
    for(auto k:indeg){
        cout<<k.first<<":"<<k.second<<" ";
    }
    cout<<endl;
    topological(v,indeg,adj);
    return 0;
}
