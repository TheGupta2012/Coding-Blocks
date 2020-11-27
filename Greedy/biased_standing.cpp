#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
int main(){
    ios::sync_with_stdio(0);
    lli t;
    cin>>t;
    while(t--){
        cout<<endl;
        lli n,rank;
        cin>>n;
        string s;
        lli arr[n];
        for(int i=0;i<n;i++){
            cin>>s>>rank;
            arr[i] = rank;
        }
        // O(nlogn)
        // sort(arr,arr+n);
        // for(int i=0;i<n;i++){
        //     ans+= abs(arr[i]-(i+1));
        // }
        // better -> O(n)
        lli ans=0;
        lli freq[n+1]={0};
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        lli available =1;
        lli counter=0;
        while(available<=n){
            if(freq[counter]!=0)
            // keep on associating ranks while you can and
            // if not then increment the counter .
            // means a smaller preferred rank is available
                {
                ans+=abs(available-counter);//associate
                freq[counter]--;
                if(freq[counter]==0)
                    counter++;
                available++;// the current rank.
            }
            else{
            counter++;// the counter accessing the array
            }
        }
        cout<<ans;
    }
    return 0;
}
