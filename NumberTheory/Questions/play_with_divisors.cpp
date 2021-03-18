#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
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
void extend_euclid(lli a,lli b,lli *x,lli *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return;
    }
    else{
        extend_euclid(b,a%b,x,y);
        lli t1,t2;
        t1 = *x;
        t2 = *y; // *x and *y are the values that were returned from the
        // bottom tier.
        *x = t2;// update x
        *y = t1 - (a/b)*t2;// update y
    }
}
lli help_euclid(lli a,lli b)
{   // just return x corresponding to the equation Ax + By = GCD(A,B)
    lli x,y;
    extend_euclid(a,b,&x,&y);
    return x;
}
lli mod_inverse(lli a,lli m)
{
    lli b = help_euclid(a,m);
    return (b+m)%m;
}
int main()
{   ios::sync_with_stdio(false);
    lli x;
    cin>>x;
    lli arr[x];
    lli cprod= 1;
    for0(x)
        {
            cin>>arr[i];
            cprod = (cprod%mod*(arr[i]+1)%mod)%mod;
        }
    //cout<<"Total product :"<<cprod<<endl;
    // res stores number of divisors.(p1+1)(p2+2)...
    lli res = 1, first,second,val;
    for0(x)
    {
        first = ((arr[i])%mod*(arr[i]+1)%mod)%mod; // the contribution of all powers.
        first = (first/2)%mod;
        second = (cprod%mod * mod_inverse(arr[i]+1,mod)%mod)%mod ; // the total possibilities for each power
                                                                // of that prime factor.
        val = ((first%mod * second%mod)%mod + 1)%mod;
        res = (res%mod * val%mod)%mod;
    }
    cout<<res;
    return 0;
}
