#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli stringToInt(int n,string s)
{   lli res = 0;
    if(n<=0) // base case
        return 0;
    lli dig = s[n-1] - '0';
    cout<<"Current n is "<<n<<endl;
    cout<<"Current digit is "<<dig<<endl;

    // recursive case.
    res = stringToInt(n-1,s)*10 + dig;
    // another way, res = stringToInt(n-1,s,pow*10) + dig*pow;
    // but the used method has a better complexity as we are only
    // multiplying once.
    cout<<"Result pertaining to this n="<<n<<" is "<<res<<endl;
    return res;
}
int main()
{
    string a;
    cin>>a;
    int n = a.size();// n denotes the last
    //index to be refered to
    cout<<stringToInt(n,a);
    return 0;
}
