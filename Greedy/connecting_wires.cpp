#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pi;
typedef vector<lli> vi;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cout<<"Enter the number of dots :";
    cin>>n;
    lli white[n],black[n];
    cout<<"Positions of white dots :";
    for(int i=0;i<n;i++)
        cin>>white[i];
    cout<<"Positions of black dots :";
    for(int i=0;i<n;i++)
        cin>>black[i];
    // now what can be the minimum for the first white dot
    sort(white,white+n);
    sort(black,black+n);
    // this is actually optimal
    // proof you thought of correctly!
    lli ans = 0;
    for(int j=0;j<n;j++)
        ans+= abs(white[j]-black[j]);
    cout<<"Minimum length is :"<<ans<<endl;
    return 0;
}
