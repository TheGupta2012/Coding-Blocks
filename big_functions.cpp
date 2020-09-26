#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,m;
    long long int i =0;
    cin>>a>>m;
    while(a%m!=0 && i<1e6)
    {
        a = a + a%m;
        i++;
    }
    if(i!=1e6) cout<<"Yes";
    else cout<<"No";
    return 0;
}
