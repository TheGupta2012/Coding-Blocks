#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
void mark_unsafe(vvi &safe,int i,int j,int n){
    safe[i][j] +=1; // reserving one spot for the knight
    if(j+2<n){
        if(i-1>=0) safe[i-1][j+2] +=1;
        if(i+1<n)  safe[i+1][j+2] +=1;
    }
    if(j-2>=0){
        if(i-1>=0) safe[i-1][j-2] +=1;
        if(i+1<n)  safe[i+1][j-2] +=1;
    }
    if(i-2>=0){
        if(j-1>=0) safe[i-2][j-1] +=1;
        if(j+1<n)  safe[i-2][j+1] +=1;
    }
    if(i+2<n){
        if(j-1>=0) safe[i+2][j-1] +=1;
        if(j+1<n)  safe[i+2][j+1] +=1;
    }
    // cout<<"Safe array updated\n";
    // for(int x=0;x<n;x++){
    //     for(int y=0;y<n;y++)
    //         cout<<safe[x][y]<<" ";
    //     cout<<endl;
    // }
    return;
}
void mark_safe(vvi &safe,int i,int j,int n){
    safe[i][j] -=1; // freeing up one spot for the knight
    if(j+2<n){
        if(i-1>=0) safe[i-1][j+2] -= 1;
        if(i+1<n)  safe[i+1][j+2] -= 1;
    }
    if(j-2>=0){
        if(i-1>=0) safe[i-1][j-2] -= 1;
        if(i+1<n)  safe[i+1][j-2] -= 1;
    }
    if(i-2>=0){
        if(j-1>=0) safe[i-2][j-1] -= 1;
        if(j+1<n)  safe[i-2][j+1] -= 1;
    }
    if(i+2<n){
        if(j-1>=0) safe[i+2][j-1] -= 1;
        if(j+1<n)  safe[i+2][j+1] -= 1;
    }
    // cout<<"Safe array updated\n";
    // for(int x=0;x<n;x++){
    //     for(int y=0;y<n;y++)
    //         cout<<safe[x][y]<<" ";
    //     cout<<endl;
    // }
    return;
}
bool nKnights(int i,int j,int knights,int n,vvi &place,vvi &safe,int *count){
    //base cases.
    if(knights==0){
        *count+=1;
        // cout<<"Configuration found!\n";
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(place[x][y]==1){
                    cout<<"{"<<x<<"-"<<y<<"} ";
                }
            }
        }cout<<" \n";
        return false;
    }
    if(j>=n){
        return nKnights(i+1,0,knights,n,place,safe,count);
    }
    if(i>=n || j>=n ||i<0 || j<0)
        return false;


    // recurse.
    bool flag ;
    if(safe[i][j]==0){// i can place the knight at i,j iff the safe value is 0 and not >0.
        mark_unsafe(safe,i,j,n);// these i and j are always valid.
        place[i][j] = 1;
        flag = nKnights(i,j+1,knights-1,n,place,safe,count);
        if(flag == false){
            mark_safe(safe,i,j,n);
            place[i][j] = 0;
            flag = nKnights(i,j+1,knights,n,place,safe,count);
        }
    }
    else
        return nKnights(i,j+1,knights,n,place,safe,count);
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cout<<"N Knight problem. \nPlacing n knights on an nxn chess board such that all are safe.\n";
    cout<<"Enter the size of the board:";
    int n;
    cin>>n;
    int count = 0;
    vvi safe(n,vector<int> (n,0));
    vvi place(n,vector<int> (n));
    cout<<"The zero based indices of valid configs are:\n";
    bool val = nKnights(0,0,n,n,place,safe,&count);
    cout<<"\nTotal ways to place the knights are "<<count<<endl;
    return 0;
}
