#include<bits/stdc++.h>
using namespace std;
class Node{
    public : char data;
             bool terminal;
             int count;
             unordered_map <char,Node*> children;
            Node(char d){
                this->data = d;
                this->terminal = false;
                this->count=1;
            }
};
// prefix -> trie, trie, trie, trie...
class Trie{
    Node *root;
    int count;
public: Trie(){
    root = new Node('\0');
    root->count=0;
    count = 0;
}
    void insert(string s){
        count+=1;
        Node *temp = root;
        for(auto k:s){
            if(temp->children.count(k)==0){
                // letter (k) absent
                Node *n = new Node(k);
                temp->children[k] = n;
                temp = n;
            }
            else // letter k is present in temp
                {
                    /* ****IMPORTANT***** */
                    (temp->children[k])->count += 1;
                    // heart of the algo



                temp = temp->children[k];}
        }
        temp->terminal = true;
    }
    bool find(string s){
        Node *temp = root;
        for(auto k:s){
            if(temp->children.count(k)==0)
                return false; // agar hota to milta
            else
                temp = temp->children[k];
        }
        if(temp->terminal == true)
            return true;
        else
            return false;
    }
    void print(char c,string s,Node *curr){
        if(curr->terminal== true)
            cout<<s<<endl;
        for(auto k:curr->children){
            char A = k.first;
            Node *add = k.second;
            s+=A;
            print(A,s,add);
            s.pop_back(); //backtrack point...
        }
    }
    void print_all(){
        Node *temp = root;
        for(auto k:temp->children){
            char c = k.first;
            string s;
            s+=c;
            Node *add = k.second;
            print(c,s,add);
        }
    }
    void find_U_prefix(string s){
        Node *temp = root;
        string res = "";
        for(auto k:s){ // k must be present, no need for data check
            Node *add = temp->children[k];
            int count = add->count;
            // cout<<"Count of "<<k<<" in "<<s<<":"<<count<<endl;
            res+=k;
            if(count==1)
                {cout<<res<<endl;
                return;}
            else{
                temp = add;
            }
        }
        cout<<-1<<endl;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cout<<"Enter the number of words :";
    int n;
    cin>>n;
    Trie T;
    list <string> arr;
    string s;
    cout<<"Enter the words :\n";
    while(n--){
        cin>>s;
        arr.push_back(s);
        T.insert(s);
    }
    T.print_all();
    cout<<endl;
    for(auto k:arr){
        T.find_U_prefix(k);
    }
    return 0;
}
