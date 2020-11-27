#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
bool comp(const pair <int,int> &a,const pair<int,int> &b){
    return (a.second)<(b.second);
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"Enter the number of activities :";
    int n,s,e;
    cin>>n;
    vector <pair<int,int> > activity;
    activity.reserve(n);
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>e;
        activity.push_back({s,e});
    }
    sort(all(activity),comp);
    // sorted according to finishing times
    int last_finish = -1,ans=0;
    for(auto k:activity){
        if(last_finish==-1)
            {
                ans++;
                last_finish = k.second;
            }
        else{
            if(k.first>=last_finish){
                ans++;
                last_finish = k.second;
            }
        }
    }
    cout<<"Maximum no. of activities available :"<<ans<<endl;
    return 0;
}
