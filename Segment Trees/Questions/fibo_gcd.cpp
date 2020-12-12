#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
vector<lli> dp(100005);
lli mod = 1e9+7;
vector<lli> tree(400005);
vvi T(2,vi(2));
vvi multiply(vvi A, vvi B){
    vvi X(2,vi(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                X[i][j] = (X[i][j] + (A[i][k]*B[k][j]));
            }
        }
    }
    return X;
}
vvi fast_power(vvi X,lli n){
    // base
    if(n==1)
        return X;
    else{
        if(n%2==0){
            vvi res;
            res = fast_power(X,n/2);
            return multiply(res,res);
        }
        else{
            return multiply(X,fast_power(X,n-1));
        }
    }
}
lli matrix_expo(lli n){
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;
    // base matrix ready ;
    vvi res = fast_power(T,n);
    // now multiply the base vector which is [0,1]
    // with the first row and grab first element
    return res[0][1]; // this is what will come ->
    // 0*res[0][0] + 1*res[0][1] is actually the first element
}
lli gcd(lli a,lli b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void buildTree(lli s,lli e,lli *arr,lli ind)
{
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    lli mid = (s+e)/2;
    buildTree(s,mid,arr,2*ind);
    buildTree(mid+1,e,arr,2*ind+1);
    tree[ind] = gcd(tree[2*ind],tree[2*ind+1])%mod;
    return;
}
lli queryTree(lli s,lli e,lli l,lli r,lli ind){
    // base
    if(r<s || l>e)
        return 0;
    if(s>=l && e<=r){
        return tree[ind];
    }
    lli mid = (s+e)/2;
    lli left = queryTree(s,mid,l,r,2*ind);
    lli right = queryTree(mid+1,e,l,r,2*ind+1);
    return gcd(left,right)%mod;
}
int main(){
    ios::sync_with_stdio(0);
    lli n,q;
    cin>>n>>q;
    lli arr[n];
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        arr[i] = matrix_expo(arr[i]);}
    // for(auto k:arr)
    //     cout<<k<<" ";
    // cout<<endl;
    //array replaced with fibonacci of Array
    buildTree(0,n-1,arr,1);
    while(q--){
        lli l,r;
        cin>>l;
        cin>>r;
        cout<<queryTree(0,n-1,l-1,r-1,1)<<endl;
    }
    return 0;
}
