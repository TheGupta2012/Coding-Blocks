#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[100][100];
lli optimalChoice(int i,int j,lli *arr){
    if(i>j)
        return 0;
    if(j==i+1){
        return (max(a[i],a[j]));
    }
    else{
        if(dp[i][j]!=-1)// f[i][j] denotes the max value a player.
                        // can get from the list[i] to list[j]
            return dp[i][j];
        // query 1 mei player 1 picks the first element.
        // now his score increases by a[i].
        // but for this there are two cases with the opponent.
        // either the opponent picks up the next of the a[i]
        // or he picks up the last of the array,a[j]
        // but since oppnent is smart he will pick that element
        // where HE gets max profit and I GET THE MINIMUM PROFIT.
        // So, for me i will be getting the min(optimalChoice(i+2,j),optimalChoice(i+1,j-1))
        lli query1 = arr[i] + min(optimalChoice(i+2,j,arr),optimalChoice(i+1,j-1,arr));
        // again here the opponent either picks the last or the first.
        // which one does he pick?
        // he picks that one such that the array that is left will give
        // the minimal choice for the first player.
        // very niceeee....!!
        lli query2 = arr[j] + min(optimalChoice(i,j-2,arr),optimalChoice(i+1,j-1,arr));
        lli ans = max(query1,query2);
        dp[i][j] = ans;
        return ans;
    }
}
int main(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
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
