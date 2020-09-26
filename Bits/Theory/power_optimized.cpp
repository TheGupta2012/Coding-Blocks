#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
int fast_power(int a,int n)
{
    int x = a,bit;// x is the a variable
    int ans = 1;// answer
    while(n>0)
    {
        bit = n&1;
        if(bit==1)
        {  // only if bit is 1, the ans is multiplied by the number x
            ans*= x;
        }
        x *=x; // x is squared in each iteration
        n = n>>1; // n is right shifted to look at other bits.
    }
    return ans;
}
int main()
{
    int a,n;
    cout<<"Enter the base:";
    cin>>a;
    cout<<"Enter the power:";
    cin>>n;
    cout<<"Answer is :"<<fast_power(a,n);
    return 0;
}
