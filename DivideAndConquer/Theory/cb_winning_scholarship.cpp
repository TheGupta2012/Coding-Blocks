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
lli canSShipGiveTo(lli n,lli target, lli total_c, lli x, lli y){
    //x -> the coupons required for a child to get s_ship
    //y-> the coupons we can take away from a student
    // i just need to see if I can atlelast give scholarship
    // these number of students.
    // total_coupon / x is the number of students to which we can directly
    // give a scholarship
    if(total_c/x >= target)
        return true;
    else{
        lli remain = n - target;// remaining students
        lli required_val = (target - total_c/x)*x; // required coupons for the rest of the remaining students
        lli gen_value = (total_c%x + y*remain);
        // how much value we have and can generate.
        if(gen_value>=required_val)
            return true;
        else
            return false;
    }
}
lli solve(lli s,lli e,lli n, lli m, lli x, lli y){
    // search space is 0-> n.
    // predicate -> if mid evaluates to true means we can
    // give atleast mid students the scholarship and thus
    // usse kum ko to de hi skte hain-> go right.
    // if mid evaluates to false means we cannot give
    // scholarship to mid students and thus usse zada ko
    // kya hi denge.
    lli ans , mid; // maximise the answer
    while(s<=e){
        mid = (s+e)/2;
        if(canSShipGiveTo(n,mid,m,x,y)==true){
            ans = mid;
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return ans;
}
// AMAZING ! first try accepted -> :D
int main(){
    in(n);// total students
    in(m);// total coupons
    in(x);// coupons required for scholarship
    in(y);// coupons that can be generated from a student back to the CB
    lli ans = solve(0,n,n,m,x,y);
    cout<<ans;
    return 0;
}
