#include<bits/stdc++.h>
using namespace std;
long int fast_power(int a,int n)
{
    long int prod = a;
    long int ans = 1;
    while(n>0)
    {
        if((n&1)==1)
            ans = ans*prod;
        prod = prod*prod;
        n = n>>1;
    }
    return ans;
}
int main()
{
    long int n;
    //cout<<"Enter the number :";
    cin>>n;
    long int a;
    //cout<<"Enter the base :";
    cin>>a;
    cout<<fast_power(n,a);
    return 0;
}
