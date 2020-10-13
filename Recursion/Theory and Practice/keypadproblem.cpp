#include<bits/stdc++.h>
using namespace std;
map<int,string > m;
void all_keycombos(int i,int j,string s, string out)
{   int n = s.size();
    if(j==n)
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    else
    {
        if(i>=n) return;

        int dig = s[i] - '0';
        for(auto k:m[dig])// for all the letters in a particular digit.
        {
            out[j] = k;// adding the digit in the output array
            all_keycombos(i+1,j+1,s,out);
            //recursing for the rest of the digits' letters.
        }
    }
}
int main()
{
    m[2]="ABC";
    m[3]="DEF";
    m[4]="GHI";
    m[5]="JKL";
    m[6]="MNO";
    m[7]="PQRS";
    m[8]="TUV";
    m[9]="WXYZ";
    cout<<"Printing all the keypad combinations for the given number\n";
    cout<<"Enter a number :";
    string n;
    cin>>n;
    bool flag = true;
    for(auto k:n)
    {
        if(k=='1' || k=='0')
        {
            flag = false;
            cout<<"Please don't enter 0 or 1";
            break;
        }
    }
    string out;
    for(int i=0;i<20;i++)
        out+= " ";
    if(flag = true)
    {
        all_keycombos(0,0,n,out);
    }
    return 0;

}
