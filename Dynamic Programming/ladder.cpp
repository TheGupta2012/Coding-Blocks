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
typedef priority_queue<lli> pq;
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
lli dp[10005];
lli top_down_solve(int n,int k){
    if(n<0) return 0;
    if(n == 0){
        dp[0] = 1;
        return dp[0];
    }
    else{
        // minimum number where we shall start ->. 
        if(dp[n]!=-1)
            return dp[n];
        dp[n] = 0;
        for1(i,k){
            dp[n] += top_down_solve(n-i,k);
        }
        return dp[n];
    }
}

// O(k*n)
lli bottom_up_solve(int n,int k){
    
    // dp[n] denotes the number of ways to reach n 
    
    dp[0] = dp[1] = 1;
    
    // correct...
    // FIRST FOR LOOP - replaces the recursive call for smaller n
    for(int j=2;j<=n;j++){ 
        // j represents the last step 
        dp[j] = 0; // reset the dp array 

        // i represents the allowable step sizes

        // j-i >=0 is very important
        for(int i=1; i<=k && j-i >=0 ;i++)
            dp[j] += dp[j-i];
    }

    return dp[n];
}

// what are we even doing in this though? 

// we are getting the sum of the immediately before 
// k elements.... why not prefix sums????? :) 

// better -> change the recurrence 

lli fastest_solve(int n,int k){
    dp[0] = 1;

    // for step <k, the answer for i 
    //  is sum of all answers that occur before i 
    // as ALL JUMPS POSSIBLE which is just 2*last answer.
    lli ways = 1LL;
    for(int step = 1;step<k;step++)
        {dp[step] = ways;
        ways*= 2;}

    // when you have enough steps, the recursion holds true 

    for(int step = k;step<=n;step++){
        // why step-1 -K ? because step-1 is n
            dp[step] = 2*dp[step-1] - dp[(step-1)-k];
    }

    return dp[n];
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    int n,k;
    cout<<"Enter last step :";
    cin>>n;
    cout<<"Enter the maximum jump size :";
    cin>>k;

    for0(i,10000)
        dp[i] = -1;
    // F(n) = F(n-1) + F(n-2) + ... + F(n-k)
    cout<<"Answer top-down:"<<top_down_solve(n,k);
    cout<<"\nAnswer bottom-up:"<<bottom_up_solve(n,k);
    cout<<"\nFastest answer:"<<fastest_solve(n,k);
    return 0;
}