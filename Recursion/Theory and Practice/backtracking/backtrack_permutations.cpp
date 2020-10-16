#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}
void generate_permuations(int i,int n,char *s)
{   //base case
    if(s[i]=='\0')
    {
        cout<<s<<endl;
        return;
    }
    //recursive case.
    for(int j=i;j<n;j++)
    {   swap(&s[i],&s[j]);
        generate_permuations(i+1,n,s);// resursive step.
        // this backtracking is very important as we want the original
        // array back when we make the next call.
        swap(&s[i],&s[j]);// the most important backtracking step.
    }
}
int main()
{
    cout<<"Given a string s, find all the permutations of the string s";
    cout<<"\nEnter the string length:";
    int n;
    cin>>n;
    char s[100];
    string r;
    cout<<"Enter string :";
    cin>>r;
    for(int i=0;i<n;i++)
        s[i]= r[i];
    s[n] = '\0';
    cout<<"All of our permutations are:\n";
    generate_permuations(0,n,s);
    return 0;
}
