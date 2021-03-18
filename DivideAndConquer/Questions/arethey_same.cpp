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
bool isEquivalent(string a, string b){
    lli n,m;
    n = a.size();
    m = b.size();
    if(n<=0 || m<=0)
        return false;
    if(a==b)
        return true;
    if(n%2==1 || m%2==1)// important case. Can even be odd and then return false;
        return false;
    string a1,a2,b1,b2;
    a1 = a.substr(0,n/2);
    a2 = a.substr(n/2,n/2);
    b1 = b.substr(0,m/2);
    b2 = b.substr(m/2,m/2);
    if(isEquivalent(a1,b1) && isEquivalent(a2,b2))
        return true;
    if(isEquivalent(a1,b2) && isEquivalent(a2,b1))
        return true;
    return false;
}
int main(){
    in(t);
    while(t--){
        string a,b;
        cin>>a>>b;
        bool flag = false;
        lli l1,l2;
        l1 = a.size();
        l2 = b.size();
        if(a==b)
        {
            cout<<"YES\n";
            continue;
        }
        if(l1%2==1 || l2%2==1)
        {
            cout<<"NO\n";
            continue;
        }
        else{
            if(isEquivalent(a,b)==true)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
