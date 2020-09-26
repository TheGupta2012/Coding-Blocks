#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gcd(lli a,lli b)
{
    if(b==0)
        return a;
    else {
        return gcd(b,a%b);
    }
}
void extend_euclid(lli a,lli b,lli *x,lli *y)// using reference method.
{
    if(b==0)
    {   //base case.
        //cout<<"Base A:"<<a<<" B:"<<b<<endl;
        *x = 1;
        *y = 0;
        return ;
    }
    else{
        // recurse
        extend_euclid(b,a%b,x,y);

        lli temp1,temp2;
        temp1 = *x;
        temp2 = *y;
        //cout<<temp1<<","<<temp2<<endl;
        //cout<<"A:"<<a<<"B:"<<b<<endl;
        *x = temp2; // this is just x[i-1] = y[i]
        *y = temp1 - (a/b)*(temp2);// this is y[i-1] = x[i] - (a/b)*y[i]
    }
}
pair<lli,lli> solve(lli a,lli b)
{
    lli x,y;
    extend_euclid(a,b,&x,&y);
    pair<lli,lli> res;
    res.first = x;
    res.second = y;
    return res;
}
lli mod_inv(lli a,lli m)
{
    if(gcd(a,m)!=1)
        return -1;
    else
    {
        pair<lli,lli> res = solve(a,m);
        return (res.first+m)%m;
    }
}
int main()
{
    lli n,p,w,d;
    cin>>n>>p>>w>>d;
    lli x,y;
    lli g = gcd(w,d);
    if(p%g!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n*w < p)
        {   // even if we win all the matches and we couldn't match the
            // required criteria.
            cout<<-1<<endl;
            return 0;
        }
    else //complete it.
    {
        w = w/g;
        d = d/g;
        p = p/g;
        // note that i have divided d and w by their gcd and now they have become co-prime.
        // thus mod inv would exist as their gcd would be 1. Also, this would be the least value
        // of y which is positive. y can't be reduced further.
        y = ((p%w)*mod_inv(d,w))%w;
        x = (p - d*y)/(w);
        if(x<0)
            cout<<-1<<endl;
        else if(x+y>n)
            cout<<-1<<endl;
        else
            cout<<x<<" "<<y<<" "<<n-x-y<<endl;
    }
    return 0;
}
