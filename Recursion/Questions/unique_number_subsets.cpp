#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}
void gen_permute(int i,set<string> &final, int n, string s)
{
    if(i==n)
    {
        final.insert(s);
        return ;
    }
    for(int j = i;j<n;j++)
    {
        swap(&s[i],&s[j]);
        gen_permute(i+1,final,n,s);
        swap(&s[i],&s[j]);
    }
}
int main()
{   ios::sync_with_stdio(0);
    long int n;
    cin>>n;
    long int arr[n];
    string s;
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        s+=arr[i]+'0';}
    set <string> final;
    gen_permute(0,final,n,s);
    for(auto k:final)
    {
        for(auto m:k)
            cout<<m<<" ";
        cout<<endl;
    }

    return 0;
}
