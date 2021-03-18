#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define mod 1000000007
#define asc_ord_set tree< lli , null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define desc_ord_set tree< lli , null_type, greater<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define key_position(k,o) o.order_of_key(k)
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef unordered_map <lli,lli> umap;
typedef priority_queue<lli> pq;
typedef pair <lli, lli> pi;
bitset<10000000> p;
bool sieve_made = false;
lli fast_power(lli a,lli b)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res*= p;
        p= p*p;
        b= b>>1;
    }
    return res;
}
void sieve()
{   sieve_made=true;
    p[0] = p[1] = 0;
    p[2] = 1;
    for(lli i=4;i<=1000000;i+=2)
        p[i] = 0;
    for(lli i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(lli j=i*i;j<=1000000;j+=i)
                p[j] = 0;
        }
    }
}
bool prime(lli n)
{
    if(sieve_made==true)
    {
        if(n<10000000)
            return (p[n]);
        else{
             for(int i=2;i<=sqrt(n);i++)
                    if(n%i==0) return false;
            return true;
        }
    }
    for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
    return true;
}
map <lli,lli> factor;
void prime_fact(lli n)
{
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                {
                    factor[i]++;
                    n = n/i;
                }
        }
    }
    if(n!=1) factor[n] = 1;
}
void buildTree(lli s,lli e,lli *arr, vi &tree,lli ind){
    // base
    if(s==e)
        { tree[ind] = arr[s];
            return ;
        }
    //recurse postorder
    lli mid = (s+e)/2;
    buildTree(s,mid,arr,tree,2*ind);
    buildTree(mid+1,e,arr,tree,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return ;
}
lli queryTree(lli qs,lli qe, lli s, lli e, vi &tree, lli ind){
    if(qe < s || qs > e)
        return 1e18;// return inf
    if(s>=qs && e<=qe)
        return tree[ind];
    // recurse
    lli mid = (s+e)/2;
    lli l = queryTree(qs,qe,s,mid,tree,2*ind);
    lli r = queryTree(qs,qe,mid+1,e,tree,2*ind+1);
    return min(l,r);
}
void updateTree(lli i, lli val,lli s,lli e, vi &tree, lli ind){
    if(i<s || i>e)
        return;
    if(s==e && s==i)
        {tree[ind] = val;
        return;}
    // recurse
    lli mid = (s+e)/2;
    updateTree(i,val,s,mid,tree,2*ind);
    updateTree(i,val,mid+1,e,tree,2*ind+1);
    tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    return ;
}
int main()
{   ios::sync_with_stdio(false);
    in(n);
    in(q);
    lli arr[n+1]={0};
    for1(n)// one - based indexing
        cin>>arr[i];
    vi tree(4*n+1,1e18);
    buildTree(1,n,arr,tree,1);
    lli c,l,r,x,y;
    while(q--){
    cin>>c;
    if(c==1)// query
    {
        cin>>l>>r;
        cout<<queryTree(l,r,1,n,tree,1)<<"\n";
    }
    else
        {
            cin>>x>>y;
            updateTree(x,y,1,n,tree,1);
        }
    }
    return 0;
}
