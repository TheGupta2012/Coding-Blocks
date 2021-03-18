#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long int lli;
void settle_up(set < pair<lli,string> > &credit, set < pair<lli,string> > &debit){
    // 1. start picking up the maximum debit person
    string n1,n2;
    lli a1,a2;
    while(credit.size()>0 && debit.size()>0){

        // get the max valued debiter
        auto debiter = *(debit.rbegin());
        a1 = debiter.first; // cost
        n1 = debiter.second; // name

        auto crediter = *(credit.rbegin()); // get the max valued crediter
        a2 = crediter.first; // cost
        n2 = crediter.second; // name

        cout<<n1<<" pays "<<min(a1,a2)<<" to "<<n2<<endl; // pay minimum of the amounts
        // update the amounts
        lli temp = a1;
        a1 -= min(a1,a2);
        a2 = max(a2-temp,0LL); // update amount

        //update the credit set
        credit.erase(prev(credit.end())); // remove the last element
        if(a2!=0) // if some amount is left, insert it again...
            credit.insert({a2,n2});

        // update the debit set
        debit.erase(prev(debit.end()));
        if(a1!=0)
            debit.insert({a1,n1});
    }
    return;
}

// correct...
int main(){
    ios::sync_with_stdio(0);
    cout<<"CLI SPLITWISE...";
    lli ch,n,amount,a;
    cout<<"\nEnter the number of people in your group :";
    cin>>n;
    string s,e;
    map <string, lli> nets;
    set < pair<lli,string> > credits,debits;
    cout<<"\nEnter the transactions(press 1 for transaction , -1 for exit) :";
    while(true){
        cin>>ch;
        if(ch==-1)
            break;
        if(ch!=1)
            {cout<<"Enter a valid option...\n";
            continue;}
        cout<<"Who gave the money? - ";
        cin>>s;
        cout<<"To whom? - ";
        cin>>e;
        cout<<"How much? - Rs";
        // cin>>a;
        a = rand()%100 + 1;
        cout<<a<<endl;
        nets[s]-= a;
        nets[e]+= a;
    }
    for(auto k:nets){
        string person = k.first;
        lli bal = k.second;
        cout<<person<<" has an outstanding balance of "<<bal<<endl;
        if(bal<0){
            debits.insert({-bal,person});
        }
        else{
            credits.insert({bal,person});
        }
    }
    cout<<"Settling up...\n";
    _sleep(1000);
    settle_up(credits,debits);
    return 0;
}
