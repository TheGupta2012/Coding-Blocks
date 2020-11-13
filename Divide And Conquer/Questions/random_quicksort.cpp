#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
