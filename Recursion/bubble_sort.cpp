#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int n,int *arr)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])//sending the ith largest element to its correct place.
                swap(&arr[j],&arr[j-1]);
        }
    }
}
void bubble_recur(int n,int *arr)
{
    if(n==1)
        return;
    else
    {
        for(int i=1;i<n;i++)
            {
                if(arr[i-1]>arr[i])// again doing the same.
                    swap(&arr[i-1],&arr[i]);
            }
        bubble_recur(n-1,arr);
    }
}
void bubble_recur_2(int *a,int j,int n)//purely recursive.
{
    if(n==1)    // single array is always sorted
        return;
    if(j==n) // i have hit a case where my j has reached the last index
    {
        return bubble_recur_2(a,1,n-1);// this is basically the outer for loop.
    }
    if(a[j-1]>a[j])
        swap(&a[j-1],&a[j]);
    bubble_recur_2(a,j+1,n);// this is pertaining to the inner for loop.
    return ;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    cout<<"Enter the elements:";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubble_recur_2(arr,1,n);
    cout<<"Sorted array is :";
    for(auto k:arr)
        cout<<k<<" ";
    return 0;
}
