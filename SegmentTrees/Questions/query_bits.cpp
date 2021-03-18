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
            res= (res * p)%mod;
        p= (p*p)%mod;
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
vi Tree(800005);
vi lazy(800005);
// lazy -> -1 : no update pending
// lazy ->  0 : make all from l,r as zero
// lazy ->  1 : make all from l,r as one
void updateTree(lli l,lli r,lli c,lli s,lli e,lli ind){
    // if lazy value is <0
    if(lazy[ind]!=-1) // resolve the lazy value
    {
        if(lazy[ind] == 0)
            Tree[ind] = 0;
        else{
            lli shifts = e-s+1;
            // doesn't matter meri current value kya hai
            // make it as (1<<shifts)-1 .
            Tree[ind] = (fast_power(2LL,shifts)%mod - 1 + mod)%mod;
        }
        if(s!=e){
            lazy[2*ind] = lazy[ind];
            lazy[2*ind+1] = lazy[ind];
        }
        lazy[ind] = -1;//default
    }
    // base return case .
    if(r<s || e<l)
        return;
    if(s>=l && e<=r){
        // node range lies completely inside the query .
        if(c==0){
            Tree[ind] = 0;
        }
        else{
            lli shifts = e-s+1;
            Tree[ind] = (fast_power(2LL,shifts)%mod - 1 + mod)%mod;
        }
        if(s!=e)// if non-leaf node then only propagate the lazy value.
        {lazy[2*ind] = c;
        lazy[2*ind+1] = c;}
        return; // the optimization
    }
    lli mid= (s+e)/2;
    updateTree(l,r,c,s,mid,2*ind);
    updateTree(l,r,c,mid+1,e,2*ind+1);
    lli shifts = e-mid;
    Tree[ind] = ((Tree[2*ind]%mod * fast_power(2LL,shifts)%mod)%mod + Tree[2*ind+1]%mod)%mod;
    return;
}
lli queryTree(lli l,lli r,lli s,lli e,lli ind){
    // base return
    if(r<s || l>e) {
        return 0;
    }
    // resolve the lazy value
    if(lazy[ind]!=-1){
        if(lazy[ind]==0){
            Tree[ind] = 0; // simply 0 as all would become zero.
        }
        else{
            // the value that will be generated in the current
            // node corresponding to updating all the elements
            // in that range as 1.
            lli shifts = e-s+1;
            Tree[ind] = (fast_power(2LL,shifts)%mod - 1 + mod)%mod;
        }
        if(s!=e){// push the lazy value to the children of the current node
            lazy[2*ind] = lazy[ind];
            lazy[2*ind+1] = lazy[ind];
        }
    lazy[ind] = -1; //resolved the value for the current node.
    }
    // don't need to check the lazy value as already checked above
    if(s>=l && e<=r){
        return Tree[ind];
    }
    // recurse for the tree in the left and right children
    lli mid = (s+e)/2;
    lli left = queryTree(l,r,s,mid,2*ind);
    lli right = queryTree(l,r,mid+1,e,2*ind+1);
    left = ( left%mod * fast_power(2LL,e-mid)%mod)%mod;
    return (left%mod+right%mod)%mod;
}
// need to correct
int main()
{   ios::sync_with_stdio(false);
    in(n);
    in(q);
    lli c,l,r;
    lli ans;
    for(int i=0;i<800005;i++)
        lazy[i] = -1;
    // no need to build tree, it is already built .
    // go on to process queries.
    while(q--){
        cin>>c>>l>>r;
        switch (c) {
            case 0:{
                updateTree(l,r,c,0,n-1,1LL);
                break;
            }
            case 1:{
                updateTree(l,r,c,0,n-1,1LL);
                break;
            }
            case 2:{
                ans = queryTree(l,r,0,n-1,1LL);
                cout<<ans<<endl;
                break;
            }
            default:{
                break;
            }
        }

    }
    return 0;
}
