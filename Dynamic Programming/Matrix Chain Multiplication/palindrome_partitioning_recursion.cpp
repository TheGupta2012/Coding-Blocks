#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define in(x) \
    lli x;    \
    cin >> x
// namespace
using namespace std;
// typdefs
typedef long long int lli;
typedef vector<lli> vi;
lli Partition_Palindrome(string s, lli i, lli j)
{
    // get the base condition
    if (i >= j)
    {
        return 0LL;
    }

    // check for a substring : whether the substr we are checking for is a substr or not
    // saves -> O(j-i+1)^2 calls.

    string t = s.substr(i, j - i + 1);
    string rev = t;
    reverse(all(rev));


    if (t == rev)
        return 0LL;

    // code
    lli ans = 1e18;
    lli s1, s2, temp;

    for (lli k = i; k < j; k++)
    {
        s1 = Partition_Palindrome(s, i, k);
        s2 = Partition_Palindrome(s, k + 1, j);
        temp = s1 + s2 + 1LL;
        ans = min(ans, temp);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    string s;
    cout << "Enter the string :";
    cin >> s;
    lli n = s.size();
    lli ans = Partition_Palindrome(s, 0LL, n - 1);
    cout << "The minimum number of partitions required are :";
    cout << ans;
    return 0;
}
