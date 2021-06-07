#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < n; i++)
#define in(x) \
    lli x;    \
    cin >> x
// namespace
using namespace std;
// typdefs
typedef long long int lli;
typedef vector<lli> vi;
int dp[1002][1002];
map< pair<int,int> , bool > P;

// to optimize...
void get_palindromes(string s,int n){
    // code 
    for(int i=n-2;i>=0;i--){
        for(int j=i+2;j<n;j++){
            if(s[i] == s[j] && P[{i+1,j-1}] == true )
                P[{i,j}] = true;
            else 
                P[{i,j}] = false;
        }
    }
}

lli Palindrome_partition(string s,lli i,lli j){
    // base 
    if(i >= j)
        return dp[i][j] = 0;

    // check 
    if(dp[i][j] != -1)
        return dp[i][j];

    // if a palindrome 
    if(P[{i,j}] == true)
        return dp[i][j] = 0;

    // code
    lli temp, ans = 1e16;
    for(lli k = i;k<j;k++){

        temp = Palindrome_partition(s,i,k) + Palindrome_partition(s,k+1,j) + 1;
        ans = min(ans,temp);
    }

    return dp[i][j] = ans;

}

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cout<<"Enter the string :";
    cin>>s;
    int n = s.size();

    // init the DP 
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            P[{i,j}] = false;
    }

    // init the P 
    for(int i=0;i<n;i++){
        P[{i,i}] = true;
    }

    // adjacent init 
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1])
            P[{i,i+1}] = true;
    }

    get_palindromes(s,n);

    lli ans = Palindrome_partition(s,0LL,n-1);

    cout<<"\nMinimum partitions :"<<ans;
    return 0;
}
