#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> primes;
bitset<100005> b;
void sieve(lli *sums,unordered_map<lli,lli> &count)
{
    for(lli i=2;i<=100009;i++)
    {
            // why are we doing this?
            // sums[i] is the count of the no of multiples of i.
            // but j is actually a multiple of i, so we always
            // check whether that number is actually a number
            // in our frequency array and thus we increment the
            // multiples of i in array a by its frequency(count[j]).
            for(lli j=i;j<=100009;j+=i)
                {
                if (count.find(j)!=count.end())
                    sums[i]+= count[j];//heart of the problem
                }
        }

}
int main()
{
    lli n,q,k;
    cin>>n;
    lli arr[n];
    unordered_map<lli,lli> count;
    for(int i=0;i<n;i++)
        {
        cin>>arr[i];
        count[arr[i]]++;}
    lli sums[100011] = {0};
    sieve(sums,count);
    //let's construct an array stating how many times
    // a number appears as a divisor for any of the
    // number in the array.

    cin>>q;
    while(q--)
    {
        cin>>k;
        if(k==1) {cout<<n<<endl;
        continue;}
        cout<<sums[k]<<endl;
    }
    return 0;
}
