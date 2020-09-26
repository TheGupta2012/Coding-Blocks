#include<bits/stdc++.h>
using namespace std;
bitset <1000005> b;
void sieve()
{   b.set();
    b[0] = b[1] = 0;
    b[2] = 1;
    for(long long int i=4;i<=1000000;i+=2)
        b[i] = 0;
    for(long long int i=3;i<=1000000;i+=2)
    {
        if(b[i]==1)
        {
            for(long long int j=i*i;j<=1000000;j+=i)
                {b[j]=0;}
        }
    }

}
int main()
{
    int t;
    cin>>t;
    sieve();
    vector <int> primetill(1000005,0);
    for(long long int j=1;j<=1000000;j++)
        {primetill[j] = primetill[j-1] + b[j];}// important part is keeping a cummulative array of the primes up until
                                            // the ith number.
    while(t--)
    {
        int A,B;
        cin>>A>>B;
        cout<<primetill[B] - primetill[A-1]<<endl; // important as you want the primes upto just the A-1 number as
                                                    // A has to be included.

    }
    return 0;
}
