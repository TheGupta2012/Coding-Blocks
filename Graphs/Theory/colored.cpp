#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors

void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
 int x;
int n=10;
int m=12;
int matrix[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       matrix[i][j] = rand()%2;
       cout<<matrix[i][j]<<"   ";}
   cout<<endl;
}cout<<endl;
int visited[100][100] = {0};
visited[1][2]=1;
visited[8][9] = 1;
 for(int f=0;f<n;f++){
     for(int g=0;g<m;g++){
         if(visited[f][g]==true)
             Color(2);
         else
             Color(15);
         cout<<matrix[f][g]<<" ";
     }
     cout<<endl;
 }

 return 0;
}
