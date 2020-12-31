#include<bits/stdc++.h>
using namespace std;
class Node{
    public: char data;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char d){
        this->data = d;
        this->terminal = false;
    }

};
bool present(Node *temp, char k){
    // if node is present in the
    // children map of current node
    if(temp->children.count(k))
        return true;
    else
        return false;
}
Node *toNodewith(Node *temp,char k){
    // return the address of the node
    // in this which contains the data k
    Node *add = temp->children[k];
    return add;
}
class Trie{
    // class must contain only the root node as the data value...
    Node *root;
    int words;
    public: Trie(){
        root= new Node('\0');
        words = 0;
    }
    int count(){
        return words;
    }
    void insertTrie(string s){
    // can only access from the root
        Node *temp = root;
        words+= 1;
        for(auto k:s){
            if(present(temp,k)){
                temp = toNodewith(temp,k);
            }
            else{
                Node *n = new Node(k);
                temp->children[k] = n;
                temp = n;
            }
        }
        temp->terminal = true;
        // here we are at the end of the
        // word .
    }
    bool find(string s){
        Node *temp = root;
        // start from root
        for(auto k:s){
            if(present(temp,k)){
                temp = toNodewith(temp,k);
            }
            else
                return false;
        }
    // if we are at a terminal pertaining to the
    // last letter of the string only , then
        if(temp->terminal == true)
            return true;
        else
            return false;
    }
    void print(char c,string s,Node *curr){
        if(curr->terminal == true)
            cout<<s<<endl;
        for(auto k:curr->children)
            {   char A = k.first;
                Node *add = k.second;
                s+=A;
                print(A,s,add);
                s.pop_back();
            }
    }

    void print_all(){
        Node *temp = root;
        for(auto k:temp->children){
            string s="";
            char c = k.first;
            Node *add = k.second;
            s+=c;
            print(c,s,add);
        }
    }
};
int main(){
    ios::sync_with_stdio(0);
    cout<<"IMPLEMENTING TRIES...\n";
    Trie T;
    string s;
    cout<<"Query type -> 1: insert 2: check 3: print all\n";
    int ch;
    while(true){
        cout<<"\nEnter query:";
        cin>>ch;
        if(ch==-1)
            break;
        switch(ch){
            case(1):{
                cout<<"Word :";
                cin>>s;
                T.insertTrie(s);
                break;}
            case(2):{
                cout<<"Word :";
                cin>>s;
                if(T.find(s)==true)
                    cout<<"Yes, present.\n";
                else
                    cout<<"Not present.";
                break;}
            case(3):{
                T.print_all();
                break;}
            default:break;
        }
    }

    return 0;
}
