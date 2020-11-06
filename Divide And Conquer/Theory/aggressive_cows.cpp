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
lli valid(lli gap, lli cows, lli n, lli *arr){
    lli i=0;
    lli prev;
    // prev is actually we have placed the cow not some random
    // consecutive element.
    cout<<"Checking for "<<gap<<" minimum distance\n";
    while(cows>0 && i<n){
        if(i==0){
            cows--;
            cout<<"A cow is placed at "<<arr[i]<<endl;
            prev = arr[i];
        }else{
            if(arr[i]-prev>=gap){
                // array sorted that is why checking the consecutive elements.
                cows--; // place a cow there.
                cout<<"A cow is placed at "<<arr[i]<<endl;
                prev = arr[i];
            }
        }
        i++;
    }
    if(cows==0)// we were able to place the cows
        return true;
    else {
        cout<<"Sorry, not able to place the cows at "<<gap<<" minimum distance in array.\n";
        return false;
    }
}
lli aggressive_cow_solve(lli s,lli e, lli n, lli c, lli *arr){
    lli ans , mid;
    while(s<=e){
        mid = (s+e)/2;
        if(valid(mid,c,n,arr)==true){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int main()
{   ios::sync_with_stdio(false);
    in(t);
    while(t--){
        in(n);
        in(c);
        lli arr[n];
        lli min,max;
        max = -1;
        min = 1e18;
        for0(n)
            {cin>>arr[i];
            if(arr[i]<min) min = arr[i];
            if(arr[i]>max) max = arr[i];}
        sort(arr,arr+n);

        // now i need to firstly find my bounds for the search space in my test case
        lli end = max - min;// this is the  bound for my searchspace.
        lli ans = aggressive_cow_solve(0,end,n,c,arr);
        cout<<ans<<endl;
    }
    return 0;
}
