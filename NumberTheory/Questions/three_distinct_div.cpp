#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long int lli;
vector <lli> primes;
bool p[100005];
void sieve()
{   for(int i=0;i<=100000;i++)
        p[i]= true;
    for(int i=4;i<=100000;i+=2)
        p[i]= false;
    p[2] = true;
    p[0] = p[1] = false;
    primes.push_back(2);
    for(lli i=3;i<=100000;i+=2)
    {
        if(p[i]==true)
        {   primes.push_back(i);
            for(lli j= i*i ; j<=100000;j+=i)
            {
                p[j] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    sieve();
    // primes vector generated.
    // this is another optimization.
    // we only check the PRIMES UP UNTIL THE VALUE OF SQRT(N) AS EG. IF 2 is included
    // 4 can't ever become a prime factor as it is not PRIME and hence we don't need
    // to check for 4.
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        lli temp = n;
        map<lli,lli> factors;
        for(int i =0;primes[i]*primes[i]<=(temp);i++)
        {
            if(temp%primes[i] == 0)
            {
                while(temp%primes[i]==0)
                    {factors[primes[i]]++;
                    temp = temp/primes[i];}
            }
        }
        if(temp!=1) // important
            factors[temp]++;
        //cout<<"Factors are:\n";
        lli divisors = 1;
        for(auto k:factors)
            {
            //cout<<k.first<<":"<<k.second<<endl;
            divisors *= (k.second+1);
            }
        vector< pair<lli,lli> > factor(factors.begin(),factors.end());
        if(factor.size()<3)
            {
                if(factor.size()==1)//single factor.
                    {   lli f = factor[0].first;
                        if(factor[0].second>=6 && (n/(f*f*f))!=1) // because all must be distinct
                            cout<<"YES\n"<<f<<" "<<f*f<<" "<<(n)/(f*f*f)<<endl;
                        else
                            cout<<"NO\n";
                    }
                else if(factor.size()==2)
                    {   lli a,b;
                        a = factor[0].first;
                        b = factor[1].first;
                        lli f = (n)/(a * b);
                        // find if n/(ab) equal to a or b.
                        if(f!=a && f!=b && f!=1)
                            cout<<"YES\n"<<a<<" "<<b<<" "<<f<<endl;
                        else
                            cout<<"NO\n";
                    }
                else
                    cout<<"NO\n";
            }
        else
        {
            cout<<"YES\n";
            lli a,b;
            a = factor[0].first;
            b = factor[1].first;
            cout<<a<<" "<<b<<" "<<n/(a*b)<<endl;
        }

    }
    return 0;
}
