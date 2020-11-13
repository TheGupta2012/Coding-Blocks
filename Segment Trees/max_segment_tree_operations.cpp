#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void buildTree(int s,int e,int *arr,vector<long long int> &tree, int ind){
    // base -> equal ranges
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    // recurse
    // build the left subtree
    int mid = (s+e)/2;
    buildTree(s,mid,arr,tree,2*ind);
    // build the right subtree
    buildTree(mid+1,e,arr,tree,2*ind + 1);
    // build the vaule of the node
    tree[ind] = max(tree[2*ind],tree[2*ind + 1]);
    return ;
 }
int main(){
    cout<<"SEGMENT TREE BUILDING\n";
    cout<<"Task -> Find maximum element given in a range [l,r]\n";
    cout<<"Enter the number of elements in the array :";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nBuilding the segment tree...\n";
    Sleep(3000);
    vector<long long int> tree_array(4*n+1,-1e10);
    buildTree(0,n-1,arr,tree_array,1);
    cout<<"Segment tree to compute max elements in given ranges is :\n";
    for(auto k:tree_array)
        {   if(k==-1e10)
                cout<<"NULL ";
            else
                cout<<k<<" ";};
    return 0;
}
