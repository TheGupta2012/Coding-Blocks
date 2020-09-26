#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli findval(lli n, lli *arr, lli val)
{
    for(int i=0;i<n;i++)
        {
            if(arr[i]==val)
                return i;
        }
    return -1;
}
int main()
{
    lli n;
    cin>>n;
    if(n<=0)
        {cout<<"Enter atleast one element.";
        abort();}
    lli arr[n];
    vector<lli> v;
    v.reserve(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        v.push_back(arr[i]);
    }
    if(n>=129)
        {cout<<"Yes";
        }
    else
    {   lli val,pos ;
        bool flag = 0;
        sort(v.begin(),v.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                    for(int k=j+1;k<n;k++)
                        {
                            val = (arr[i]^arr[j])^arr[k];
                            if(binary_search(v.begin(),v.end(),val))
                                {   pos = findval(n,arr,val);
                                    if(pos>k)
                                    {flag = true;
                                    break;}
                                }
                            else
                                {
                                    continue;
                                }
                        }
                    if(flag==true)
                        break;
                }
            if(flag==true)
                break;
        }
        if(flag==true) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}
