#include<bits/stdc++.h>
using namespace std;
void Union(int v1,int v2,int *parents)
{
    while(parents[v1]>0)
        v1 = parents[v1];
    while(parents[v2]>0)
        v2 = parents[v2];
    // now v1 and v2 are the head nodes
    if(v1!=v2)
        parents[v2] = v1; // merge v1 component into v2
    else
        cout<<"\nYou're trying to make a cycle!\n";
}
int find(int v,int *parents){
    while(parents[v]>0)
        v= parents[v];
    return v;
}
int main(){
    ios::sync_with_stdio(0);
    // linear union find

    cout<<"UNION-FIND FOR GRAPH....\n";
    cout<<"Enter number of vertices :";
    int n;
    cin>>n;
    int parents[n+1];
    for(int i=0;i<=n;i++){
        parents[i] = -1;
        //negative vaue indicates a
        // component is headed or rooted
        // at i
    }
    int ch,u1,u2;
    cout<<"Enter operation(1: union, 2: find, 3: print components,-1: exit)\n";
    while(true){
        cout<<"Enter choice :";
        cin>>ch;
        if(ch==-1) break;
        switch(ch){
            case(1):{
                    cout<<"\nEnter v1:";
                    cin>>u1;
                    cout<<"Enter v2:";
                    cin>>u2;
                    Union(u1,u2,parents);
                    break;
                }
            case(2):{
                    cout<<"Enter v:";
                    cin>>u1;
                    cout<<find(u1,parents);
                    cout<<endl;
                    break;}
            case(3):{
                    for(int i=1;i<=n;i++){
                        if(parents[i]<0)
                            cout<<"Head is "<<i<<endl;
                    }
                    break;}
            default: break;
        }
    }
    return 0;
}
