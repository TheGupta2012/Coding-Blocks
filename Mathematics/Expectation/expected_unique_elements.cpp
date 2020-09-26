#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    if(n==1)
    {   long long int ele;
        cin>>ele;
        float res = 1.0;
        cout<<fixed<<setprecision(6)<<1.0;
        return 0;
    }
    long int ele;
    unordered_map <long int,long int> last;
    double sum = 0.0;
    long long int ans = 0;
    for(int i=1;i<=n;i++)
        {
        cin>>ele;
        if(i==1) ans = 1;
        else ans = ans + i - last[ele];
        last[ele] = i;
        sum+= ans;
     }
    double final = 0.0;
    final = (2*(sum-n) + n)/(n*n*1.0);
    cout<<fixed<<setprecision(6)<<final;
    return 0;
}
