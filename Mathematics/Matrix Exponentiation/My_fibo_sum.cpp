#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef vector < vector< lli> > vvi;
vector < lli > F1(3);
void assign()
{ // making transformation matrix and initial vector

F1[0] = 1;
F1[1] = 0;
F1[2] = 1;

}
vvi multiply(vvi A,vvi B)
{   vvi X (3,vector<lli> (3));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int x=0;x<3;x++)
            {
                X[i][j] = (X[i][j]%mod+((A[i][x]%mod)*(B[x][j]%mod))%mod)%mod;
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
lli compute(lli n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    // STEP 1-> make initial vector-> done in assign() function
    //STEP 2-> make transormation matrix
    vvi T (3,vector<lli>(3));
    T[0][0]=1;
    T[0][1]=1;
    T[0][2]=1;

    T[1][0]=0;
    T[1][1]=0;
    T[1][2]=1;

    T[2][0]=0;
    T[2][1]=1;
    T[2][2]=1;
    // STEP 3 Calculate power
    T = power(T,n-1);
    // Step 4 Calculate answer
    lli res = 0;
    for(int i=0;i<3;i++)
    {
        res = (res%mod+ ((T[0][i]%mod)*F1[i])%mod)%mod;
    }
    return res;
}
int main()
{   ios::sync_with_stdio(0);
    lli t;
    cin>>t;
	assign();
    while(t--)
    {
    lli n,m;
    cin>>n>>m;
    if(n<m)
	{
		if(n==0)
			cout<<compute(m)<<endl;
		else{
			cout<<(compute(m)%mod-compute(n-1)%mod + mod)%mod<<endl;
		}
	}
	else
	{
		if(m==0)
			cout<<compute(n)<<endl;
		else
		{
			cout<<(compute(n)%mod - compute(m-1)%mod + mod)%mod<<endl;
		}
	}
    }
    return 0;
}
