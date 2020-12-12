#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef priority_queue<lli,vector<lli>,greater<lli>> pq;
// nicee!!...
int main(){
    ios::sync_with_stdio(0);
    lli t;
    cin>>t;
    while(t--){
        lli n ;
        cin>>n;
        lli c[n],l[n];
        for(int i=0;i<n;i++)
            cin>>c[i];
        for(int i=0;i<n;i++)
            cin>>l[i];
        // start with fuel =0;
        lli fuel = 0;
        lli ans = 0;
        pq p;
        for(int i=0;i<n;i++){
            p.push(c[i]);
            // basically agar atleast
            // l[i] fuel chahie to utna hi
            // lo but FROM THE FUEL STATION WITH THE
            // LOWEST COST ... NICEEEE!!!
            ans+= l[i]*p.top();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
