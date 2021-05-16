#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the number of elements :";
    int n;
    cin>>n;

    cout<<"Enter the elements :";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the target sum :";
    int target;
    cin>>target;

    int dp[n+1][target+1];

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            // if no element present, no way to make 
            if(i == 0) dp[i][j] = 0;

            // there is ak zero sum subset always
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){

            // check , does this element come
            if(arr[i-1] <= j){
                // take all ways possible! 
                // very cool ...
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }

            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<"Total number of subsets is :"<<dp[n][target];
    return 0;
}