#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}
void store_unique_permutations(set<string> &final, string s, int n, int i)
{
    if(i==n)
    {
        final.insert(s);
        return;
    }
    for(int j = i;j<n;j++)
    {
        swap(&s[i],&s[j]);
        store_unique_permutations(final,s,n,i+1);
        swap(&s[i],&s[j]);
    }
}
int main()
{   ios::sync_with_stdio(0);
    // basis is just inserting each of the permutations
    // into a set of strings(gives lexicographic order too)
    cout<<"Finding the unique permutations for a string.\n";
    cout<<"Enter the string :";
    string s;
    cin>>s;
    int n = s.size();
    set<string> final;
    store_unique_permutations(final,s,n,0);
    cout<<"Unique permutations are:\n";
    for(auto k:final)
        cout<<k<<endl;
    return 0;

}
