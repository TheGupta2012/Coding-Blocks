#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
map <lli,lli> factor;
void prime_fact(lli n)
{
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                {
                    factor[i]++;
                    n = n/i;
                }
        }
    }
    if(n!=1) factor[n] = 1;
}
int main()
{
    ios::sync_with_stdio(0);
    // optimization for calculating the rpime factors of a number.
    lli n;
    cout<<"Enter the number:";
    cin>>n;
    prime_fact(n);
    for(auto k:factor)
        cout<<k.first<<":"<<k.second<<endl;
    return 0;
}
