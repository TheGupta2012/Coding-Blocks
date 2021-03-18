#include<bits/stdc++.h>
using namespace std;
bool check(int i, int j, int place[][10]){
    // check the column upwards
    for(int k=i;k>=0;k--)
        {
            if(place[k][j]==1) return false;
        }
    int x,y;
    x = i;
    y = j;
    // upper left
    while(x>=0 && y>=0){
        if(place[x][y]==1) return false;
        x--;
        y--;
    }
    x = i;
    y = j;
    // upper right
    while(y<10 && x>=0){
        if(place[x][y] == 1) return false;
        x--;
        y++;
    }
    return true;

}
bool solveNqueens(int q,int i,int place[][10]){
    if(i>=q) // placed all queens
        return true;
    else{
        // go on filling the board assuming that you CAN
        bool flag;
        for(int j=0;j<10;j++){
            if(check(i,j,place)==true)
                {   // place teh queen assuming the i,j is the valid position
                    place[i][j] = 1;
                    flag = solveNqueens(q,i+1,place);// solve for the next part of the board.
                    if(flag == false)
                    {
                        place[i][j] = 0;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            else
                continue;
        }
        return flag;
    }

}
int main(){
    ios::sync_with_stdio(0);
    // int n;
    // cout<<"Enter the size of the board :";
    // cin>>n;
    cout<<"Enter the number of queens you wish to place(board is size 10x10) :";
    int q;
    cin>>q;
    if(q>10){
        cout<<"No combination possible as the number of queens are greater \nthan the number of dimensions of the board.";
    }
    int place[10][10] = {0};
    solveNqueens(q,0,place);
    for(int i=0;i<10;i++){
        for(int j =0 ;j<10;j++){
            if(place[i][j]==1)  cout<<"Q";
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;

}
