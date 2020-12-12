#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define asc_ord_set tree< lli , null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define desc_ord_set tree< lli , null_type, greater<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define key_position(k,o) o.order_of_key(k)
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef unordered_map <lli,lli> umap;
typedef priority_queue<lli> pq;
typedef pair <lli, lli> pi;
bitset<10000000> p;
bool sieve_made = false;
lli mod;
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
lli matrices[100005][2][2];
vector< vector < vector< lli > > > Tree(400005,vvi(2,vi(2)));
vvi identity(2,vi(2));
vvi multiply(vvi &a,vvi &b){
    vvi res(2,vi(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res[i][j] = (res[i][j]%mod + (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
            }
        }
    }
    return res;
}
void buildTree(lli s,lli e,lli ind){
    // if leaf, then store the matrix
    // segment tree of matrices ! arre wah!.
    if(s==e){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                Tree[ind][i][j] = matrices[s][i][j];
            }
        }
        return;
    }
    lli mid = (s+e)/2;
    buildTree(s,mid,2*ind);
    buildTree(mid+1,e,2*ind+1);
    // store a matrix in the segment tree node which is the
    // product of matrices from l to r, both included. :D
    Tree[ind] = multiply(Tree[2*ind],Tree[2*ind+1]);
    return;
}
vvi queryMatrix(lli s,lli e,lli l, lli r,lli ind){
    // if out of range, return indentity matrix
    if(r<s || l>e){
        return identity;
    }
    if(s>=l && e<=r){
        return Tree[ind];
    }
    lli mid = (s+e)/2;
    vvi left = queryMatrix(s,mid,l,r,2*ind);
    vvi right = queryMatrix(mid+1,e,l,r,2*ind+1);
    return multiply(left,right);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    identity[0][0] = 1;
    identity[0][1] = 0;
    identity[1][0] = 0;
    identity[1][1] = 1;
    cin>>mod;
    in(n);
    in(q);
    for0(n){
        // input matrix[i]
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cin>>matrices[i][j][k];
            }
        }
    }
    buildTree(0,n-1,1);
    while(q--){
        in(l);
        in(r);
        vvi res= queryMatrix(0,n-1,l-1,r-1,1);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<res[i][j]<<" ";
            }
        cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
