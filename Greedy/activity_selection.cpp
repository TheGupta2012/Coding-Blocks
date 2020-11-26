#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair <int,int> pi;
bool comp (const pair <pi,int> &a, const pair< pi,int > &b){
    return (a.first).second < (b.first).second;
}
// this is a naive implementation.
// just don't choose the current schedule if s[j] < f[j-1] , simple.
void mark_invalid(int si, int finish, vector < pair < pi , int > > schedules, bool *valid){
    int start,m;
    for(auto k:schedules){
        start = (k.first).first;
        m = k.second;
        if(start < finish && m!=si && valid[m]==true){
            valid[m] = false;// it is not a valid schedule.
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,start,finish,si;
    cin>>n;
    vector < pair < pi , int > > schedules;
    for(int i=0;i<n;i++){
        cin>>start;
        cin>>finish;
        schedules.push_back({{start,finish},i});
    }
    // sort according to earliest finishing times.
    sort(all(schedules),comp);
    bool valid[n];
    for(int i=0;i<n;i++)
        valid[i] = true;
    int ans =0;
    for(auto k:schedules){
        start = (k.first).first;
        finish = (k.first).second;
        si = (k.second);//note that it is zero based.
        if(valid[si]==true){
            // all those schedules as invalid which have a start time
            // before the finish of the current schedule.
            mark_invalid(si,finish,schedules,valid);
            valid[si] = false;
            ans++;
        }
        else continue;
    }
    cout<<ans<<endl;
}
    return 0;
}
