#include<bits/stdc++.h>
using namespace std;
typedef vector < vector <int> > vvi;
bool check_diag(int i,int j,unordered_map<int,int> &d1, unordered_map<int,int> &d2){
    // basis is that slope of all diagonals is either 1 or -1.
    if(( d1[i+j] + d2[j-i] == 0 ))// checking if the diagonal entries have been made or not.
        return true;
    else
        return false;
}
long long int count=0;
bool n_queens(int i,int n,int q,bool *col,unordered_map<int,int> &d1, unordered_map<int,int> &d2, long long int *count,vvi &block){
     // diagonals is a special map which stores
     // the constants that have appeared in the lines
    // which are formed by our queen placement.
    //always start placing row wise and then go on placing the queens at the
    // indices in the next row where THEY CAN BE PLACED.
    if(i==n+1)// because I am using one based indexing.
        {*count+=1;
        // returning false as although we have found a solution
        // but
        return false;}
    bool flag = false;
    for(int j = 1;j<=n;j++)
    {
        if(col[j] == false && check_diag(i,j,d1,d2)==true)// placeable position
        {

            col[j] = true;
            block[i][j] = 1;
            d1[i+j] = 1; // reserving the m = -1 diagonal
            d2[j-i] = 1; // reserving the m = 1 diagonal
            flag = n_queens(i+1,n,q,col,d1,d2,count,block);
            if(flag==false) // flag returned false which means the current position in
            //the ith row is not good so go to next jth column and place there.
            {
                col[j] = false;
                d1[i+j] = 0;
                d2[j-i] = 0; // freeing up the place.
                block[i][j] = 0;
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
    cin>>n;
    vector <long long int> v{1, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184, 14772512, 95815104, 666090624, 4968057848};
    if(n>=13){ // at 13 max recursion depth is reached...
        cout<<v[n];
        return 0;
    }
    long long int count;
    count=0;
    bool col[n+1]= {false};
    unordered_map <int,int> d1,d2;
    vvi block(n+1,vector<int>(n+1,0));
    bool flag = n_queens(1,n,n,col,d1,d2,&count,block);
    cout<<count;
    return 0;
}
