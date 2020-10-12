#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void gen_subsets(string s,string res,int i,int j)
{   int n = s.size();
    if(i==n)
    {
        res[j] = '\0';
        cout<<res<<endl;
        return;
    }
    else{
        res[j] = s[i];
        gen_subsets(s,res,i+1,j+1); // include the ith char
                                    // and then go on including
                                    // rest of the subsets.
        gen_subsets(s,res,i+1,j); // don't include the ith char
                                  // and then go on including
                                  // rest of the subsets.
                    // we didn't increment the jth char as we
                    // want to overwrite it with another value.
}
}
int main()
{
    // printing all the subsequences of a given array using recursion
    cout<<"Enter the string :";
    string s;
    cin>>s;
    string o;
    cout<<"The subsets for "<<s<<" are :\n";
    for(int i=0;i<s.size();i++) o+=" ";
    gen_subsets(s,o,0,0);
    return 0;
}
