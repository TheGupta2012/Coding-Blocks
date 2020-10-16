#include<bits/stdc++.h>
using namespace std;
void generate_strings(int i,int j,string s,string out,map<int,char> m)
{   int n = s.size();
    if( i == n)// here the stopping criteria is the fact that we have traversed the whole of s
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    else
    {
        int n1,n2;
        n1 = s[i] - '0';
        if(i<n-1)
            n2 = (s[i] - '0')*10 + (s[i+1] - '0');
        if(n1!=0)
        {out[j] = m[n1];
        generate_strings(i+1,j+1,s,out,m);}
        // pertaining to the above call we have utilised only one i and thus increment i by one.
        int d1,d2;
        d1 = s[i] - '0';
        d2 = s[i+1] - '0';
        if(d1!=0)
        {   if(d1==1)
            {out[j] = m[n2];
            generate_strings(i+2,j+1,s,out,m);}
            if(d1 == 2 && d2 >=1 && d2<=6)
            {out[j] = m[n2];
            generate_strings(i+2,j+1,s,out,m);}
            // why i+2? because pertaining to this call we took two numbers inside.
        }
    }
}
// need to handle zero case.
int main()
{   ios::sync_with_stdio(0);
    cout<<"You have a mapping from 1:a, 2:b, 3:c, ... , 26:z";
    cout<<"\nand you are given a number with n digits\n";
    cout<<"\nTASK: to print all possible combinations that can be generated in the number.\n";
    cout<<"\nExample - 1123-> aabc, kbc, alc, aaw, kw";
    cout<<"\nEnter the number :";
    string s;
    cin>>s;
    // note that the single digit case is trivial.
    map <int,char> m;
    for(int i=0;i<26;i++)
        m[i+1] = 'a' + i;
    // now handle the recursive case with two digits at once.
    // be careful- only when number <=26 then only print something.
    string o;
    for(int i=0;i<s.size();i++)
        o+= " ";
    generate_strings(0,0,s,o,m);
    return 0;
}
