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
lli search(lli s,lli e, lli key){
    lli ans,mid;
    while(s<=e){
        mid = (s+e)/2;
        if(mid*(mid+1)/2<=key){
            ans = mid;
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return ans;
}
bool valid(lli time,lli total,lli tot_cooks, lli *ranks)
{   lli curr_parathas = 0;
    for0(tot_cooks){
        lli r = ranks[i];// r for a cook.
        lli target = time/(r);
        // now find k such that k*(k+1)<= time, obviously k <= target.
        // add that k to your count
        // count of parathas is >= total parathas required then returnn true;
        lli k = search(0,target+1,target);
        // cout<<"Rank of "<<i<<" cook is:"<<r<<endl;
        // cout<<"He can make "<<k<<" parathas in "<<time<<" minutes"<<endl;
        curr_parathas += k;
    }
     // cout<<"Total parathas that they can make in "<<time<<" is "<<curr_parathas<<endl;
    if(curr_parathas>=total)
        return true;
    else
        return false;
}
lli solve_cooks(lli s,lli e,lli p,lli l, lli *ranks){
    lli mid,ans;
    while(s<=e){
        mid = (s+e)/2;
        if(valid(mid,p,l,ranks)==true)
            {ans = mid;
            e = mid - 1;}
        else
            s = mid + 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);

        in(p);
        in(l);
        lli ranks[l];
        for0(l)
            cin>>ranks[i];
        sort(ranks,ranks+l);
        // now what would be my higher bound? -> take it high enough
        lli ans = solve_cooks(0,1e10,p,l,ranks);
        cout<<ans<<endl;

    return 0;
}
