#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector< vector <lli> > vvi;
lli mod = 1e9;
vvi multiply(vvi A, vvi B,int k)
{   vvi X ( k+1,vector<lli> (k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x = 1;x<=k;x++)
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
lli compute(lli n, int k, vector<lli> &b,vector<lli> &c)
{
    if(n<=k)
        return b[n-1];// as it is given that for i<=k, ai = bi
    if(n==0)
        return 0;
    else
    {   //STEP 1
        // make transormation matrix for ai;
        //T is transormation matrix.
        vvi T (k+1,vector<lli>(k+1));// a 2D vector
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i!=k)
                {   if(j==i+1)
                        T[i][j]=1;
                    else
                        T[i][j]=0;
                }
                else
                   T[i][j] = c[k-j];// because c has zero based indexing
            }
        }
        //STEP 2
        // Compute power of transormation matrix
        T = fast_power(T,n-1,k);
        //STEP 3
        // Make the F1 vector;
        vector<lli> F1(k+1);
        // it just stores the values of b vector in it
        for(int i=1;i<=k;i++)
            F1[i] = b[i-1];
        //STEP 4
        // find the a(n) from the mulitplication.
        // Note that you only need the firt term from the generated matrix.
        lli res= 0;
        for(int i=1;i<=k;i++)
        {
            res = (res+(T[1][i]*F1[i])%mod)%mod;// only generating the first term of the Resulting vector
        }
        return res;
    }
}
int main()
{   ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        vector<lli> b,c;
        lli ele;
        b.reserve(k);
        c.reserve(k);
        for(int i=0;i<k;i++)
        {
            cin>>ele;
            b.push_back(ele);
        }
        for(int i=0;i<k;i++)
        {
            cin>>ele;
            c.push_back(ele);
        }
        lli n ;
        cin>>n;
        cout<< compute(n,k,b,c)<<endl;
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
