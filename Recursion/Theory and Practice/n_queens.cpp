#include<bits/stdc++.h>
using namespace std;
long long int count ;
bool check_diag(int i,int j,map<int,int> &diagonal){
    // basis is that slope of all diagonals is either 1 or -1.
    if( diagonal[i+j] + diagonal[j-i] == 0)
        return true;
    else
        return false;
}
bool n_queens(int i,int n,int q,bool *row,bool *col,map<int,int> &diagonal){
     // diagonals is a special map which stores
     // the constants that have appeared in the lines
    // which are formed by our queen placement.
    //always start placing row wise and then go on placing the queens at the
    // indices in the next row where THEY CAN BE PLACED.
    if(i>=q)
        {count++;
        return false;}
    bool flag = false;
    for(int j = 1;j<=n;j++)
    { if(row[i]==false && col[j] == false && check_diag(i,j,diagonal)==true)// placeable position
        {
            row[i] = true;
            col[j] = true;
            diagonal[i+j] = 1; // reserving the m = -1 diagonal
            diagonal[j-i] = 1; // reserving the m = 1 diagonal
            flag = n_queens(i+1,n,q,row,col,diagonal);
            if(flag==false) // flag returned false which means the current position in
            //the ith row is not good so go to next jth column and place there.
            {   row[i] = false;
                col[j] = false;
                diagonal[i+j] = 0;
                diagonal[j-i] = 0; // freeing up the place.
                continue;
            }
            else // flag was returned true means that queens ahead of you were able to be placed
                break;
        }
            else
        { // non placeable position
                continue;
        }
        }
    return flag;
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cout<<"Enter the size of the board :";
    cin>>n;
    count=0;
    cout<<"Enter the number of queens you wish to place :";
    int q;
    cin>>q;
    if(q>n){
        cout<<"No combination possible as the number of queens are greater \nthan the number of dimensions of the board.";
    }
    bool row[n+1]= {false};
    bool col[n+1]= {false};
    map <int,int> diag;
    bool flag = n_queens(1,n,q,row,col,diag);
    if(flag==true)
    {
        cout<<"The queen placement is :\n";
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(row[i]==true && col[j]==true){
                cout<<"Q";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    }
    else{
        cout<<"No combination possible ";
    }
    return 0;
}
