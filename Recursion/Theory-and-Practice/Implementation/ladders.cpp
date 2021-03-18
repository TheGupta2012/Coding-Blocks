#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int tiling(int n, unordered_map<lli,lli> &memo)
// using dp to speed up
{  if(n<=0)
        return 0;
    if(memo.find(n)!=memo.end())
        return memo[n];
    memo[n] = tiling(n-1,memo) + tiling(n-2,memo) + tiling(n-3,memo);
    return memo[n];
}
int main()
{
    cout<<"A tiling problem\n";
    cout<<"If a person climbs a wall in 1,2 and 3 steps only,\n find how many ways he can climb the wall?";
    cout<<"\nEnter n:";
    int n;
    cin>>n;
    unordered_map <lli,lli> memo;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    cout<<"Total ways to climb the wall is :"<<tiling(n,memo);
    cout<<"\nThis problem can always be extended to solving \n for upto k length steps.\n";
    cout<<"\nThe recursion would just change to :\n";
    cout<<"f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + ... +f(n-k) where we say that f(0) = 1, one way to climb from the ground,\n and if n<0 then answer is 0.";
    return 0;
}
