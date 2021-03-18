#include<bits/stdc++.h>
using namespace std;
int partition_search(int s,int e,int *arr){
    //check if we are on the eft part or the right part
    bool flag = false;
	int ind;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]>arr[mid+1])
            { // found pivot and break
                flag = true;
				ind = mid;
                break;
            }
        else{
            if(arr[mid]>=arr[s])// in the part 1
            {  // go right
               s = mid+1;
            }
            else{ // go left
                e = mid-1;
            }
        }
    }
    return ind;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<partition_search(0,n-1,arr);
    return 0;
}
