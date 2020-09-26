#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int q;
    cin>>q;
    vector< pair< long long int, long long int> > v;
    v.reserve(q+1);
    unordered_map<long long int,long long int> m;
    while(q--)
    {   long long int a,b;
        cin>>a>>b;
        long long int ans = 0;
        for(int i=a;i<=b;i++)
        {
            if(m.find(i)!=m.end())
                ans+=m[i];
            else
            {m[i] = __builtin_popcount(i);
            ans+= m[i];}
        }
        cout<<ans<<endl;
    }
    return 0;
}
