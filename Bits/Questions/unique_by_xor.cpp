#include<bits/stdc++.h>
using namespace std;
int main()
{
    // problem is that you have an array with only one
    // unique number , how would you find it?
    // approach 1-> maintain a freq table and check for the frequency of
    // the numbers
    // approach 2-> maintain a running xor-> why will it help?
    // as a^a = 0 and a^0 = a, so all the elements would pair up which
    // are not unique and the ans will be the unique number
    int n;
    cin>>n;
    int ele,ans;
    ans = 0;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        ans = ans^ele;// requires constant space.
    }
    cout<<ans;
    return 0;
}
