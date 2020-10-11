#include<bits/stdc++.h>
using namespace std;
int non_consec_ones(int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    else
    {
        return (non_consec_ones(n-1) + non_consec_ones(n-2));
    }
}
int main()
{   int n;
    cout<<"Count the number of strings of length n, which have no consecutive ones?";
    cout<<"\nEnter the number n:";
    cin>>n;
    cout<<"\nRecursion was implemented without DP\nTotal possible strings are 2^"<<n<<" out of which "<<non_consec_ones(n)<<" do not have consecutive ones.";
    return 0;
}
