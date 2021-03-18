#include<bits/stdc++.h>
using namespace std;
void buildSegTree(int s,int e,int *arr,vector<int> &tree,int ind){
    //base case
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    // recurse, basically postorder
    int mid = (s+e)/2;
    buildSegTree(s,mid,arr,tree,2*ind);
    buildSegTree(mid+1,e,arr,tree,2*ind +1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return ;
}
int findMintree(int qs,int qe,int s,int e,vector<int> &tree,int ind){
    // three cases
    // 1. Complete overlap-> node range completely inside query range
    if(s>=qs && e<=qe)
        {return tree[ind];}// return the node value.
    // 2. Partial overlap
    // 3. no overlap -> return a suitable value as required in question
     if(qe<s || qs>e)
        {return 1e8;}// return infinity as min(inf,some_val) is gonna be some_val.
   int mid = (s+e)/2;
   int l = findMintree(qs,qe,s,mid,tree,2*ind);
   int r = findMintree(qs,qe,mid+1,e,tree,2*ind+1);
   return min(l,r);

}
int main(){
    int n;
    cout<<"Building a minimum segment tree...\n\n";
    cout<<"ENTER THE NUMBER OF ELEMENTS :";
    cin>>n;
    cout<<"Enter the elements :";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> tree_array(4*n+1,1e8);
    buildSegTree(0,n-1,arr,tree_array,1);
    // why did we give 1? we use 1 based indexing in
    // the segment tree
    for(auto k:tree_array){
        if(k==1e6)
            cout<<"NULL ";
        else
            cout<<k<<" ";
    }
    cout<<"\nLet's do queries!\n";
    cout<<"Enter the number of queries you would like :";
    int q,s,e;
    cin>>q;
    while(q--){
        x:cout<<"\nStart :";
        cin>>s;
        cout<<"End :";
        cin>>e;
        if(s<0 || e>n-1 || (e<s))
            {cout<<"Invalid queries.\nEnter again";
            q = q+1;
            goto x;}
        cout<<"Answer is :"<<findMintree(s,e,0,n-1,tree_array,1);
    }
    cout<<endl;
    return 0;
}
