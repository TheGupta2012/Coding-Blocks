#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<vector<lli> > vvi;
lli n,t;// global variables so that all functions can access
lli mod = 98765431;//mod used in question.
vvi multiply(vvi A,vvi B)
{
    vvi X(n,vector<lli> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
                {X[i][j] = ( (X[i][j]%mod)+ ((A[i][k]%mod)*(B[k][j]%mod))%mod)%mod;}
        }
    }
    return X;
}
vvi power(vvi T)
{
    if(t==1)
        return T;
    else
    {
        if(t%2==1)
            {t--;
            return multiply(T,power(T));
            }
        else
            {   t = t/2;
                vvi X = power(T);
                return multiply(X,X);
            }
    }
}
void compute(lli *arr)
{
    vvi T(n,vector<lli> (n,1));
    for(int i=0;i<n;i++)
    {
        T[i][i] = 0; // creating transformation matrix for the recurrence.
    }
    T = power(T);
    // note that a new initial vector has not been created and the array is utilised as itself.
    for(int i=0;i<n;i++)
    {   lli res = 0;
        for(int j=0;j<n;j++)
        {
            res = ( res%mod + (T[i][j]%mod*arr[j]%mod)%mod )%mod;
            // this is the term (c1+c2+...cn) after t steps but excluding c[i].
        }
        cout<<res<<endl;
    }

}
//works for all
int main()
{
    ios::sync_with_stdio(0);

    cin>>n>>t;
    lli arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    compute(arr);
    return 0;
}
