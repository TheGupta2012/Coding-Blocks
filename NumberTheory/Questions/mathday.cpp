#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli fast_expo(lli a,lli b, lli m)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res = (res*p)%m;
        p = (p*p)%m;

        b >>=1;
    }
    return res;
}
int main()
{   ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
    lli n,a,p;
    cin>>a>>n>>p;
    lli ans = (a%p);
    for(lli i = 2;i<=n;i++)
        ans = fast_expo(ans,i,p);
    cout<<ans<<endl;
    }
    return 0;
}
