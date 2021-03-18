#include<bits/stdc++.h>
using namespace std;
vector<int> tree(40000,0);
vector<int> lazy(40000,0);
void buildTree(int s,int e,int *arr,int ind){
    // base
    if(s==e)
        {
            tree[ind]= arr[s];
            return;
        }
    // recurse
    int mid = (s+e)/2;
    buildTree(s,mid,arr,2*ind);
    buildTree(mid+1,e,arr,2*ind+1);
    tree[ind] = tree[2*ind] + tree[2*ind+1];
    return;
}
int queryTree(int qs,int qe,int s,int e,int ind)
{
    if(lazy[ind]!=0) // resolve the lazy values
    {
        tree[ind] += lazy[ind]*(e-s+1); // resolving is a bit different
        // add the sum that is required to be added for that corresponding node.
        if(s!=e)
        {
            lazy[2*ind] += lazy[ind]; // only updating lazy not resolving them
            lazy[2*ind+1] += lazy[ind]; // only updating lazy not resolving them
        }
        lazy[ind] = 0;
    }
    // base
    if(s>qe || e<qs)
        return 0; // no sum needs to be returned for out of bounds range
    if(s>=qs && e<=qe){
        return tree[ind];
        // not checking for lazy values as we already resolved them
        // in the above code segment
    }
    int mid = (s+e)/2;
    int l = queryTree(qs,qe,s,mid,2*ind);
    int r = queryTree(qs,qe,mid+1,e,2*ind+1);
    return (l+r);
}
void updateLazySum(int qs,int qe,int update, int s,int e,int ind){
    // resolve the lazy update
    if(lazy[ind]!=0)// something needs to be resolved
    {
        tree[ind]+= lazy[ind]*(s-e+1);
        if(s!=e)// children present
        {
            lazy[2*ind]+= lazy[ind];
            lazy[2*ind+1]+= lazy[ind];// only updation, no resolultion
        }
        lazy[ind] = 0;
    }
    // base
    if(s>qe || e<qs)
        return ;
    if(s>=qs && e<=qe){
        tree[ind]+= update*(e-s+1);// resolve the update
        if(s!=e){
            lazy[2*ind]+= update; // update the lazy values.
            lazy[2*ind+1]+= update;// update the lazy values.
        }
        return; //optimization
    }
    int mid = (s+e)/2;
    updateLazySum(qs,qe,update,s,mid,2*ind);
    updateLazySum(qs,qe,update,mid+1,e,2*ind+1);
    tree[ind] = tree[2*ind]+tree[2*ind+1];
    return ;
}
// correct
int main(){
    int n,q,l,r,c,update;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :";
    // lazy value still represents
    // the update but
    // how you update a node corresponding
    // to a lazy value changes.
    // here it will be -> +inc*(no.of nodes)
    // as the node is responsible for the
    // sum from l-> r and that is why
    // you update it like this
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Making the tree...";
    buildTree(0,n-1,arr,1);
    cout<<"\nTree built.\n";
    cout<<"Enter number of queries :";
    cin>>q;
    cout<<"QUERY FORMAT :\n 1 L R -> TO GET SUM FROM RANGE [L,R]\n 2 L R U -> TO UPDATE ALL NODES FROM RANGE [L,R] BY VALUE U\n";
    while(q--){
        cin>>c>>l>>r;
        if(c==1){
            cout<<queryTree(l,r,0,n-1,1)<<endl;
        }
        else if(c==2){
            cin>>update;
            updateLazySum(l,r,update,0,n-1,1);
        }
        else{
            cout<<"Wrong query format.\n";
        }
    }

    return 0;
}
