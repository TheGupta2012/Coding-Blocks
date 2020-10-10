#include<bits/stdc++.h>
using namespace std;
void changePi(int i,string &s)
{   int n = s.size();
    if(i>=n-1)
        return ;
    string pi = "3.14";

    if(s[i]=='p' && s[i+1]=='i')
    {
        s = s.substr(0,i) + pi + s.substr(i+2,n-(i+2));
        // now your string is like ....3.14(.....)
        // the bracket part needs to be changed but the
        // initial part has been taken care of.
        changePi(i+4,s);
        // why i+4? as 4 new characters added (3.14) and thus
        // index now at i+4.
    }
    else
        changePi(i+1,s); // if pi not found just increment index.
}
int main()
{   cout<<"Replacing all occurences of pi with 3.14 recursively.\n\n";
    string s;
    cout<<"Enter string :";
    cin>>s;
    changePi(0,s);
    cout<<"Your new string is :"<<s;
    return 0;
}
