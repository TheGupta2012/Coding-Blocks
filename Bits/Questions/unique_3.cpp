#include<bits/stdc++.h>
using namespace std;
int bit(int pos,int a)
{   // extracting j th bit from number
    a = a>>pos;
    return (a&1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int power = 1;
    int bitsum;
    for(int j=0;j<32;j++) // iterating for 32 bit numbers.
    {   bitsum = 0; // initiating bitsum
        for(int i=0;i<n;i++)
        {   bitsum += bit(j,arr[i]);
        }

        ans = ans + power*(bitsum%3); // adding the appropriate value to answer.
        power *=2; // updating power
    }
    cout<<ans;
}
