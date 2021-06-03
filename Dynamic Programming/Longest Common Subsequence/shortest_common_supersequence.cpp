#include<bits/stdc++.h>
using namespace std;
int dp[n+1][m+1];
int SCS(string s1,string s2){
    int n = s1.size();
    int m = s2.size();

    // first get the LCS 
    memset(dp,-1,sizeof(dp));

    //init 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // code 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // now you have the length of the LCS 

    return n + m - dp[n][m];
}
// printing SCS is easy - 
    // get the indices of LCS in the string 1 
    // and the indices of LCS in string 2 

    // in string 2 - take all the chars before first index of LCS in s2 and insert them just 
    // before index 1 in s1 

    // then, take all chars between index 1 and index2 of LCS in s2 and insert them just before 
    // index2 lof LCS in s1 and so on ...
int main(){
    ios::sync_with_stdio(0);
    string s1,s2;
    cout<<"Enter the string 1:";
    cin>>s1;
    cout<<"Enter the string 2:";
    cin>>s2;
    int ans = SCS(s1,s2);
    cout<<"The shortest common supersequence length is:";
    cout<<ans;
    cout<<"The shortest common supersequence is :";
    print_SCS(s1,s2);
    return 0;
}