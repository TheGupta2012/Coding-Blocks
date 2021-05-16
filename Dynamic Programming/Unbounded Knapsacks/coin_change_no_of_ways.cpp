#include<bits/stdc++.h>
#include<cmath>
#define pb(x) push_back(x)
#define umap unordered_map
#define print_arr_like(x) for(auto k:x) cout<<k<<" "
#define print_map_like(x) for(auto k:x)\
                            cout<<k.first<<":"<<k.second<<"\n"
#define make_lower(s) transform(all(s),s.begin(),::tolower)
#define make_upper(s) transform(all(s),s.begin(),::toupper)
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(i,n) for(lli i=0;i<n;i++)
#define for1(i,n) for(lli i=1;i<=n;i++)
#define mod 1000000007
#define asc_ord_set tree< lli , null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define desc_ord_set tree< lli , null_type, greater<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define key_position(k,o) o.order_of_key(k)
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int lli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef priority_queue<lli> max_pq;
typedef priority_queue<lli,vi, greater<lli> > min_pq;
typedef pair <lli, lli> pi;
lli gcd(lli a,lli b){
if(b == 0)
return a;
else
return gcd(b,a%b);
}
lli lcm(lli a,lli b){
lli g = gcd(a,b);
return (a*b)/g;
}
lli fast_power(lli a,lli b)
{
    lli p = a;
    lli res = 1;
    while(b>0)
    {
        if(b&1)
            res*= p;
        p= p*p;
        b= b>>1;
    }
    return res;
}
lli dp[1005][1005];
lli solve_coin_change(lli n,lli *coins,lli target){
    // init the dp 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            // no element means no ways, when sum > 0
            if(i==0) dp[i][j] = 0;

            // zero sum means atleast one way - null set
            if(j==0) dp[i][j] = 1;
        }
    }

    // code 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            // if you can take the element 
            if(coins[i-1] <= j){
                // take the ele, try to again take it

                // not take the element and go ahead

                // add all ways...
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }

            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][target];
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    cout<<"Enter the number of coins :";
    in(n);
    lli coins[n];
    
    cout<<"Enter the denominations :";
    for0(i,n)
        cin>>coins[i];

    cout<<"Enter the target money :";
    in(target);

    memset(dp,-1,sizeof(dp));

    lli ans = solve_coin_change(n,coins,target);
    cout<<"Number of ways is :"<<ans;
    return 0;
}