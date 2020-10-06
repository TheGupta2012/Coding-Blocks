#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long int lli;
map <lli,lli> factor;
lli fast_power(lli a,lli b)
{
    lli res = 1,p=a;
    while(b>0)
    {
        if(b&1)
            res = res*p;
        p = p*p;
        b = b>>1;
    }
    return res;

}
lli find_sum(lli n)
{   lli res = 1LL,size;
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                factor[i]++;
                n = n/i;
            }
             size = factor[i];
             res *= ((fast_power(i,size+1)-1)/(i-1));
        }
    }
    if(n!=1)
        {factor[n]++;
        size = factor[n];
        res*= ((fast_power(n,size+1)-1)/(n-1));}
    return res;
}
int main()
{   ios::sync_with_stdio(0);
    lli s;
    bool flag;
    map <lli,lli> sums;
    for(int i=1;i<=100000;i++)
    {
        sums[find_sum(i)] = i; // this would overwrite the sums map with the largest integer
		// with sum s.
        factor.clear();
    }
    // this now has sums associated with their number n.
    while(1){
        cin>>s;
        if(s==0) break;
        if(sums.find(s)!=sums.end())
           cout<<sums[s]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
