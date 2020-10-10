#include<bits/stdc++.h>
using namespace std;
void alloccur(int n,int i,int *arr,int key)
{
    if(i==n)
        return ;
    else
    {
        if(arr[i]==key)
            cout<<"Index :"<<i<<endl;
        alloccur(n,i+1,arr,key);
    }
}
int main()
{
    int n,ele;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element:";
    cin>>ele;
    cout<<"All occurences are:\n";
    alloccur(n,0,arr,ele);
    return 0;
}
