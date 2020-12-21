#include<bits/stdc++.h>
using namespace std;
int find_compressed(int u,int *parent){
    int temp = u;
    while(parent[temp]!=-1)
        temp = parent[temp];
    if(parent[u]!=-1)
        parent[u] = temp;
    return temp;
}
void Union(int n,int u,int v,int *parent,int *rank){
    cout<<"\nParent of "<<u<<" is :";
    int p1 = find_compressed(u,parent);
    cout<<u;
    cout<<"\nParent of "<<v<<" is :";
    int p2 = find_compressed(v,parent);
    cout<<v<<endl;
    if(p1!=p2)
        {
            if(rank[p1]<rank[p2]){
                parent[p1] = p2;
                // merge smaller into bigger
                rank[p2]+= rank[p1];
            }
            else{
                parent[p2] = p1;
                rank[p1]+= rank[p2];
            }
            cout<<"\nPARENTS :";
            for(int i=0;i<n;i++)
                cout<<parent[i]<<" ";
            cout<<"RANKS :";
            for(int i=0;i<n;i++)
                cout<<rank[i]<<" ";
                cout<<endl;
        }
    else
        cout<<"CYCLEEEE!";
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"COLLAPSING FIND AND WEIGHTED UNION\n";
    cout<<"\nCollapsing find is just building the tree and after a call,\nmake the child as the direct child of its top level parent.\n";
    cout<<"\nWeighted union is the process of using the size of component while doing union\n\n";
    cout<<"Enter total vertices :";
    int n,s,e;
    cin>>n;
    int parent[n+1];
    int ranks[n+1];
    for(int i=0;i<=n;i++)
        {parent[i] = -1;
        ranks[i] = 1;}
    cout<<"Enter total edges :";
    int edges;
    cin>>edges;
    cout<<"Enter edges :\n";
    while(edges--){
        cin>>s>>e;
        Union(n,s,e,parent,ranks);
    }
    cout<<"Enter the number of find queries :";
    int q;
    cin>>q;
    while(q--){
        cout<<"Enter v:";
        int v;
        cin>>v;
        cout<<"\nCurrent parent :"<<parent[v];
        cout<<"\nRooted Parent is :"<<find_compressed(v,parent);
        cout<<"\nParent becomes :"<<parent[v]<<endl;
    }
    return 0;
}
