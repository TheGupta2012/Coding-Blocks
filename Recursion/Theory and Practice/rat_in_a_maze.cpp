#include<bits/stdc++.h>
using namespace std;
typedef vector < vector < char > > vvc;
typedef vector < vector < int > > vvi;
// int count = 0;
void print(int r,int c,vvi v)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }cout<<endl;
}
bool ratInMaze(int *count,int r, int c,vvc maze,vvi &visited, int i, int j)
{

    if(i==r-1 && j==c-1 && maze[i][j]!='X')
        {//    count/+=1;
            visited[i][j] = 1;
            cout<<"Path found!\n";
            print(r,c,visited);
            int temp = *count + 1;
            *count = temp;
            return true;
        }
        if(i>=r || j>=c)
            return false;
        if(maze[i][j] == 'X')
            return false;

        visited[i][j] = 1;//assume that a path exists from that
        // current cell
        bool right = ratInMaze(count,r,c,maze,visited,i,j+1);
        bool down  = ratInMaze(count,r,c,maze,visited,i+1,j);

        // backtrack and mark that node as not visited so that
        // all possible paths can be found out
        visited[i][j] = 0;

        if(right == true || down==true)
            return true;
        return false;


}
int main()
{
    cout<<"Rat in a maze problem.\n";
    cout<<"Printing out all the possible paths and the total number of paths\n";
    cout<<"Enter the size of the maze-";
    cout<<"\nEnter the rows :";
    int r,c;
    cin>>r;
    cout<<"Enter the columns :";
    cin>>c;
    cout<<"Enter the matrix(0- free,X- blocked):\n";
    vvc maze(r,vector<char> (c));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>maze[i][j];
    }
    int count = 0;
    vvi visited(r,vector<int> (c,0));
    bool soln = ratInMaze(&count,r,c,maze,visited,0,0);
    cout<<"total paths are "<<count<<endl;
    return 0 ;
}
