#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> tree(400005,0);
lli F(lli ind,lli n,lli k,lli *arr,lli sum){
    lli total = sum;
    lli turns = k/n;
    lli ans = turns*total;
    lli rem = k%n;
    while(rem>0){
        ans+= arr[ind];
        ind--;
        rem--;
        if(ind<1)
            ind = n;
    }
    return ans;
}
void buildTree(lli n,lli k,lli s, lli e, lli *arr,lli ind,lli sum){
    // base
    if(s==e)
        {
            // tree[ind] = arr[s];
            // at a particular index you need the f(x,k) value
            tree[ind] = F(s,n,k,arr,sum);
            return;
        }
    // recurse
    lli mid = (s+e)/2;
    buildTree(n,k,s,mid,arr,2*ind,sum);
    buildTree(n,k,mid+1,e,arr,2*ind+1,sum);
    tree[ind] = tree[2*ind] + tree[2*ind+1];
    return;
}
void updateTree(lli i,lli n,lli k,lli val, lli s,lli e,lli ind,lli *arr,lli sum){
    //base
    if(i>e || i<s)
        return;
    if(s==e && s==i){
        // just changing the value of the array
        arr[s] = val;
        tree[ind] = F(s,n,k,arr,sum);
        return;
    }
    lli mid = (s+e)/2;
    updateTree(i,n,k,val,s,mid,2*ind,arr,sum);
    updateTree(i,n,k,val,mid+1,e,2*ind+1,arr,sum);
    tree[ind] = tree[2*ind] + tree[2*ind+1];
    return ;
}
lli query(lli s,lli e,lli l,lli r,lli ind){
    // base
    if(r<s || l>e)
        return 0;
    if(s>=l && e<=r){
        return tree[ind];
    }
    //recurse
    lli mid = (s+e)/2;
    lli left = query(s,mid,l,r,2*ind);
    lli right = query(mid+1,e,l,r,2*ind+1);
    return left + right;
}
int main(){
    ios::sync_with_stdio(0);
    lli n,k,q,l,r,c;
    cin>>n>>k>>q;
    lli arr[n+1];
    lli sum = 0;
    arr[0] = 0;
    for(int i=1;i<=n;i++)
        {cin>>arr[i];
        sum+=arr[i];}
    // lli suffix[n+1] = {0};
    // suffix[n] = arr[n-1];
    // for(int i=n-1;i>=1;i--){// one based
    //     suffix[i] = suffix[i+1] + arr[i];
    // }
    // suffix 1 is the total sum.
    // build segtree
    buildTree(n,k,1,n,arr,1,sum);
    while(q--){
        cin>>c;
        cin>>l>>r;
        if(c==1){
            updateTree(l,n,k,r,1,n,1,arr,sum);
            cout<<"Array becomes :\n";
            for(auto j:arr)
                cout<<j<<" ";
            cout<<endl;
        }
        else{
            cout<<query(1,n,l,r,1)<<endl;
        }
    }
    return 0;
}
