#include<bits/stdc++.h>
using namespace std;
void gen_substrings(int i, int j, string s, string out, vector<string> &res,vector<string> table){
    int n = s.size();
    if(j==n){
        out[j] = '\0';
        res.push_back(out);
        return;
    }
    int dig = s[i] - '0';
    for(auto k: table[dig]){// we gotta go in the table man not the i and the j
        out[j] = k;
        gen_substrings(i+1,j+1,s,out,res,table);
    }
}
void search_and_print(string s, vector<string> find)
{
    for(auto k:find) // this is basically substring matching of s in k
    {   //cout<<k<<endl;
        for(int i=0;i<(k.size()-s.size());i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(s[j] != k[i+j])
                    break;
                if(j==(s.size()-1))
                     cout<<k<<endl;// printing the string which contains s.
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    vector<string> table{ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    vector<string> searchIn{"prateek", "sneha", "deepak", "arnav", "shikha", "palak","utkarsh", "divyam", "vidhi", "sparsh", "akku"};
    string s;
    cin>>s;
    string out;
    for(int i=0;i<s.size();i++)
        out+=" ";
    vector <string> res;
    gen_substrings(0,0,s,out,res,table);
    for(auto k : res){
        //cout<<k<<endl;
        search_and_print(k,searchIn);
        // if(ind!=-1)
            // cout<<searchIn[ind]<<endl;
    }
    return 0;
}
