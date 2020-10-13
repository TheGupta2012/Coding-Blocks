#include<bits/stdc++.h>
using namespace std;
long long int dp[100];
long long int non_consec_ones(long long int n)
{
	if(dp[n]!=-1)
		return dp[n];
    else
    {
        dp[n] =  (non_consec_ones(n-1) + non_consec_ones(n-2));
		return dp[n];
    }
}
int main()
// almost same implementation of the optimal binary string question
// just with dynamic programming.
{	int t;
	cin>>t;
	dp[0] = 1;
	dp[1] = 2;
	for(int i=2;i<=95;i++)
		dp[i] = -1;
	 while(t--)
	{long long int n;
    cin>>n;
    cout<<non_consec_ones(n)<<endl;
	}
    return 0;
}
