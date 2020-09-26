#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> primes;
bitset<100000> b;
void sieve()
{
    for(lli i=0;i<=100000;i++)
        b[i] = 1;

    //mark all as prime
    for(lli i=4;i<=100000;i+=2)
        b[i] = 0; // all even as non prime
    b[2] = 1;
    b[0] = b[1] = 0;

    for(lli i=2;i<=100000;i++)
    {
        if(b[i]==1)
        {   primes.push_back(i);
            for(lli j=2*i;j<=100000;j+=i)
                b[j] = 0;
        }
    }
}
int main()
{   sieve();
    lli n,q,k;
    cin>>n;
    lli arr[n];
    lli max = -1;
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        if(arr[i]>max) max= arr[i];
    }
    
    //let's construct an array stating how many times
    // a number appears as a divisor for any of the
    // number in the array.
    unordered_map <lli,lli> appear;
    cin>>q;
    while(q--)
    {
        cin>>k;
        cout<<appear[k]<<endl;
    }
    return 0;
}
