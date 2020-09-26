#include<bits/stdc++.h>
using namespace std;
int setrange_bits(int n,int i,int j)
{   int a,b;
    if(i<=j)
    { a = (-1<<(j+1));
      b = (1<<i) - 1;}
    else
    {
         a = (-1<<(i+1));
         b = (1<<j) - 1;
    }
    int mask = a|b;
    int ans = n&mask;
    return ans;
}
int main()
{
    cout<<"Operations related to bits....\n";
    cout<<"Enter number :";
    int n,i,j;
    cin>>n;
    cout<<"Enter the indices :";
    cout<<"i:";
    cin>>i;
    cout<<" j:";
    cin>>j;
    cout<<"Updated number is:"<<setrange_bits(n,i,j);
    return 0;
}
