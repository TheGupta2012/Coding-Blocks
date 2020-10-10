#include<bits/stdc++.h>
using namespace std;
int cross_inver_or_mergefunction(int *arr,int s,int e)
{
    int i = s;
    int mid = (e+s)/2;
    int j = mid + 1;
    int k = s;
    int count = 0;
    int temp[1000];
    while(i<=mid && j<=e)
    {
        if(arr[i]>arr[j])
        {
            count += (mid-i+1 );// adding inversions- > all the elements to the right
            // of a[i] will also make an inversion with a[j] as a[j]<a[i]
            // and all elements right of a[i] are >a[i].
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }
    while(i<=mid)
        temp[k++]= arr[i++];
    while(j<=e)
        temp[k++]= arr[j++];
    for(int h=s;h<=e;h++)
        arr[h] = temp[h];
    return count;
}
int inversions(int *arr,int s,int e)
{
    if(s>=e)
        return 0;

    int mid = (e+s)/2;
    int x = inversions(arr,s,mid);
    int y = inversions(arr,mid+1,e);
    int z = cross_inver_or_mergefunction(arr,s,e);

    return (x+y+z);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nInversion in the array are "<<inversions(arr,0,n-1);
    return 0;
}
