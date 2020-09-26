#include<bits/stdc++.h>
#include<cmath>
#define in(x) lli x; cin>>x;
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
#define mod 1e9 + 7;
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
{   lli temp = n;
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
    if(n!=1 && n!=temp) factor[n] = 1;
}
int main(){
    in(n);
    lli ele;
    vector<int> v(n,0);
    for0(n)
        {cin>>ele;
         prime_fact(ele);
         if(factor.size()==1)
         {
             // only one factor and the power is also only one.
             v[i]=1;

         }
        factor.clear();
        }
    for(auto j:v)
    {
        if(j) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
