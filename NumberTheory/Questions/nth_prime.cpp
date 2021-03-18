#include<bits/stdc++.h>
using namespace std;
bitset <10000000> b;
vector <long long int> primes;
void sieve()
{   b.set();
    b[0] = b[1] = 0;
    primes.push_back(2);
    for(long long int i=4;i<=10000000;i+=2)
        b[i] = 0;
    for(long long int i=3;i<=10000000;i+=2)
    {
        if(b[i]==1)
        {
            primes.push_back(i);
            for(long long int j=i*i;j<=10000000;j+=i)
                {b[j]=0;}
        }
    }
}

int main()
{   int n;
    sieve();
    cin>>n;
    cout<<primes[n-1];
    return 0;
}
