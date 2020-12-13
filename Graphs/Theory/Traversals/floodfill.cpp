#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool visited[100][100];
void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void floodfill(int i,int j,int n,int m,int start,int target,int matrix[][100]){
    // base case
    if(i>=n || j>=m || i<0 || j<0)
        return;
    // boundary condition
    if(matrix[i][j]!=start || visited[i][j] == true)
        return;
    // visited array is not needed as we would already
    // have a changed cell when we backtrack.
    visited[i][j]=true;
    matrix[i][j] = target;
    for(int f=0;f<n;f++){
        for(int g=0;g<m;g++){
            if(visited[f][g]==true)
                Color(3);
            else
                Color(15);
            cout<<matrix[f][g];
        }
        cout<<endl;
    }
    cout<<endl;
    floodfill(i+1,j,n,m,start,target,matrix);
    floodfill(i-1,j,n,m,start,target,matrix);
    // floodfill(i+1,j+1,n,m,start,target,matrix);
    // floodfill(i+1,j-1,n,m,start,target,matrix);
    // floodfill(i-1,j+1,n,m,start,target,matrix);
    // floodfill(i-1,j-1,n,m,start,target,matrix);
    floodfill(i,j+1,n,m,start,target,matrix);
    floodfill(i,j-1,n,m,start,target,matrix);
}
int main(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++)
            visited[i][j] = false;
    }
     cout<<"FLOOD FILL ALGRITHM\n";
     cout<<"Enter the number of rows and columns :";
     int n,m;
     cin>>n>>m;
     cout<<"Your matrix has been generated.\n";
     int matrix[100][100];
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            matrix[i][j] = rand()%2;
            cout<<matrix[i][j]<<"   ";}
        cout<<endl;
     }
    cout<<"Coloring the matrix with floodfill, \nEnter a cell to start from(0 based)...";
    int x,y,target;
    cout<<"\nCell co-ordinates : ";
    cin>>x>>y;
    cout<<"Enter the number with which you wanna replace :";
    cin>>target;
    floodfill(x,y,n,m,matrix[x][y],target,matrix);
    cout<<"Your matrix is :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<matrix[i][j]<<"  ";}
       cout<<endl;
    }
    return 0;
}
/*
INPUT MATRIX


*/
