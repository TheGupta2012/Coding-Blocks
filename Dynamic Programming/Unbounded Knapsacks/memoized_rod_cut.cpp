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
lli solve(lli n, lli *prices,lli *length,lli total){
    if(n == 0 || total == 0)
        return 0;
    
    if(dp[n][total]!=-1){
        return dp[n][total];
    }

    else{
        if(length[n-1]<=total){
            dp[n][total] = max(prices[n-1] + solve(n,prices,length,total - length[n-1]),solve(n-1,prices,length,total));
        }
        else{
            dp[n][total] = solve(n-1,prices,length,total);

        }

        return dp[n][total];
    }
}

void get_rod_cuts(lli n,vi &arrange){
    lli i = n, j = n;
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j]) // this element wasn't included 
            i--;
        else {
            // this element was included with a length i 
            // and still tried to include it by going back 
            // in its own row
            arrange.pb(i);
            j-=i;
        }
    }
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    
    cout<<"Enter the size of rod :";
    in(n);
    memset(dp,-1,sizeof(dp));
    cout<<"Enter the price of the pieces by weight :";
    lli prices[n],length[n];
    for0(i,n)
        {cin>>prices[i];
        length[i] = i+1;
        dp[i][0] = 0;
        dp[0][i] = 0;
        }
    dp[0][n] = dp[n][0] = 0;

    lli ans = solve(n,prices,length,n);

    cout<<"The maximal profit is :"<<ans;
    vi arrange;
    get_rod_cuts(n,arrange);
    cout<<"\nThe best arrangement is :";
    print_arr_like(arrange);
    cout<<endl;
    return 0;
}