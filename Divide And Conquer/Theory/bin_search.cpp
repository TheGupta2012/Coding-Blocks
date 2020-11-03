#include<bits/stdc++.h>
using namespace std;
bool bin_search(int s,int e,int key, int *arr){
    if(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==key)
            return true;
        else if(arr[mid]<key)
            bin_search(mid+1,e,key,arr);
        else
            bin_search(s,mid-1,key,arr);
    }
    else
        return false;
}
int main(){
    int n;
     cout<<"Enter the no. of elements:";
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
        arr[i] = rand()%(n+10);
     cout<<"Randomized array is :";
     for(auto k:arr) cout<<k<<" ";
     cout<<"\nSorted list :";
     sort(arr,arr+n);
     for(auto k:arr) cout<<k<<" ";
     cout<<"\nEnter element to search:";
     int ele;
     cin>>ele;
     if(bin_search(0,n-1,ele,arr)==true)
        cout<<"Element present!";
    else
        cout<<"Sorry element not found.";
     return 0;
}
