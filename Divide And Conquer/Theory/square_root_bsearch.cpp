#include<bits/stdc++.h>
using namespace std;
int int_root(int s,int e,int n){
    int target = n;
    int mid,ans;
    while(s<=e){
        mid = (s+e)/2;
        if(mid*mid == target)
            {ans = mid;
             break;}
        else if (mid*mid<target)
            {ans = mid;// ans can be mid but not necesaarily.
            s = mid+1;}
        else
            e = mid-1;
    }
    return ans;
}
double float_root(int s, int e,int n,int precise){
    int target = n;
    int mid;
    double ans;
    while(s<=e){
        mid = (s+e)/2;
        if(mid*mid==target)
            {ans = mid;
            break;}
        else if (mid*mid<target)
            {ans = mid; // ans can be mid.
            s = mid+1;}
        else
            e = mid - 1;
    }
    if(precise==0)
        return ans;
    else{
        double floater= 0.1;
        while(precise>0){
            while(ans*ans<=target)
                ans+=floater;
            if(ans*ans>target) ans-=floater;
            precise--;
            floater/=10;
        }
        return ans;
    }
}
int main(){
    double n;
    cout<<"SQUARE ROOT USING BINARY SEARCH\n";
    cout<<"Enter a number :";
    cin>>n;
    cout<<"For integer value enter Y else enter N:";
    char ch;
    cin>>ch;
    if(ch=='Y' || ch=='y'){
        cout<<int_root(0,int(n),int(n));
    }
    else{
        cout<<"Enter the precision digits:";
        int prec;
        cin>>prec;
        cout<<fixed<<setprecision(prec)<<float_root(0,n,n,prec);
    }
    return 0;
}
