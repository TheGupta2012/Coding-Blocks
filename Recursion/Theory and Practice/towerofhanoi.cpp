#include<bits/stdc++.h>
using namespace std;
void move(int n,char src, char through, char dest)
{   char a,b,c;
    a = src;
    b = through;
    c = dest;
    if(n==0)
        return ;
    else
    {
        move(n-1,a,c,b);//through becomes the destination.
        //cout<<n-1<<" disks shifted from "<<a<<" to "<<b<<endl;
        cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
        move(n-1,b,a,c);
        //cout<<n-1<<" disks shifted from "<<b<<" to "<<c<<endl;
    }
}
int main()
{
    cout<<"Visualising the tower of Hanoi through recursion\n";
    cout<<"Enter the number of disks :";
    int n;
    cin>>n;
    cout<<"The tower of hanoi is :\n";
    move(n,'A','B','C');
    return 0;
}
