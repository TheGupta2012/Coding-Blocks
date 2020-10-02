#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
lli  gcd(lli   a,lli  b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void extend_euclid(lli a,lli b,lli *x,lli *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return;
    }
    else{
        extend_euclid(b,a%b,x,y);
        lli t1,t2;
        t1 = *x;
        t2 = *y; // *x and *y are the values that were returned from the
        // bottom tier.
        *x = t2;// update x
        *y = t1 - (a/b)*t2;// update y
    }
}
lli help_euclid(lli a,lli b)
{   // just return x corresponding to the equation Ax + By = GCD(A,B)
    lli x,y;
    extend_euclid(a,b,&x,&y);
    return x;
}
lli mod_inverse(lli a,lli m)
{
    lli b = help_euclid(a,m);
    return (b+m)%m;
}
int main()
{
    lli n,r;
    cin>>n>>r;
    if(r>n/2)
        r = n-r;
    lli mod = 1000000007;
    lli num = 1;
    lli den = 1;
    for(int i=n;i>(n-r);i--)
        {
            num = (num%mod*(i%mod))%mod;
        }
    for(int i=1;i<=r;i++)
        {
            den = (den%mod * (i%mod))%mod;
        }
    lli res = (num%mod * mod_inverse(den,mod)%mod)%mod;
    cout<<res;
}
