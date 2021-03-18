#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{   ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {   vector<lli> res;
        int a,b,q;
        cin>>a>>b>>q;
        lli l,r;
        int arr[a*b];
        int cycle= 0; // this will contain the numbers in one cycle of 0-> (a*b - 1).
        for(int i=0;i<(a*b);i++)
        {
            if ( ((i%b)%a)==((i%a)%b) )
                {cycle++;
                // cout<<"No is :"<<i<<endl;
                arr[i] = 1;
                }
            else arr[i] = 0;
        }
        int prefix[a*b]={0};
        prefix[0] = arr[0];
        for(int i=1;i<a*b;i++) // important to generate prefix array.
            prefix[i] = prefix[i-1]+arr[i];
        while(q--)
        {
            cin>>l>>r;
            // subtract the numbers which are l<=x<=r and x%a % b = x%b % a.
            lli right = (r/(a*b)) * cycle;
            // the number of numbers satisfying the condition less than [r/ab]ab.
            lli rleft = r%(a*b);
            lli left = ((l-1)/(a*b)) * cycle;
            // the number of numbers satisfying the condition less than [l/ab]ab.
            lli lleft = (l-1)%(a*b);
            lli rightend = (a*b)*(r/(a*b));
            lli leftend = (a*b)*((l-1)/(a*b));
            right+= prefix[rleft];
            left+= prefix[lleft];
            res.push_back(r-l+1-(right-left));
        }
        for(auto k:res)
            cout<<k<<" ";
        cout<<endl;
    }
    return 0;
}
