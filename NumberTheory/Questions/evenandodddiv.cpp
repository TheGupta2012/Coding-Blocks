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
lli sums[100005]={0};
void sieve()
{   for(int i=1;i<=100000;i++)
    {
        for(int j=i;j<=100000;j+=i)
        {   // heart of the problem.
            // j will have i as a divisor and depending on the nature of i
            // i will either add i or subtract i.
            if(i%2==0)
                sums[j] += i;
            else
                sums[j] -= i;

        }
    }
}
int main()
{
    lli q,n;
    cin>>q;
    sieve();
    while(q--)
    {
        cin>>n;
        cout<<sums[n]<<endl;
    }
    return 0;
}
