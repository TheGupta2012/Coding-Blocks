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
bool comp(const pi &a, const pi &b){
    if(a.first!=b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(0);
    in(t);
    while(t--){
        in(w);
        in(h);
        in(towers);
        lli x,y;
        lli X[towers],Y[towers];
        for0(towers){
            cin>>x;
            cin>>y;
            X[i] = x;
            Y[i] = y;
        }
        if(towers==0){
            cout<<w*h<<endl;
            continue;
        }
        sort(X,X+towers);
        sort(Y,Y+towers);
        // correct... O(n*log(n))
        lli l,b;
        l = X[0] - 1;
        for(int i=1;i<towers;i++){
            l = max(l,X[i]-X[i-1]-1);
        }
        l = max(l,w-X[towers-1]);
        b = Y[0] - 1;
        for(int i=1;i<towers;i++){
            b = max(b,Y[i]-Y[i-1]-1);
        }
        b = max(b,h -Y[towers-1]);
        cout<<l*b<<endl;
    }
    return 0;
}
