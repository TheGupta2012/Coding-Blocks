#include<bits/stdc++.h>
#include<cmath>
#define MAX 100000
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
int* hash_array(int A[], int n)
{   // count only increments upto the number of distinct elements in the
    // array .
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++)
        hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {   cout<<"Pass "<<i+1<<endl;
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            for(int i=0;i<MAX;i++){
                if(hash[i]!=-1)
                    cout<<i<<":"<<hash[i]<<endl;
            }
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
        for(int i=0;i<MAX;i++){
            if(hash[i]!=-1)
                cout<<i<<":"<<hash[i]<<endl;
        }
    }
    return hash;
}// think more!...
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    lli ele;
    vi v;
    v.reserve(n);
    map <lli,lli> m;
    for0(n)
    {
        cin>>ele;
        m[i] = ele;
        if(i==0)
            {v.push_back(ele);
            continue;}
        if(v[i-1]!=ele)
            v.push_back(ele);
    }
    if(v.size()==n)
        {
            for(auto k:m)
                cout<<k.second<<"\n";
        }
    else{
        // non - unique...
        
    }
    return 0;
}
