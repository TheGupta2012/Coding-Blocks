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
bool comp(const pi &a,const pi &b){
    return a.first < b.first;
}
// correct ...
int main(){
    ios::sync_with_stdio(0);
    in(t);
    while(t--){
        in(n);
        lli d,f;
        // the distance are actually given from the
        // town, if we do town - d[i] then we get
        // the distance of the station from the truck
        vector <pi> stops;
        bool flag = 0;
        lli total = 0;
        for0(n){
            cin>>d;
            cin>>f;
            total+= f;
            stops.push_back({d,f});
        }
        in(town);
        in(capacity);
        for0(n)
            stops[i].first = town - stops[i].first;
        // making the distances all with respect to the truck
        if(capacity + total < town){
            // even if we make all the stops then also
            // we can't reach the town .
            cout<<-1<<endl;
            continue;
        }
        else{
            if(capacity>=town){
                cout<<0<<endl;
            }
            else{
                // main question
                pq p;
                sort(all(stops),comp);// wrt the truck distance
                lli x = 0;
                lli curr = capacity,dist;
                lli ans = 0;
                // to visit all fuel stations

                while(x<n){
                    if(x>0)
                        dist = stops[x].first - stops[x-1].first;
                    else
                        dist = stops[x].first;
                    if((curr-dist)>=0)
                    {   // means I can reach atleast this
                        // station
                        p.push(stops[x].second);
                        // store that fuel tank
                        curr = curr-dist;
                        // capacity decreases
                    }
                    else{
                        // means we can exactly reach
                        // that stop and no further
                        if(p.empty()){
                            flag = 1;
                            break;
                        }
                        lli add = p.top();
                        p.pop();
                        curr += add;
                        ans++;
                        continue;
                    }
                    x++;
                }
                // now we have reached the last station
                // with the capacity curr
                // visit the town...
                while((town - stops[n-1].first)>curr){
                    if(p.empty())
                    {
                        flag = 1;
                        break;
                    }
                    curr+=p.top();
                    p.pop();
                    ans++;
                }
                if(flag==0)
                cout<<ans<<endl;
                else
                cout<<-1<<endl;
            }
        }
    }

    return 0;
}
