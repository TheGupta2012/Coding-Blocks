#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli pairing(lli n, unordered_map<lli,lli> memo)
{
    if(n==0)
        return 0 ;
    if(n==1)
        return 1;
    if(memo.find(n)!=memo.end())
        return memo[n];
    memo[n] = pairing(n-1,memo) + (n-1)*(pairing(n-2,memo));
    return memo[n];
}
int main()
{
    cout<<"Given N friends who want to go to a party on bikes.\n";
    cout<<"Each person can go single, or as a couple. Find number\n";
    cout<<"of ways they can go to the party.";
    cout<<"\nEnter n :";
    lli n;
    cin>>n;
    unordered_map <lli,lli> memo;
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    cout<<"The total ways are :"<<pairing(n,memo);
}
