#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli power_mod(lli a,lli b,lli m)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res*p)%m;
        p = (p*p)%m;
        b = b>>1;
    }
    return res;
}
lli mod_inv(lli a,lli m)
{
    return power_mod(a,m-2,m);
}
int main()
{
    ios::sync_with_stdio(0);
    lli n;
    cin>>n;
    cout<<mod_inv(n,1000000007);
    return 0;
}
