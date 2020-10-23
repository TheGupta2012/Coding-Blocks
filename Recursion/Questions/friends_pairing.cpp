#include<bits/stdc++.h>
using namespace std;
long long int friends_pairing(int n,long long int *dp){
    if(dp[n]!=0) return dp[n];
    else{
        dp[n] = friends_pairing(n-1,dp) + (n-1)*friends_pairing(n-2,dp);
		// heart of the problem
        return dp[n];
    }
}
int main(){
    int t;
    cin>>t;
    long long int dp[40]={0};
	dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    while(t--){
        int n;
        cin>>n;
        cout<<friends_pairing(n,dp)<<endl;
    }
    return 0;
}
