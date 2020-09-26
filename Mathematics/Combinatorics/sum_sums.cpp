#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod = 98765431;
lli fast(lli a, lli b)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res%mod * p%mod)%mod;
        p = (p%mod*p%mod)%mod;
        b = b>>1;
    }
    return res;
}
lli get_coeff(lli n,lli t)
{
    lli val = fast(n-1,t);
    if(t%2==0)
        return (1-val)/n;
    else
        return (1+val)/n;
}
int main()
{   ios::sync_with_stdio(0);
    lli n,t;
    cin>>n>>t;
    lli arr[n];
    lli sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum = (sum%mod + arr[i]%mod)%mod;
    }
    lli coeff = ((sum%mod)*(get_coeff(n,t)%mod))%mod;
    // each of the C(i,j) = C(0,j) - sum*((1-(1-n)^t)/
    for(int i=0;i<n;i++)
        cout<<(arr[i]%mod - coeff%mod + mod)%mod<<endl;
    return 0;
}
