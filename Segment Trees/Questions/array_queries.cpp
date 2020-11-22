#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> tree(400005,0);
void buildTree(lli s, lli e, lli *arr,lli ind){
    // base
    if(s==e)
        {
            tree[ind] = arr[s];
            return;
        }
    // recurse
    lli mid = (s+e)/2;
    buildTree(s,mid,arr,2*ind);
    buildTree(mid+1,e,arr,2*ind+1);
    tree[ind] = ;//??
    return ;
}
void updateTree(lli i,lli val, lli s,lli e,lli ind){
    //base
    if(i>e || i<s)
        return;
    if(s==e && s==i){
        // just changing the value of the array
        tree[ind] = val;
        return;
    }
    lli mid = (s+e)/2;
    updateTree
}
int main(){
    ios::sync_with_stdio(0);
    lli n,k,q;
    cin>>n>>k>>q;
    lli arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    // build segtree
    buildTree(0,n-1,arr,1);

    return 0;
}
