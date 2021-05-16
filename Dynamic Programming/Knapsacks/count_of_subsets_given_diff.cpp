#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int count_subsets_sum(int n, int *arr,int target){

    // init dp 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
                if(i==0) dp[i][j] = 0;

                if(j==0) dp[i][j] = 1;
        }
    }

    //code 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1] <= j){
                // + because we want all ways > if we included and got the sum 
                // or if we excluded and got the sum 

                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}
int main(){
    ios::sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    cout<<"Enter size of array :";
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    cout<<"Enter elements ";
    for(int i=0;i<n;i++)    
        {cin>>arr[i];
        sum+=arr[i];}

    cout<<"Enter the target difference :";
    int diff;
    cin>>diff;

    // note -> s1 - s2 = target 
    // but also, the sum MUST equal to the total sum 
    // s1 + s2 = total 

    // -> this then reduces to s1 = (diff + target)/2 

    int target = (diff + sum)/2;

    int ans = count_subsets_sum(n,arr,target);
    cout<<ans;

    return 0;
}