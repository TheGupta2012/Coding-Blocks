#include<bits/stdc++.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {
    long int n;
    cin>>n;
    double res = 0;
    for(int i=1;i<=n;i++)
    {
        res = res+ 1.0/(i); // 1+ 1/2 + 1/3 + 1/4 +... + 1/n
    }
    cout<<fixed<<setprecision(2)<<res*n<<endl; // displaying n*(res)
    }
    return 0;
}
