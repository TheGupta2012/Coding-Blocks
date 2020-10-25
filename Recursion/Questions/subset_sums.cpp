#include<bits/stdc++.h>
using namespace std;
bool calc_sum(int *arr,int i){
    if(i==0) return false;
    long long int res = 0;
    int count = 0;
    while(i>0)
    {
        if(i&1){
            res+=arr[count];
        }
        count++;
        i = i>>1;
    }
    if(res==0) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag = false;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<(1<<n);i++)
        {
            if(calc_sum(arr,i)==true)
                {cout<<"Yes\n";
                flag = true;
                break;}
        }
        if(flag==false) cout<<"No\n";
    }
    return 0;
}
