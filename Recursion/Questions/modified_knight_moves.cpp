#include<bits/stdc++.h>
#include<cmath>
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
typedef unordered_map <lli,lli> umap;
typedef priority_queue<lli> pq;
typedef pair <lli, lli> pi;
bitset<10000000> p;
bool sieve_made = false;
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
void sieve()
{   sieve_made=true;
    p[0] = p[1] = 0;
    p[2] = 1;
    for(lli i=4;i<=1000000;i+=2)
        p[i] = 0;
    for(lli i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(lli j=i*i;j<=1000000;j+=i)
                p[j] = 0;
        }
    }
}
bool prime(lli n)
{
    if(sieve_made==true)
    {
        if(n<10000000)
            return (p[n]);
        else{
             for(int i=2;i<=sqrt(n);i++)
                    if(n%i==0) return false;
            return true;
        }
    }
    for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
    return true;
}
map <lli,lli> factor;
void prime_fact(lli n)
{
    for(int i=2;i<=int(sqrt(n));i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                {
                    factor[i]++;
                    n = n/i;
                }
        }
    }
    if(n!=1) factor[n] = 1;
}
lli ans;
void solve(lli i,lli j,lli n,vvi &board,lli count){
    //base case
    if(i<0 || j<0 || i>=n || j>=n){
        return ;
    }
    if(board[i][j] == 0)
        return ;
    // if(visit[i][j]==1 || visit[i][j]==-1)// -1 for zeroes and 1 for visited ones.
    //     return ;
    // //recurse
    // visit[i][j] = 1;// need to just mark the ones that are reachable and then count the ones
                    // which are not visited.
      ans = max(ans,count+1);// +1 as initially we passed zero.
      board[i][j] = 0;
      solve(i+2,j+1,n,board,count+1);//down and right
      solve(i+2,j-1,n,board,count+1);//down and left
      solve(i-2,j+1,n,board,count+1);//up and right
      solve(i-2,j-1,n,board,count+1);//up and left
      solve(i+1,j+2,n,board,count+1);//right and down
      solve(i-1,j+2,n,board,count+1);//right and up
      solve(i+1,j-2,n,board,count+1);//left and down
      solve(i-1,j-2,n,board,count+1);//left and up
      board[i][j]=1;// backtrack
}
int main()
{   ios::sync_with_stdio(false);
    ans = -1;
    in(n);
    vvi board(n,vi(n));
    lli ones = 0;
    for0(i,n){
        for0(j,n){
            in(ele);
            if(ele==1) ones++;
            board[i][j] = ele;
        }
    }
    lli c = 0;
    solve(0,0,n,board,c);
    cout<<ones-ans;// total ones - maximum reachable ones.
    return 0;
}
