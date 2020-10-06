#include<bits/stdc++.h>
using namespace std;
int found(int n,int *arr,int key)
{
    if(n<=0)
        return -1;
    if(arr[0]==key)
        return n;
    else
       return found(n-1,arr+1,key);

}
int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int ele;
    int arr[n];
    cout<<"Enter the elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter the element to search :";
    cin>>ele;
    int pos = found(n,arr,ele);
    if(pos>=0)
        cout<<"Element is found at position "<<(n-pos);
    else
        cout<<"Element not found";
    return 0;
}
