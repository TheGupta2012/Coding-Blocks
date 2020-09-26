#include<bits/stdc++.h>
using namespace std;

long long int ack(long long int m,long long int n, map < pair<long long int,long long int> , long long int > dp)
{ long long int ans;
  if(dp.find({m,n})!=dp.end())
      return dp[{m,n}];
  if(m==0)
    {ans = n+1;
    dp.insert({{m,n},ans});}
  else if(n==0)
    {ans = ack(m-1,1,dp);
    dp.insert({{m,n},ans});}
  else
   {ans = ack(m-1,ack(m,n-1,dp),dp);
   dp.insert({{m,n},ans});}
  return ans;
}
int main()
{ map < pair<long long int,long long int> , long long int > dp;
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
        cout<<"Ackerrman of "<<i<<" "<<j<<" is "<<ack(i,j,dp)<<endl;
  }
  return 0;
}
