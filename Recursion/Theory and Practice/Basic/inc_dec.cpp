#include<bits/stdc++.h>
using namespace std;
void inc(int n,int c)
{
    if(c<n)
    {
        cout<<c<<" ";
        c++;
        inc(n,c);
    }
    else
    {
        cout<<c;
        return ;
    }
}
void dec(int n)
{
    if(n>0)
    {
        cout<<n--<<" ";
        dec(n);
    }
    else
        return ;
}
int main()
{
    inc(10,1);
    cout<<endl;
    dec(8);
    return 0;
}
