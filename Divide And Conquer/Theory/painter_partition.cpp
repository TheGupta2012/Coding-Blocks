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
// scheduling approach won't really work as you can't sort the boards.
bool canPaint(lli time,lli painters, lli n, lli *boards){
    //cout<<"Checking for "<<time<<"...\n";
    if(painters>=n){
        // then kabhi switch mar hi nhi paenge
        // why? as all the boards would be occupied.
        lli max=-1;
        for0(n)
        {
            if(boards[i]>max)
                max = boards[i];
        }
        if(time>=max)
            return true;
        else
            return false;
    }
    else{
        lli changes = 0;
        lli curr = 0, i=0;
        while(i<n){
            curr+= boards[i];
            if(curr>time){
                curr = 0;
                changes++;
            }
            else
                i++;
        }
        if(changes<=painters-1) return true; // <= condition important.
        else return false;
    }

}
lli solve_painter(lli s,lli e, lli n,lli k, lli *arr)
{
    lli ans,mid;
    while(s<=e){
        mid = (s+e)/2;
        if(canPaint(mid,k,n,arr)==true){
            ans = mid;
            // kya isse kum mei bhi paint ho skta hai?
            e = mid - 1;
        }
        else{
            // agar mid mei hi nhi kr skte
            // to usse kum mei kya krenge
            s = mid+1;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    in(k);
    in(n);
    lli arr[n];
    lli max = -1;
    lli sum = 0;
    for0(n)
        {cin>>arr[i];
        sum+=arr[i];
        if(arr[i]>max) max=arr[i];}
    // can't sort
    //sort(arr,arr+n);
    lli ans = solve_painter(max,sum,n,k,arr);// range needs to be specified else we wil get tle.
    cout<<ans;
    return 0;
}
