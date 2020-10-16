#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli knapsack(lli i, lli m,lli curr, lli k,lli *w, lli *p)
{
    if(i>=k)
        return 0;
    lli res = 0;
    if(curr>=m)
        return 0;
    else
    {
        lli inc1 ,inc2;
        inc1 = inc2 = 0;
        if(curr+w[i]<=m)// including the current item only when including the item does not exceed the capacity
                        // of the bag.
            inc1 = p[i] + knapsack(i+1,m,curr+w[i],k,w,p);
        inc2 = knapsack(i+1,m,curr,k,w,p);// else just not including the item.
        lli res = 0;
        if(inc1>inc2)
            {cout<<"Item "<<i+1<<" included ";
            cout<<endl;}
        res = max(inc1,inc2);
        return res;
    }
}
int main()
{   cout<<"Enter the total capacity:";
    lli n;
    cin>>n;
    cout<<"Enter the number of items:";
    lli k;
    cin>>k;
    lli w[k],p[k];
    cout<<"Enter the weights of the items:";
    for(int i=0;i<k;i++)
        cin>>w[i];
    cout<<"Enter the prices of the items:";
    for(int i=0;i<k;i++)
        cin>>p[i];
    cout<<"The maximum profit you can get is :";
    cout<<knapsack(0,n,0,k,w,p);

}
