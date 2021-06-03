#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int n;
int m;

string get_lcs(string str1, string str2)
{
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
string shortestCommonSupersequence(string str1, string str2)
{
    // first find the LCS

    n = str1.size();
    m = str2.size();

    // first get the LCS
    memset(dp, -1, sizeof(dp));

    //init
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // code
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // get LCS
    string lcs = get_lcs(str1, str2);
    int i = 0, j = 0;
    // cout<<"LCS is :"<<lcs<<endl;
    string ans = "";
    // now start
    for (auto k : lcs)
    {

        while (i < n && str1[i] != k)
        {
            ans += str1[i];
            i++;
        }
        i++; // go to the next char
        while (j < m && str2[j] != k)
        {
            ans += str2[j];
            j++;
        }
        j++; // go to the next char
        ans += k;
    }
    // add left over chars...
    while (i < n)
    {
        ans += str1[i];
        i++;
    }
    while (j < m)
    {
        ans += str2[j];
        j++;
    }
    //return the ans
    return ans;
}
int main()
{
    string s1,s2;
    cout<<"Enter the string 1:";
    cin>>s1;
    cout<<"Enter the string 2:";
    cin>>s2;

    cout<<"Shortest common supersequence is :";
    cout<<shortestCommonSupersequence(s1,s2);
    return 0;
}