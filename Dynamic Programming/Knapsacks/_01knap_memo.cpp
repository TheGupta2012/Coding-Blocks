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
int t[1000][1000];
int knapsack(int *W, int *P, int max_cap, int n){

    if(n == 0 || max_cap == 0)
        return 0;
    else{
        if(t[n][max_cap] != -1)
            return t[n][max_cap];
        // if we can include the last item
        if(W[n-1] <= max_cap){
           
          t[n][max_cap] = max(P[n-1] + knapsack(W,P,max_cap - W[n-1],n-1), knapsack(W,P,max_cap,n-1));

          return t[n][max_cap];
          
        }

        // else if we can't 
        else{
            t[n][max_cap] = knapsack(W,P,max_cap,n-1);
            return t[n][max_cap];
        }

    }
}
int main()
{   ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif 
    int n;
    cout<<"Enter the size :";
    cin>>n;
    memset(t,-1,sizeof(t));
    int W[n],P[n];
    
    int wt,val;
    for0(i,n){
        wt = rand()%20+1;
        val = rand()%15+1;
        W[i] = wt;
        P[i] = val;
       
    }

    cout<<"Items are :\n";
    for0(i,n){
        cout<<"W"<<i+1<<":"<<W[i]<<" P"<<i+1<<":"<<P[i]<<endl;
    }
    int max_cap;
    cout<<"Enter the capacity :";
    cin>>max_cap;

    int profit = knapsack(W,P,max_cap,n);

    cout<<"Max profit is : "<<profit<<endl;
    return 0;
}