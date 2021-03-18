#include<bits/stdc++.h>
using namespace std;
vector<int> tree(40000,100000);
int lazy[40000];
void buildTree(int s,int e,int *arr,int ind){
    //base
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    // recurse
    int mid = (s+e)/2;
    buildTree(s,mid,arr,2*ind);
    buildTree(mid+1,e,arr,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return ;
}
int queryTree(int qs,int qe,int s,int e,int ind){
    if(lazy[ind]!=0)
    // you need to always resolve the lazy value
    {
        tree[ind]+=lazy[ind];
        if(s!=e){
            lazy[2*ind]+= lazy[ind];
            lazy[2*ind+1]+= lazy[ind];
        }
        lazy[ind] = 0;
    }
    //base
    if(qe<s || qs>e)
        return 100000;// return a suitable value .
    // lazy value resolution needs to come before
    // recursion

    if(s>=qs && e<=qe){
        return tree[ind];
        // not checking lazy values as
        // in the above code segment we already
        // updated them and then only came down.
    }
    // recurse
    int mid = (s+e)/2;
    int l = queryTree(qs,qe,s,mid,2*ind);
    int r = queryTree(qs,qe,mid+1,e,2*ind+1);
    return min(l,r);
}
void updateLazy(int qs,int qe,int update,int s,int e,int ind){
    if(lazy[ind]!=0) {
            // you need to update your lazy value at the current node
            // in the first step i.e. resolve lazy value before going down.
            tree[ind] += lazy[ind];
            if(s!=e){
                lazy[2*ind] += lazy[ind];
                lazy[2*ind+1] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    // base
    if(s>qe || e<qs)
        return ; // no updation required .
    // the lazy case

    // recursive cases
        // -> optimization case
        if(s>=qs && e<=qe){
            tree[ind] += update;
            // create new lazy value for children
            if(s!=e){
                lazy[2*ind] += update;
                lazy[2*ind+1] += update;
            }
            return ; // this is the optimization
        }
        // -> partial overlap
        int mid = (s+e)/2;
        updateLazy(qs,qe,update,s,mid,2*ind);
        updateLazy(qs,qe,update,mid+1,e,2*ind+1);
        // update the tree index
        tree[ind] = min(tree[2*ind],tree[2*ind+1]);
        return;
}
int main(){
    ios::sync_with_stdio(0);
    for(int i=0;i<40000;i++)
        lazy[i] = 0;
    int n;
    cout<<"Enter the number of items :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(0,n-1,arr,1);
    cout<<"Enter the number of updates and queries(0 : query, 1 : update) :";
    int q,l,r,c,up;
    cin>>q;
    cout<<"Enter queries...\n";
    while(q--){
        cin>>c;
        cin>>l>>r;
        if(c==0){
            cout<<queryTree(l,r,0,n-1,1)<<endl;
        }
        else{
            cout<<"Enter the update value :";
            cin>>up;
            updateLazy(l,r,up,0,n-1,1);
            cout<<"The tree is :";
            for(int i =0;i<4*n + 1;i++)
                {if(tree[i]!=1e5)
                    cout<<tree[i]<<" ";
                else
                    cout<<"NULL ";
                }
            cout<<endl;
            cout<<"The lazy values of the tree are :";
            for(int i=0;i<4*n+1;i++)
                cout<<lazy[i]<<" " ;
            cout<<endl;
        }

    }
    return 0;
}
