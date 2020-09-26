// no of coin tosses required for getting n consecutive heads
#include<bits/stdc++.h>
using namespace std;
long long int fast_expo(lli n)
{
    lli res = 1;
    lli prod = 2;
    while(n>0)
    {
        if(n&1)
        {
            res= res*prod;
        }
        prod = prod*prod;
        n = n>>1;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    long int res = fast_expo(n+1);
    // formula is 2^(n+1) - 2.
    cout<<res-2;
    return 0;
}
