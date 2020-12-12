#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of nodes in the graph :";
    cin>>n;
    string s,e;
    int w;
    char type;
    cout<<"Enter directed or undirected(D/U):";
    cin>>type;
    cout<<"Enter the vertex names :";
    map<string,int> v;
    string name;
    for(int i=0;i<n;i++){
        cin>>name;
        v[name] = i;
    }
    cout<<"Enter what representation you want (A:Adjaacency, L:List)-";
    char c;
    cin>>c;
    if(c=='A'){
        int connections=0;
        cout<<"Enter connections...(S,E,W)(S= -1 to break)\n";
        int adj[n][n]={0};
        while(true && connections<= n*(n-1)/2)
        {cout<<"Start:";
        cin>>s;
        if(s=="-1")
            break;
        cout<<"End:";
        cin>>e;
        cout<<"Weight:";
        cin>>w;
        if(type=='U'){
            adj[v[s]][v[e]] = w;
            adj[v[e]][v[s]] = w;
        }
        else
            adj[v[s]][v[e]] = w;
        connections++;
        }
        cout<<"\nYour graph is : - \n";
        for(int i=0;i<n;i++){
            for(int j=0;i<n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        // vector < pair <string,int> > Adj[n];
        // int connections=0;
        // cout<<"Enter connections...(S,E,W)(S= -1 to break)\n";
        // while(true && connections<= n*(n-1)/2)
        // {cout<<"Start:";
        // cin>>s;
        // if(s=="-1")
        //     break;
        // cout<<"End:";
        // cin>>e;
        // cout<<"Weight:";
        // cin>>w;
        // if(type=='U'){
        //     Adj[v[s]].push_back(make_pair(v[e],w));
        //     Adj[v[e]].push_back(make_pair(v[s],w));
        // }
        // else
        //     Adj[v[s]].push_back(make_pair(v[e],w));
        // connections++;
        // }
        // cout<<"\nYour graph is : -\n";
        // int count=0;
        // for(auto k: Adj){
        //     cout<<v[count++]<<":";
        //     for(auto j:k){
        //         cout<<j.first<<","<<j.second<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}
