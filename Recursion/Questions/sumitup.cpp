#include<bits/stdc++.h>
using namespace std;
void AddSubset(int i,int n,int *arr,set < vector<int> > &s,int target){
    vector <int> res;
    int sum = 0;
    int counter = 0;
    while(i>0){
        if(i&1){
            res.push_back(arr[counter]);// pushing back into the result.
            sum+=arr[counter]; // adding its value.
        }
        counter++;
        i = i>>1;
    }
    sort(res.begin(),res.end());
    if(sum==target)
        s.insert(res);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    set < vector<int> > s;
    for(int i=0 ; i<(1<<n) ; i++){
        AddSubset(i,n,arr,s,sum);
    }
    for(auto k:s){
        for(auto f:k)
            cout<<f<<" ";
        cout<<endl;
    }
    return 0;
}
