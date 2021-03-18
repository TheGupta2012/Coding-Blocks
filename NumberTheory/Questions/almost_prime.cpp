#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int factor(int a)
{
    for(int i=2;i<=int(sqrt(a));i++)
        {if(a%i==0)
           return i;}
    return a;
}
int compute(int n)
{   lli total = 0;
    for(int i=2;i<=n;i++)
    {   //cout<<"Number "<<i<<endl;
        int temp = i;
        int f,count;
        int prev=-1;
        while(temp>1)
        {
            f = factor(temp);// smallest prime factor
            //cout<<"Factor "<<f<<endl;
            temp = temp/f;
            if(prev==-1)
                {prev = f;
                 count=1;}
            else if(prev!=f)
            {   count++;// keep track of primes that are coming
                prev = f;
                if(count>2)
                    break;
            }
            else continue;
        }
        if(count==2)
        {   //cout<<"Number :"<<i<<endl;
            total++;}
    }
    return total;
}
int main()
{   int n;
    cin>>n;
    cout<<compute(n);
    return 0;
}
