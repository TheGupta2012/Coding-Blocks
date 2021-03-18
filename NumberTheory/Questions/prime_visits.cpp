#include<bits/stdc++.h>
using namespace std;
bitset <10000000> b;
vector <long int> primes(500000);
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
{
    int t;
    cin>>t;
    sieve();

    while(t--)
    {
        long int a,b;
        cin>>a>>b;
        int pos1 = upper_bound(primes.begin(),primes.end(),a) - primes.begin();
        int pos2 = upper_bound(primes.begin(),primes.end(),b) - primes.begin();
        if(primes[pos1-1]!=a && primes[pos2-1]!=b)
            cout<<pos2-pos1<<endl;
        else
        {
            if((primes[pos1-1]==a &&primes[pos2-1]!=b) || (primes[pos1-1]==a &&primes[pos2-1]==b))
                cout<<pos2-pos1+1<<endl;
            else if(primes[pos1-1]!=a && primes[pos2-1]==b)
                cout<<pos2-pos1<<endl;
        }
    }
    return 0;
}
