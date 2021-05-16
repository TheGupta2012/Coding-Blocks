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
int DP[1001][1001];

bool solve(lli n, lli *arr,lli total){
    // initialize the dp 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            if(i == 0) DP[i][j] = 0;

            if(j == 0) DP[i][j] = 1;
        }
    }

    // iterate for the subset sum 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=total;j++){

            if(arr[i] <= j){
                // if we can place the element then good 
                DP[i][j] = max(DP[i-1][j-arr[i]], DP[i-1][j]);
            }
            else 
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][total];
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    memset(DP,-1,sizeof(DP));
    cout<<"Enter number of elements :";
    in(n);
    cout<<"Enter the elements :";
    lli arr[n];
    lli total = 0LL;
    for0(i,n)   
        {cin>>arr[i];
        total+= arr[i];}

    if(total%2 == 1){
        cout<<"Not possible as total sum is odd.";
    }
    else{
    lli target = total/2;
    bool ans = solve(n,arr,target);
    if(ans == true)
        cout<<"YES";
    else 
        cout<<"NO";
    }
    
    return 0;
}


