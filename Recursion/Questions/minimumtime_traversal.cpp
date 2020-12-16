#include<bits/stdc++.h>
using namespace std;
int mod(int a,int b){
    if(a>b) return a-b;
    else return b-a;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        int pipesx[n][2],pipesy[n][2],pipest[n];
        for(int i=0;i<n;i++)
            {cin>>pipesx[i][0]>>pipesy[i][0];
            cin>>pipesx[i][1]>>pipesy[i][1];
            cin>>pipest[i];}


    }
    return 0;
}
