#include<bits/stdc++.h>
using namespace std;
bool rightRatsolve(int i,int j,int n, int m, char maze[][1000], bool visited[][1000]){
    //base case.
    if(i>=n || j>=m || i<0 || j<0)
        return false;
    if(maze[i][j]=='X')
        return false;
    if(i==n-1 && j==m-1){// if you reached the final cell print the path.
        //cout<<"Path found\n";
        visited[i][j] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<visited[i][j]<<" ";
            cout<<endl;
        }
        exit(0);
    }
    // recurse.
    if(visited[i][j]==0)
    {visited[i][j] = 1;
    // if you can, go right
    bool right = rightRatsolve(i,j+1,n,m,maze,visited);
    if(right==false){
        // if not right, go down
        bool down = rightRatsolve(i+1,j,n,m,maze,visited);
        // if you can't even go down, that cell is not good
        // mark it unvisited and return false.
        if(down==false)
            visited[i][j] = 0;
        return down;
    }
    else
        return true;
    }
    else
        return false;
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    char ele;
    cin>>n>>m;
    char maze[1000][1000];
    bool visited[1000][1000]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ele;
            maze[i][j]= ele;
        }
    }
    if(maze[n-1][m-1]=='X')
        {
            cout<<-1<<endl;
            return 0;
        }
    bool flag = rightRatsolve(0,0,n,m,maze,visited);
    if(flag==false){
            cout<<-1<<endl;
    }
    return 0;
}
