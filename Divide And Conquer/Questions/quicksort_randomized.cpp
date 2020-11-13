#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void swap(lli *a, lli *b){
    lli t ;
    t = *a;
    *a = *b;
    *b = t;
}
lli find_partition(lli s, lli e, lli n, lli *arr){
    lli pivot = s + (rand()%(e-s));
    swap(&arr[s],&arr[pivot]); // pick first element only
                              // as the pivot
    // but after swapping with a random element in the array.
    lli i,j;
    i = s;
    j = e;
    lli p = arr[s];
    do{
            do
            {i++;}while(arr[i]<=p);
            do
            {j--;}while(arr[j]>p);
        if(i<j)
            swap(&arr[i],&arr[j]);
    } while(i<j);
    swap(&arr[s],&arr[j]);
    return j;

}
void quick_sort( lli start, lli end, lli n, lli *arr){
    lli partition;
    if(start<end){
        partition = find_partition(start,end,n,arr);
        quick_sort(start, partition, n , arr);
        quick_sort(partition+1,end, n , arr);
    }
}
int main(){
    lli n;
    cin>>n;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(0,n,n,arr);
    for(auto k:arr)
        cout<<k<<" ";
    return 0;
}
