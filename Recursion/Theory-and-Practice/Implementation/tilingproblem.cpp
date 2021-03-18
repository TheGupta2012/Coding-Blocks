#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int tiling(int n, unordered_map<lli,lli> &memo)
// using dp to speed up
{   if(n<=0)
        return 0;
    if(n<4)
        return 1;
    if(n==4)
        return 2;
    if(memo.find(n)!=memo.end())
        return memo[n];
    memo[n] = tiling(n-1,memo) + tiling(n-4,memo);
    return memo[n];
}
int main()
{
    cout<<"A tiling problem\n";
    cout<<" Given a wall of size 4 x n and tiles of size\n 1x4 and 4x1 , find how many ways you\n can build the wall?";
    cout<<"\nEnter n:";
    int n;
    cin>>n;
    unordered_map <lli,lli> memo;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 1;
    memo[4] = 2;
    cout<<"Total ways to make the wall is :"<<tiling(n,memo);
    return 0;
}
