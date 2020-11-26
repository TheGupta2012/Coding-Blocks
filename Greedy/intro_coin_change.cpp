#include<bits/stdc++.h>
using namespace std;
int coinchange(int *arr,int n,int money){
    int ans = 0;
    cout<<"Coin : ";
    while(money > 0){
        int id = upper_bound(arr,arr+n,money) - arr;

        id--;// as we got first ele >money
        ans++;
        money-= arr[id];
        if(money>0)
            cout<<arr[id]<<" + ";
        else
            cout<<arr[id];
    }
    cout<<endl;
    return ans;
}
int main(){
    int t;
    cout<<"Enter tests :";
    cin>>t;
    int coins [] = {1,2,5,10,20,50,100,500,1000};
    while(t--){
        int n = rand()%100+1;
        cout<<n<<endl;
        cout<<"Coins required are :"<<coinchange(coins,9,n)<<endl;
    }
    return 0;
}
