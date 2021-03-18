#include<bits/stdc++.h>
using namespace std;
void buildTree(int s,int e,int *arr, vector<int> &tree, int ind){
    //base case
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    //recurse
    int mid = (s+e)/2;
    buildTree(s,mid,arr,tree,2*ind);
    buildTree(mid+1,e,arr,tree,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return;
}
void updateTreeInd(int i,int val,int s,int e,vector<int> &tree, int ind){
    // base
    if(i==s && i==e){ //
        tree[ind] = val;
        return;
    }
    if(i>e || i<s)
        return; // don't update the node val as it is already min of it's range
        // and won't be affected
    // index in the given range
    int mid = (s+e)/2;
    updateTreeInd(i,val,s,mid,tree,2*ind);
    updateTreeInd(i,val,mid+1,e,tree,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
}
void updateTreeRange(int qs,int qe,int inc,int s,int e,vector<int> &tree,int ind){
    // base cases.
    // out of bounds
    if(s>qe || e<qs)
        return ;
    // inside the range and singular range
    if(s==e && s>=qs && s<=qe)
        {
            tree[ind]+= inc;
            return;
        }
    // recurse
    int mid = (s+e)/2;
    // postorder traversal
    updateTreeRange(qs,qe,inc,s,mid,tree,2*ind);
    updateTreeRange(qs,qe,inc,mid+1,e,tree,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return;
}
int main(){
    int n;
    cout<<"Enter elements in array :";
    cin>>n;
    cout<<"Enter the elements :";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> tree(4*n+1,1e8);
    cout<<"Making the segment tree...";
    buildTree(0,n-1,arr,tree,1);
    cout<<"Tree built.";
    cout<<"\nEnter the number of updates :";
    int u;
    int s,e,i,val;
    cin>>u;
    while(u--){
        cout<<"Enter p for point updates and r for range updates\n";
        cout<<"Choice:";
        char c;
        Q:cin>>c;
        if(c=='p'){
            cout<<"Enter the index :";
            cin>>i;
            cout<<"Enter the new value :";
            cin>>val;
            if(i>=0 && i<n)
                {updateTreeInd(i,val,0,n-1,tree,1);
                cout<<"Updated tree is :\n";
                for(auto k:tree)
                    cout<<k<<" ";
                }
            else
                cout<<"Invalid index";
        }
        else if(c=='r')
            {cout<<"Enter range \n";
            cout<<"Start :";
            cin>>s;
            cout<<"End :";
            cin>>e;
            cout<<"Enter the value to update the range by :";
            cin>>val;
            updateTreeRange(s,e,val,0,n-1,tree,1);
            cout<<"\nTree has been updated...\n";
            for(auto k:tree)
                cout<<k<<" ";
            cout<<endl;
        }
        else
            {cout<<"Invalid choice\nEnter again";
            goto Q;}
    }
    return 0;
}
