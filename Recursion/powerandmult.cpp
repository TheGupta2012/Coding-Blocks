#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli power(lli a, lli n)
{
    if(n==1)
        return a;
    else
    {
        if(n%2==0)
        {
            int x = power(a,n/2);
            return (x*x);
        }
        else
            return a*(power(a,n-1));
    }
}
lli mult(lli a,lli b)
{   if(b==0)
        return 0;
    if(b==1)
        return a;
    else
    {
        return a+mult(a,b-1);
    }
}
int main()
{
    cout<<"Power and multiply with recursion\n Enter 1 for power, 2 for multiplication(-1 exit) :\n";
    int a,n,ch;
    while(true)
    {
        cout<<"Enter choice :";
        cin>>ch;
        if(ch==-1)
            break;
        if(ch==1)
        {
            cout<<"Enter the base :";
            cin>>a;
            cout<<"Enter the power:";
            cin>>n;
            cout<<"Power of "<<a<<"^"<<n<<" is:"<<power(a,n)<<endl;
        }
        else
        {
            cout<<"Enter first number:";
            cin>>a;
            cout<<"Enter the second number:";
            cin>>n;
            cout<<"Multiplication is :"<<mult(a,n)<<endl;
        }
    }
    return 0;
}
