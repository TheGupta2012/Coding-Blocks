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
using namespace std;
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
vi tree[400005]; // vector of vectors, important concept here
void buildTree(lli s,lli e, lli *arr,lli ind){
    //base
    if(s==e){
        tree[ind].push_back(arr[s]);
        return;
    }
    lli mid = (s+e)/2;
    buildTree(s,mid,arr,2*ind);
    buildTree(mid+1,e,arr,2*ind+1);
    merge(all(tree[2*ind]),all(tree[2*ind+1]),back_inserter(tree[ind]));
    // a node is actually a vector -> note that
    return;
}
lli queryTree(lli qs,lli qe,lli k,lli s,lli e,lli ind){
    // base case
    if(s>qe || e<qs)
        return 0;
    if(s>=qs && e<=qe){
        // means we are in a complete overlap phase
        lli i = upper_bound(all(tree[ind]),k) - tree[ind].begin();
        lli ans = tree[ind].size()- i;
        return ans;
    }
    // partial overlap
    lli mid = (s+e)/2;
    lli l = queryTree(qs,qe,k,s,mid,2*ind);
    lli r = queryTree(qs,qe,k,mid+1,e,2*ind+1);
    return l+r;
}
int main(){
    ios::sync_with_stdio(0);
    in(n);
    lli arr[n];
    for0(n)
        cin>>arr[i];
    buildTree(0,n-1,arr,1);
    in(q);
    lli a,b,c,l,r,k;
    lli last = 0;
    while(q--){
        cin>>a>>b>>c;
        l = a^last;
        r = b^last;
        k = c^last;
        if(l<1) l = 1;
        if(r>n) r = n;
        last = queryTree(l-1,r-1,k,0,n-1,1);
        cout<<last<<"\n";
    }
    return 0;
}
