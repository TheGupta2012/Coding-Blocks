#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void buildSegTree(int s,int e,int *arr, vector<int> &tree_array,int ind){
    // ind is the index at which we are currently at
    // s and e are the range boundaries FOR WHICH THIS INDEX CONTAINS THE ANSWER...
    // BASE -> Range boundaries are equal -> min is just the array element itself.
    if(s==e){
        tree_array[ind] = arr[s];
        return;
    }
    // RECURSE-> it is basically a post order traversal.
    // first build left
    int mid = (s+e)/2;
    buildSegTree(s,mid,arr,tree_array,2*ind);
    // then build right
    buildSegTree(mid+1,e,arr,tree_array,2*ind+1);
    // now build the current node
    tree_array[ind] = min(tree_array[2*ind],tree_array[2*ind + 1]);
    return;
}
int main(){
    cout<<"SEGMENT TREE BUILDING\n";
    cout<<"Task -> Find minimum element given in a range [l,r]\n";
    cout<<"Enter the number of elements in the array :";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Building the tree...";
    Sleep(4000);
    vector <int> tree_array(4*n+1,NULL);
    // the tree array has the property that its elements are computed
    // in  bottom up manner.
    buildSegTree(0,n-1,arr,tree_array,1);
    cout<<"Segment tree has been built.\n";
    for(int i=0;i<=2*n+1;i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<=2*n+1;i++)
        cout<<tree_array[i]<<" ";
    cout<<endl;
    return 0;

}
