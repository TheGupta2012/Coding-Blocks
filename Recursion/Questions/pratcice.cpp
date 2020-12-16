#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long int lli;
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
    lli n,q;
    cin>>n>>q;
    lli arr[n];
    for(int i=0;i<n;i++)
        {arr[i] = rand()%n;
        cout<<arr[i]<<" ";}
    cout<<endl;
    // int last = 0;
    // priority_queue<lli> l;
    // for(int i=1;i<n;i++){
    //     if(arr[i]==arr[i-1])
    //         {l.push(i-last);
    //         last = i;}
    // }
    lli max = -1;
    lli last = 0;
    lli left;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            { //l.push(i-last);
             if((i-last)>max)
                {max = i - last;
                left = last;
                last = i;}
            }
    }
    if(max==-1)
        max = n;
    while(q--){
        lli x,y;
        cin>>x>>y;
        arr[x-1] = y;
        if(x-1>=last || x+1<left)
            cout<<max<<endl;
        //priority_queue<lli> l;
        else
        {
            //do something
            // well just look that if the segment is the largest segment and it is getting
            // affected so you need to see
        }

    }
    }
    return 0;
}
