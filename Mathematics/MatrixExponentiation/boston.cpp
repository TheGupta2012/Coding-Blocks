#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long int lli;
lli prime_fact(lli n)
{
    for(int i=2;i<=lli(sqrt(n));i++)
    {
        if(n%i==0)
            return i;
    }
    return n;
}
int main()
{lli n;
cin>>n;

lli temp1 = n;
lli temp2 = n;
lli p_sum,d_sum;
p_sum = d_sum = 0;
if(n==1)
    {cout<<1;
    return 0;}
while(temp1>1)
// getting the prime factors of n
{   lli factor = prime_fact(temp1);
    if (factor<10)
        p_sum += factor;
    else
    {
        lli temp3 = factor;
        while(temp3>0)
            {p_sum+= temp3%10;
            temp3 = temp3/10;}
    }
    temp1 = temp1/factor;
}
assert (temp1<=1);
while(temp2>0)
{
    d_sum+= temp2%10;
    temp2 = temp2/10;
}
assert (temp2>0);
if(d_sum==p_sum)
    cout<<1;
else
    cout<<0;
return 0;
}
