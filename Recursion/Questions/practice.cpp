#include<bits/stdc++.h>
using namespace std;
int solve(int n,int i,int *arr,int s,int curr){
    long int res = 0;
    if(curr>s) return 0;// curr is current sum
    if(curr==s){
        return 1;
    }
    //base
    if(i>=n){
        return 0;
    }
    //recurse
    else{
        if(arr[i]+curr<=s){// don't increment i yet.
            res = res + solve(n,i,arr,s,curr+arr[i]);
        }
        res = res+ solve(n,i+1,arr,s,curr);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n]; // coin denomiantion
    int sum;
    cin>>sum;
    long long int dp[n][m]={0};
    //set<int> s;
    for(int i=0;i<n;i++)
        {cin>>arr[i];} // only unique needed.
    sort(arr,arr+n);
    cout<<solve(n,0,arr,sum,0,dp);
    return 0;
}
