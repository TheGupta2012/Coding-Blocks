#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void eras_primes(lli n,int *p)
{
    for(int i=0;i<n+1;i++)
    {
        if(i%2==0) p[i] = 0;
        else p[i] = 1;
    }
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1) // it is a prime
        {
            for(int j = 2*i;j<=n;j+=i)
                {p[j] = 0;}
        }
    }
    // the sieve of eratosthenes.
    p[1] = 0;
    p[0] = 0;
}
int main()
{
    cout<<"Precomputing all the primes in a given range.\n";
    lli n;
    cin>>n;
    int p[n+1]={0};
    // 0 means not prime and 1 means prime
    eras_primes(n,p);
    for(int i=0;i<n+1;i++)
        {
            if(p[i])
                cout<<i<<" ";
        }
    return 0;
}
