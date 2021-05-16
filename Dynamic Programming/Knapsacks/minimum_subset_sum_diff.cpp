#include<bits/stdc++.h>
using namespace std;
int dp[105][105];

void subset_sum(int n, int *arr, int total){
    // initialize the dp 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    // iterate for the subset sum 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=total;j++){

            if(arr[i-1] <= j){
                // if we can place the element then good 
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :";
    int total = 0;
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        total+= arr[i];}

    // range is -> [0,total]

    // make a subset sum call over the problem 
    // total/2 

    // minimizing |s1 - s2| or |total - 2*s1|


        memset(dp,-1,sizeof(dp));
        int target = total/2;
        subset_sum(n,arr,target);

        // after you have the DP array 
        // you iterate from behind 

        // for(int j=0;j<=target;j++){
        //     cout<<"sum "<<j<<":";
        //     dp[n][j]?cout<<"true":cout<<"false";
        //     cout<<endl;
        // }
        int ans;
        for(int j=target;j>=0;j--){
            if(dp[n][j] == true){
                ans = total - 2*j;
                break;
            }
        }
 
        cout<<ans;
    

    return 0;
}