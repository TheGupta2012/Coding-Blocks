#include<bits/stdc++.h>
#include<chrono>
#include<windows.h>
#include<cmath>
using namespace std;
using namespace std::chrono;
bool isValid(int number, int i, int j, vector<vector<int> > &sudoku, int n){
    // check for rows and columns.
    for(int m=0;m<n;m++){
        if(sudoku[i][m]==number || sudoku[m][j]==number)
            return false;
    }
    // now find which grid does it belong to and search in the grid.
    int size = int(sqrt(n));
    int x = (i/size)*(size);// starting row index of subgrid
    int y = (j/size)*(size);// starting col index of subgrid
    for(int h=x;h<x+size;h++){ // searching in sub rows
        for(int d=y;d<y+size;d++){//searching in subcolmns
            if(sudoku[h][d]==number)
                return false;
        }
    }
    return true;
}
bool solve(int n,int i,int j,vector< vector<int> > &sudoku){
    if(i>=n){
        return true;
    }
    if(j==n){// means reached beyond the last column so update the row.
        return solve(n,i+1,0,sudoku);
    }
    if(sudoku[i][j]!=0)
        return solve(n,i,j+1,sudoku);
    bool flag;
    for(int no=1;no<=n;no++)
    {   if(isValid(no,i,j,sudoku,n))// repeatedly checking for the numbers 1-> n in i,jth cell
            {   cout<<"Trying "<<no<<endl<<"for "<<i<<" and "<<j<<endl;
                sudoku[i][j] = no;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout<<sudoku[i][j]<<" ";
                    }cout<<endl;
                }
                Sleep(1000);
                flag = solve(n,i,j+1,sudoku);
                if(flag==true)
                {   cout<<no<<" was actually correct for position "<<i<<" and "<<j<<"!"<<endl;
                    return flag;
                }// do not backtrack here as you still have numbers to check for in the i,j th cell
            }
    }
    // backtrack here -> why ? as at this point we would have tried all the numbers at the
    // i , j th cell.
    sudoku[i][j] = 0;//don't solve with this cell.
    return false;
}
int main()
{
    ios::sync_with_stdio();
    cout<<"SOLVING SUDOKU...\n";
    cout<<"Sizes -> 1x1 , 4x4 , 9x9 , 16x16";
    int n;
    x:cout<<"\nEnter the side length :";
    cin>>n;
    if(n>4) {
        cout<<"Invalid side\nPlease enter again";
        goto x;
    }
    vector< vector<int> > sudoku(n,vector<int> (n));
        for(int i=0;i<n;i++){
            cout<<"Enter row "<<i+1<<":\n";
            for(int j=0;j<n;j++){
                cin>>sudoku[i][j];
            }
        }
    cout<<"Your sudoku is being solved...\n";
    Sleep(4000);
    bool flag = solve(n,0,0,sudoku);
    if(flag==true)
    {cout<<"Your final sudoku is :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sudoku[i][j]<<" ";
        }cout<<endl;
    }}
    else{
        cout<<"Sorry invalid configuration given!";
    }
    return 0;
}
