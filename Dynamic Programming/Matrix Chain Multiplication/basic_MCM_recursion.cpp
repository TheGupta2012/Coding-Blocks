#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < n; i++)
#define in(x) \
    lli x;    \
    cin >> x
// namespace
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
lli solve_MCM(vi &arr, lli left, lli right)
{
    if (left >= right)
        return 0LL; //even 1 length array can't define a matrix

    lli temp, s1, s2, s3, ans;
    ans = 1e16;

    for (lli k = left; k <= right - 1; k++)
    {
        // very important to look at loop bounds correctly

        s1 = solve_MCM(arr, left, k);
        s2 = solve_MCM(arr, k + 1, right);
        s3 = arr[left - 1] * arr[k] * arr[right];

        temp = s1 + s2 + s3;
        ans = min(ans, temp);
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cout << "Matrix Chain Multiplication ...";
    cout << "Enter the number of matrices :";
    in(n);

    n++; // length of dimensions array is n

    cout << "Enter the dimensions in the array :";
    vi arr(n);

    for0(i, n)
    {
        in(ele);
        arr[i] = ele;
    }

    // solve for the minimum cost of multiplication
    lli ans = solve_MCM(arr, 1LL, n - 1);
    cout << "The minimum cost to multiply is :" << ans << endl;
    return 0;
}
