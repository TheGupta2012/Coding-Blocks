#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    long long int l,r;
    cin>>l>>r;
    if(l==r)
        {cout<<0;
        return 0;}
    bitset <64> bs1(l);
    bitset <64> bs2(r);
    string s1 = bs1.to_string();
    string s2= bs2.to_string();
    //cout<<s1<<endl<<s2<<endl;
    long int shifts;
    for(int i=0;i<64;i++)
    {
        if(s1[i]==s2[i])
            continue;
        else
        {
            shifts = 64 - i ;// 
            //cout<<"Shifts:"<<shifts<<endl;
            break;
        }
    }
    long long int ans = (1LL<<shifts) - 1;
    cout<<ans;
    return 0;
}
