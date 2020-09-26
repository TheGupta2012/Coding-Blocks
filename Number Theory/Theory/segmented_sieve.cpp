#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli n = 100000;
bool p[n+1];
vector< lli > primes;
void sieve()
{
    for(lli i=3;i<=n;i+=2)
        p[i]= true;
    for(lli i=4;i<=n;i+=2)
        p[i] = false;
    // evens can't be primes.
    primes.push_back(2);
    p[2] = true;
    p[0] = p[1] = false;
    for(lli i=3;i<=n;i+=2)
    {
        if(p[i]==true)
        {   primes.push_back(i);
            for(lli j=i*i;j<=n;j+=i)
                {p[j] = false;}
        }
    }
}
int main()
{
    //make sieve
    ios::sync_with_stdio(0);
    sieve();
    lli t;
    cin>>t;
    // primes are here.
    // now make an  array of size n-m+1 which stores the primality of numbers from
    // [m,n].
    while(t--)
    {lli m,n;
    cin>>m>>n;
    bool nm[n-m+1];// interval array containing the primality of [m,n].
    // heart of the problem is the shifting of the range into another array of size n-m
    for(int i=0;i<n-m+1;i++)
        nm[i] = true;
        // true denotes the primes .
        // initially all are prime.
    lli start;
    for(auto f:primes)
    {
        if(f*f>n)
            break;// if the square of the prime is greater than the largest value of
        // the range then that means we don't need to check more. As for every number,
        // to check the primality,we need checking with primes only upto its root and surely
        // the number with a square greater than n will always be greater than the square root
        // of any number less than n and hence we would have checked up until there.

        // Calculate where you will start from.
        start = (m/f)*f; // () if the gif of c++. [m/f]*f will give us the starting point.

        if(f<=n && f>=m) // note for the prime number whether it lies in range or not.
            start = 2*f;
        // this is because you will have zero as the result eg. (1/2)*2 = 0, but you wanted
        // to start from number 4.
        for(lli i = start;i<=n;i+=f)
        {
            nm[i-m] = false;
        }
    }
    for(lli i = 0;i<n-m+1;i++)
    {
        if(nm[i]==true)
            { if(i+m!=1)
                cout<<i+m<<endl;}
    }
    cout<<endl;
}
    return 0;
}
