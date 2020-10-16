#include<bits/stdc++.h>
using namespace std;
void print_brackets(int i,int n,string res,int cleft,int cright)
{
    if(i==2*n)
    {
        res[i] = '\0';
        cout<<res;
        cout<<endl;
        return ;
    }
    if(cleft<n) // a left bracket can come until its count has not reached n.
    {   res[i] = '(';
        print_brackets(i+1,n,res,cleft+1,cright);
    }
    if(cright<cleft && cright<n) // only when the left brackets are unended
        // then only a right bracket can come to close it.
    {
        res[i] = ')';
        print_brackets(i+1,n,res,cleft,cright+1);
    }
}
int main()
{
    cout<<"Generating balanced parenthesis\n";
    cout<<"Enter the number of pairs :";
    int n;
    cin>>n;
    string res;
    for(int i=0;i<2*n;i++)
        res+=" ";
    print_brackets(0,n,res,0,0);
}
