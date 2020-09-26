// Divisible subarrays in an array
// Find the number of subarrays divisible by the
// size of the array
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{   int t;
    cin>>t;
    while(t--)
    {
    lli n ;
    cin>>n;
    lli c[n+1];
    c[0] = 0; //c[i] means sum uptil the ith index. Note, c[0] is always 0, always have a zero sum array uptil 0.
    lli sum = 0;
    lli ele;
    lli arr[n];// making the array.
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        // creating cumulative sum array.
        c[i+1] = sum;
    }
    map <int, set<int> > m;// stores the indices of csum mods
    m[0].insert(0);
    for(int i=1;i<n+1;i++)
    {
        if(c[i]>=0)
            {c[i] = (c[i])%n;
             m[c[i]].insert(i);
            } // finding mod with n. Note that sum can be negative hence adding n
        else
            {c[i] = (c[i]%n+n)%n;
             m[c[i]].insert(i);
            } // dealing with negative numbers.
    }
    lli s,e,size;
    for(auto k:m)
    {
        if(k.second.size()>1) // if any bucket of remainders contains 2 or more elements.
        {
            vector <int> v(k.second.begin(),k.second.end());//making vector to access indices.
            s = v[0]; //starting element
            e = v[1]; // ending element+1
            break;
        }
    }
    cout<<e-s<<endl;// size of the subset.
    for(int i=s ; i<e ; i++)
        cout<<i+1<<" ";// output the indices
    cout<<endl;
    }
    return 0;
}
