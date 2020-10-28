#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
void changeColors(int i,int j,int n,int m, vvi &maze,vvi &visit,int curr_color,int *size){
    //base
    if(i>=n || j>=m || i<0 || j<0)  return;
    if(visit[i][j]==1) return;
    if(maze[i][j]==0) return;

    // recurse
    visit[i][j] = 1;
    *size+=1;
    maze[i][j] = curr_color;
    changeColors(i+1,j,n,m,maze,visit,curr_color,size);
    changeColors(i-1,j,n,m,maze,visit,curr_color,size);
    changeColors(i,j-1,n,m,maze,visit,curr_color,size);
    changeColors(i,j+1,n,m,maze,visit,curr_color,size);
}
void floodFill(int n,int m, vvi &maze, map<int,int> &color,vvi &visit){
    int c = 2,size;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==1) continue;
            if(maze[i][j]==0) continue;
            size = 0;
            changeColors(i,j,n,m,maze,visit,c,&size);
            color[c] = size; // the size of the cluster that was recolored.
            c++;// changing the color value.
        }
    }
}
int main(){
    int n,m,ele;
    cin>>n>>m;
    vvi maze(n,vector<int>(m)) ;
    map<int,int> color;// keeps size of the clusters.
    vvi visit(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ele;
            maze[i][j] = ele;
        }
    }
    floodFill(n,m,maze,color,visit);
    // at this point i have the color map ready, let us traverse the matrix.
    long int ans = 0;
    cout<<"Your new maze:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;
    // cout<<color[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]==0){
                set<int> s; // inserting the distinct colors as repition shoulnd't be there.
                if(i-1>=0)  s.insert(maze[i-1][j]);
                if(j-1>=0)  s.insert(maze[i][j-1]);
                if(i+1<n)   s.insert(maze[i+1][j]);
                if(j+1<m)   s.insert(maze[i][j+1]);

                // at this point i have the distinct color values.
                long int val = 1;// for the zero.
                for(auto z:s)
                    val += color[z];// for all the clusters with the color z and connected to i,j.
                ans = max(ans,val);
            }
        }
    }
    cout<<ans;
    return 0;
}
