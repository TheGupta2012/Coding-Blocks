#include<bits/stdc++.h>
using namespace std;
// while(i<=j)
//     dp[i][j] = max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
typedef long long int lli;
lli dp[100][100];
lli optimalChoice(int i,int j,lli *arr){
    if(i>j)
        return 0;
    if(j==i+1){
        return (max(a[i],a[j]));
    }
    else{
        // recursion left.
        dp[i][j] = ans;
        return ans;
    }
}
int main(){
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){
            dp[i][j] = -1;
       }
    }
    int n;
    cin>>n;
    lli values[n];
    long int ele;
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    cout<<optimalChoice(0,n-1,values);
    return 0;
}
