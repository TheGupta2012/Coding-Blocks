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
int main()
{   ios::sync_with_stdio(0);
    while(true){
        in(n);
        if(n==-1)
            break;
        vi arr(n);
        vi prefix(n+1,0);
        lli ele;
        for0(n)
            {cin>>ele;
            arr[i] = ele;
            prefix[i+1] = (prefix[i]+arr[i]);}
        lli s = accumulate(all(arr),0);
        if(s%n!=0)
            cout<<-1<<"\n";
        else{
        // go on to find the minimum number of moves .
        lli target = s / n;
        lli ans = -1e10;
        for(int i=0;i<n-1;i++){// only go till the second last element.
            // aim to find the number of transfers we require
            // why maximum ?
            // because utne mei saare hi ho jaenge but usse kum
            // mei maximum vala nhi hoga .... nice!.
            // cout<<"Index i : "<<i+1<<endl;
            lli left = prefix[i+1];
            // cout<<"Left sum : "<<left<<endl;
            // Don't really need the right sum, as absolute difference is gonna be the same
            // lli right = prefix[n] - prefix[i+1];
            // cout<<"Right sum : "<<right<<endl;
            lli left_req = (i+1)*target;
            // lli right_req = (n-i-1)*target;
            // cout<<"Absolute value of jobs to be transferred : "<<abs(left-left_req)<<endl;
            ans = max(ans,abs(left_req-left));
        }
        cout<<ans<<endl;
    }
}
    return 0;
}
