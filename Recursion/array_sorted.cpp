#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool sorted(vector<int> &v, int ind)
{   int n = v.size();
    if(ind>=n-1)
        return true;
    else{
        bool flag = false;
        if(v[ind]<=v[ind+1])
                flag = sorted(v,ind+1);
        else
            { cout<<"Broken at index "<<ind<<"\n";
            cout<<"Unsorted elements are :"<<v[ind]<<" and "<<v[ind+1]<<endl;
            flag = false;}
        return flag;
    }
}
int main()
{   /* Checking through recursion whether an array is  sorted or not.*/
    lli n;
    cout<<"\nEnter the size of the array :";
    cin>>n;
    cout<<"\nEnter the elements:";
    int ele;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        {
            cin>>ele;
            v[i]= ele;
        }
    if(sorted(v,0)==true)
        cout<<"Your array is sorted\n";
    else
        cout<<"Your array is not sorted.";
    return 0;
}
