#include<bits/stdc++.h>
using namespace std;
int last_found(int n,int *arr,int ele)
{
    if(n==0)
        return -1;
    else{
        int i = last_found(n-1,arr+1,ele);
        if(i==-1)// i couldn't find an element in subarray
        {
            if(arr[0]==ele)// if the current array has it return its first occurence.
                return 0;
            else
                return -1;
        }
        return i+1;// why? means that we had an occurence in the subarray
        // and that is why returning i+1
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter element to check:";
    int ele;
    cin>>ele;
    if(last_found(n,arr,ele)!=-1)
        cout<<"Element found at "<<last_found(n,arr,ele);
    else
        cout<<"Not found";
    return 0;
}
