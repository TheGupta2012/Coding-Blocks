#include<bits/stdc++.h>
#include<cmath>
#define tr(v,it) for(typeof(v.begin()) it = v.begin() ;it!=v.end();it++)
#define in(x) lli x; cin>>x
#define all(v) v.begin(),v.end()
#define for0(n) for(lli i=0;i<n;i++)
#define for1(n) for(lli i=1;i<=n;i++)
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
void bfs(int source,lli *dist, unordered_map <lli , list<lli> > adj){
    // distance of source is 0
    queue <int> q;
    bool visited[101] = {false};
    map < lli,lli > par;
    for(int i=1;i<=100;i++)
        par[i] = i;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        lli curr = q.front();
        for(auto k:adj[curr]){
            if(visited[k] == false){
                visited[k] = true;
                dist[k] = dist[curr] + 1;
                par[k] = curr;
                q.push(k);
            }
        }
        q.pop();
    }
    cout<<"The shortest path to the end is :";
    int temp = 100;
    while(par[temp]!=temp){
        cout<<temp<<"->";
        temp = par[temp];
    }
    cout<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    in(t);
    while(t--){
        int l,s;
        cin>>l;
        lli board[101] = {0};
        lli ladders[l][2];
        for0(l)
            {cin>>ladders[i][0]>>ladders[i][1];
            // the board will be indexed by the
            // ladder's foot
            board[ladders[i][0]] = ladders[i][1] - ladders[i][0];}
        cin>>s;
        lli snakes[s][2];
        for0(s)
            {cin>>snakes[i][0]>>snakes[i][1];
                // the board will be indexed by The
                // snake's head
            board[snakes[i][0]] = snakes[i][1] - snakes[i][0];}
        unordered_map <lli , list<lli> > adj;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=6;j++){
                if(i+j>100)
                    break;
                else{
                    // heart of the problem...
                    adj[i].push_back(i + j + board[i+j]);
                }
            }
        }
        // now just do bfs from 1 and find the distance
        // till 100.
        // done.
        lli dist[101] = {0};
        bfs(1,dist,adj);
        if(dist[100]>0)
            cout<<dist[100]<<endl;
        else
            cout<<-1<<endl;

    }
    return 0;
}
