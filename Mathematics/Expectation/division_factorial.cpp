#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long int lli;
lli prime_fact(lli n)
{
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
            return i;
    }
    return n;
}
int main()
{   ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
    lli n,k;
    cin>>n>>k;
    map <lli,lli> freq;
    lli temp2 = k;
    while(temp2>1)
    // getting the prime factors in 
    {   lli factor = prime_fact(temp2);
        freq[factor]+= 1;
        temp2 = temp2/factor;
    }
    cout<<"Factors are:\n";
    for(auto k:freq)
    {
        cout<<k.first<<":"<<k.second<<endl;
    }
    lli factor,multiplicity,ans;
    lli min = 1e10;
    for(auto k:freq)
    {   ans = 0 ;
        factor = k.first;
        multiplicity = k.second;
        lli temp = n;
        while(temp>0)
        {
            ans += temp/factor;
            temp = temp/factor;
        }
        ans = (ans/multiplicity) ;
        //cout<<"Answer for "<<factor<<":"<<ans<<endl;
        if(ans<min)
            min = ans;
    }
    cout<<min<<endl;
    }
    return 0;
}
