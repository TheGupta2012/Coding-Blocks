#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long int lli;
vector <lli> primes;
bool p[1000005];
void sieve()
{   for(int i=0;i<=1000000;i++)
        p[i]= true;
    for(int i=4;i<=1000000;i+=2)
        p[i]= false;
    p[2] = true;
    p[0] = p[1] = false;
    primes.push_back(2);
    for(lli i=3;i<=1000000;i+=2)
    {
        if(p[i]==true)
        {   primes.push_back(i);
            for(lli j= i*i ; j<=1000000;j+=i)
            {
                p[j] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    sieve();
    // primes vector generated.
    // this is another optimization.
    // we only check the PRIMES UP UNTIL THE VALUE OF SQRT(N) AS EG. IF 2 is included
    // 4 can't ever become a prime factor as it is not PRIME and hence we don't need
    // to check for 4.
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        set<lli> factors;
        factors.insert(n);
        factors.insert(1);
        for(int i =0;primes[i]*primes[i]<=(n);i++)
        {
            if(n%primes[i] == 0)
            {
                while(n%primes[i]==0)
                    {factors.insert(primes[i]);
                    n = n/primes[i];}
            }
        }
        if(n!=1) // important
            factors.insert(n);
        if(factors.size()==3)   cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}
