#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    lli arr[n];
    lli xored = 0;
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        xored = xored^arr[i];}
    lli ans=-1;
    for(int i=0;i<n;i++){ // very simple solution, i like.
        ans = max(ans,xored^arr[i]); // this is because a^a = 0, and look did xor increase?
    }
    cout<<ans;
    return 0;
}
