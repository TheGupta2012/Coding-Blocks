#include<bits/stdc++.h>
using namespace std;
bool partition_search(int s,int e,int key,int *arr){
    //check if we are on the eft part or the right part
    bool flag = false;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key)
            {
                flag = true;
                break;
            }
        else{
            if(arr[mid]>=arr[s])// in the part 1
            {
                // equality with end and start is applied
                // because we have not yet checked for it
                // In the first case we only checked if
                // key== arr[mid].
                if(key<arr[mid] && key>=arr[s])
                    e = mid-1;
                else
                    s = mid+1;
            }
            else{
                if(key>arr[mid] && key<=arr[e])
                    s = mid+1;
                else
                    e = mid-1;
            }
        }
    }
    return flag;

}
int main(){
    int n;
    cout<<"Enter the size:";
    cin>>n;
    cout<<"Enter the elements :";
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the element to be searched :";
    int key;
    cin>>key;
    if(partition_search(0,n-1,key,arr)==true)
        cout<<"Yes element is there!";
    else
        cout<<"Sorry element not here.";
    return 0;
}
