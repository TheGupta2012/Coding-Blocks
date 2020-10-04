#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define all(v) v.begin(),v.end()
#define in(c) lli c; cin>>c
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
{   if(b<0)// just modifying for the question
      return 0;
    lli p = a;
    lli res = 1LL;
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
/*
QUESTION:
Alice is fond of playing mathematical games. This time he comes up with a unique game. He takes a number 'N' and calls magic fraction of N as:
-It is a proper fraction (The value is < 1)
-It cannot be reduced further
-The product of the numerator and the denominator is factorial of N. i.e. if a/b is the fraction, then a*b = N!
For example magic fractions for 3 are 2/3 and 1/6.

Now given a number N, you need to print the total number of magic fractions that exist, for all numbers from 1 till N (both inclusive).
*/
int main()
{
    in(n);
    lli res = 0,distinct;
    for(int i=1;i<=n;i++)
    {
        prime_fact(i); // generates the prime
        // factors of i! and appends them to factors map.
        // doing this as i want total magic fractions that
        // exist from 1 to n inclusive so i would need to
        // do it for 1!,2!,3!,4!,....
        distinct = factor.size();
        // at this point i have no of distinct prime factors in
        // i!.
        // any prime can go in numerator or the denominator.
        // so total choices 2^(distinct)
        // but numerator must be less than denominator hence
        // one of them MUST go in denominator.

        cout<<"Factors of "<<i<<"! are:\n";
        for(auto k:factor)
            cout<<k.first<<":"<<k.second<<endl;
        res += fast_power(2LL,distinct-1);
        cout<<"\nFor "<<i<<" no. of magic numbers are :"<<fast_power(2,distinct-1)<<endl;
    }

    cout<<"Total are: "<<res;
    return 0;
}
