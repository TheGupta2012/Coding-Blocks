#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void extend_euclid(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return;
    }
    else{
        extend_euclid(b,a%b,x,y);
        int t1,t2;
        t1 = *x;
        t2 = *y; // *x and *y are the values that were returned from the
        // bottom tier.
        *x = t2;// update x
        *y = t1 - (a/b)*t2;// update y
    }
}
int help_euclid(int a,int b)
{   // just return x corresponding to the equation Ax + By = GCD(A,B)
    int x,y;
    extend_euclid(a,b,&x,&y);
    return x;
}
int mod_inverse(int a,int m)
{
    if(gcd(a,m)!=1)
      {cout<<"Modular inverse not possible!\n";
      return -1;}
    int b = help_euclid(a,m);
    return (b+m)%m;
}
int main()
{
    int a,m;
    cout<<"Enter the numbers a and m:";
    cin>>a>>m;
    try{
        int b = mod_inverse(a,m);
        if(b<0)
            throw(b);
        else{
            cout<<"Multiplicative modular inverse of "<<a<<" w.r.t "<<m<<" is : "<<b<<endl;
        }
    }
    catch(int )
    {
        cout<<"GCD of a and m must be 1. Wrong numbers.";
    }

    return 0;
}
