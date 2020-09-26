#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector < vector< lli> > vvi;
lli mod =1e9+7;
vvi T (2,vector<lli>(2));
vector< lli > F1(2);
void assign()
{
T[0][0]=0;
T[0][1]=1;
T[1][0]=1;
T[1][1]=1;
F1[0] = 0;
F1[1] = 1;

}
vvi multiply(vvi A,vvi B)
{   vvi X (2,vector<lli> (2));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int x=0;x<2;x++)
            {
                X[i][j] = (X[i][j]+(A[i][x]*B[x][j])%mod)%mod;
            }
        }
    }
    return X;
}
vvi power(vvi T,lli n)
{
    if(n==1)
        return T;
    if(n&1)
    {
        return multiply(T,power(T,n-1));
    }
    else
    {
        vvi X = power(T,n/2);
        return multiply(X,X);
    }
}
void compute(lli n)
{
    if(n==0)
        {cout<<0;
        return ;}
    if(n==1)
        {cout<<1;
        return ;}
    // STEP 1-> make initial vector-> done
    //STEP 2-> make transormation matrix-> done
    T = power(T,n);
    lli res = 0;
    for(int i=0;i<2;i++)
    {
        res = (res+ (T[0][i]*F1[i])%mod)%mod;
    }
    cout<<res<<endl;
}
int main()
{   ios::sync_with_stdio(0);
    lli n;
    cin>>n;
    assign();
    compute(n);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
