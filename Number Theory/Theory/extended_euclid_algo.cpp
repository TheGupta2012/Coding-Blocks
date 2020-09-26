#include<bits/stdc++.h>
using namespace std;
void extend_euclid(int a,int b,int *x,int *y)// using reference method.
{
    if(b==0)
    {   //base case.
        cout<<"Base A:"<<a<<" B:"<<b<<endl;
        *x = 1;
        *y = 0;
        return ;
    }
    else{
        // recurse
        extend_euclid(b,a%b,x,y);

        int temp1,temp2;
        temp1 = *x;
        temp2 = *y;
        cout<<temp1<<","<<temp2<<endl;
        cout<<"A:"<<a<<"B:"<<b<<endl;
        *x = temp2; // this is just x[i-1] = y[i]
        *y = temp1 - (a/b)*(temp2);// this is y[i-1] = x[i] - (a/b)*y[i]
    }
}
void solve(int a,int b)
{
    int x,y;
    extend_euclid(a,b,&x,&y);
    cout<<"The values of x and y that solve "<<a<<"x + "<<b<<"y = GCD("<<a<<"%"<<b<<") are:";
    cout<<"\nX :"<<x<<endl;
    cout<<"Y :"<<y<<endl;
}
int main()
{
    cout<<"Using the extended Euclid's Algorithm to solve equations of form :\n\t\t";
    cout<<"\n Ax + By = GCD(A,B)\n";
    cout<<"Enter A and B\n ";
    int A,B;
    cout<<"A:";
    cin>>A;
    cout<<" B:";
    cin>>B;
    solve(A,B);
    return 0;
}
