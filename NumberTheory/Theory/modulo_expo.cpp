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
        // this is a crucial step.
        //( res%m * p%m ) %m , the res%m part is being calculated in the line where res
        // is being updated.
        // the p%m part for the next term is calculated in the last iteration.
        b >>=1;
    }
    return res;
}
int main()
{   ios::sync_with_stdio(0);

    lli a,b,c;
    cin>>a>>b>>c;
	cout<<fast_expo(a,b,c);
return 0;
}
