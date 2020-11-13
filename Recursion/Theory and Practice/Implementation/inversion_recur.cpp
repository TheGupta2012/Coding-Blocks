#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli cross_inver_or_mergefunction(lli *arr,lli s,lli e)
{
    lli i = s;
    lli mid = (e+s)/2;
    lli j = mid + 1;
    lli k = s;
    lli count = 0;
    lli temp[100000];
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
    for(lli h=s;h<=e;h++)
        arr[h] = temp[h];
    return count;
}
lli inversions(lli *arr,lli s,lli e)
{
    if(s>=e)
        return 0;

    lli mid = (e+s)/2;
    lli x = inversions(arr,s,mid);
    lli y = inversions(arr,mid+1,e);
    lli z = cross_inver_or_mergefunction(arr,s,e);

    return (x+y+z);
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    lli n;
    cin>>n;
    lli arr[n];
    for(lli i=0;i<n;i++)
        cin>>arr[i];
    //cout<<"\nInversion in the array are "
    cout<<inversions(arr,0,n-1)<<endl;
}
    return 0;
}
