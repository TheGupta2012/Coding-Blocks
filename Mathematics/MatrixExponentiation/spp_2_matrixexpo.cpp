#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector< vector <lli> > vvi;
lli mod;
vvi multiply(vvi A, vvi B,int k)
{   vvi X ( k+2,vector<lli> (k+2));
    for(int i=1;i<=k+1;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            for(int x = 1;x<=k+1;x++)
            {
                X[i][j] = (X[i][j]+(A[i][x]*B[x][j])%mod)%mod;
            }
        }
    }
    return X;
}
vvi fast_power(vvi T, lli n,int k)
{
    if(n==1)
        return T;
    else
    {
        if(n&1)// if n is odd
        {
            return multiply(T,fast_power(T,n-1,k),k);
        }
        else // if n is even.
        {
            vvi X = fast_power(T,n/2,k);
            return multiply(X,X,k);
        }
    }
}
lli compute(lli n, lli *b,lli *c,int k)
{
    lli sum_b[k+1] = {0};
    for(int i=1;i<=k;i++)
    {
        sum_b[i] = (sum_b[i-1]%mod + b[i-1]%mod)%mod;
    }
    if(n==0)
        return 0;
    if(n<=k)
        return sum_b[n];

    //STEP 1
        // make transormation matrix for S(n);
        //T is transormation matrix.
        vvi T (k+2,vector<lli>(k+2));// a 2D vector
        for(int i=1;i<=k+1;i++)
        {
            for(int j=1;j<=k+1;j++)
            {
                if(i<k)
                {   if(j==i+1)
                        T[i][j]=1;
                    else
                        T[i][j]=0;
                }
                else
                  {if(j<k+1)
                      T[i][j] = c[k-j];
                     // because c has zero based indexing
                   else
                   {
                           if(i==k)
                              T[i][j] = 0;
                           if(i==k+1)
                              T[i][j] = 1;
                   }
            }
        }
   }
   // STEP 2 compute the power of transormation
   T = fast_power(T,n-1,k);
   // STEP 3 MAKE THE INITIAL vector
   vector <lli> F1(k+2);
   for(int i=1;i<=k+1;i++)
   {    if(i<k+1)
            F1[i] =  b[i-1];
        else
            F1[i] = sum_b[k];
   }
   // Step 4 Find S(n) by multiplying the last row of
   // transormation matrix with the column vector
   lli res = 0;
   for(int i=1;i<=k+1;i++)
   {
       res = (res%mod + (T[k+1][i]*F1[i])%mod ) %mod;
   }
   return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m;
        int k;
        cin>>k;
        lli b[k],c[k];// 0 based indexing
        for(int i=0;i<k;i++)
            cin>>b[i];
        for(int i=0;i<k;i++)
            cin>>c[i];
        cin>>m>>n>>mod;
        lli s1 = compute(m-1,b,c,k);
        lli s2 = compute(n,b,c,k);
        cout<< ( (s2%mod) - (s1%mod) + mod)%mod<<endl;
    }
    return 0 ;
}
