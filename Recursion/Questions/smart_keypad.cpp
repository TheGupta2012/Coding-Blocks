#include<bits/stdc++.h>
using namespace std;
void keypad_combo(int i,int j,string s,string out, vector<string> &t)
{   int n = s.size();
    if(j==n)
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    else
    {
        if(i==n)
            return ;
        else
        {
            int dig = s[i] - '0';
            for(auto m: t[dig])
            {
                out[j] = m;
                keypad_combo(i+1,j+1,s,out,t);
            }
        }
    }
}
int main()
{   ios::sync_with_stdio(0);
    vector<string> table{ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    string s;
    cin>>s;
    string o;
    for(int i=0;i<s.size();i++)
        o+= " ";
    keypad_combo(0,0,s,o,table);
    return 0;
}
