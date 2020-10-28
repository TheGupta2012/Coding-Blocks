#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector <vector <int> > vvi;
void reColor(int i,int j,int tochange,int n, int m, vvi &matrix, int color,vvi &visit){
    //base
    if(i>=n || j>=m || i<0 || j<0)
        return;
    if(visit[i][j]==1 || matrix[i][j]!=tochange)
        return;

    // recurse
    visit[i][j] = 1;
    matrix[i][j] = color;
    reColor(i-1,j,tochange,n,m,matrix,color,visit);
    reColor(i+1,j,tochange,n,m,matrix,color,visit);
    reColor(i,j-1,tochange,n,m,matrix,color,visit);
    reColor(i,j+1,tochange,n,m,matrix,color,visit);
    return;
}
int main() {
	//code
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	// flood fill...
	while(t--){
	    int n,m,ele;
	    cin>>n>>m;
	    vvi matrix(n,vectochanger<int> (m));
	    vvi visit (n,vectochanger<int> (m));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	            {cin>>ele;
	            matrix[i][j] = ele;}
	    }
	    int x,y,color;
	    cin>>x>>y>>color;
	    reColor(x,y,matrix[x][y],n,m,matrix,color,visit);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	            cout<<matrix[i][j]<<" ";

	    }
	    cout<<endl;
	}
	return 0;
}
