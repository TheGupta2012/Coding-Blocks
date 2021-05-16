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
int dp[1001][1001];
bool solve(int i,lli n,lli *arr,lli total){
    if(total == 0){
        dp[i][total] = true;
        return true;
    }
    if(i>=n)
        return false;

    bool take,leave;

    if(dp[i][total] != -1)
        return dp[i][total];

    if(arr[i] <= total)
         take = solve(i+1,n,arr,total-arr[i]);

    if(take == true)
        {dp[i][total] = true;
        return true;}
    
    leave = solve(i+1,n,arr,total);

    if(leave == true)
        {dp[i][total] = true;
        return true;}
    
    dp[i][total] = false;
    return false;
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    memset(dp,-1,sizeof(dp));
    cout<<"Enter number of elements :";
    in(n);
    cout<<"Enter the elements :";
    lli arr[n];

    for0(i,n)   
        cin>>arr[i];
    
    cout<<"Enter the target sum :";
    in(total);

    bool ans = solve(0,n,arr,total);
    if(ans == true)
        cout<<"YES";
    else 
        cout<<"NO";
    return 0;
}