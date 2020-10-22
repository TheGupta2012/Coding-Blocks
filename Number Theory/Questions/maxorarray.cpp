#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void add_bits(lli *bits, lli ele)
{   int bit;
    for(int i=0;i<64 && ele>0;i++)
    {
        bit = ele&1;
        bits[i] = (bits[i]+bit);
        ele = ele>>1;
    }
}
lli calc(lli *bits){
    lli res=0;
    lli p = 1;
    for(int i=0;i<64;i++)
    {
        if(bits[i]==1)
            res+=p;
        p=p*2;
    }
    return res;
}
lli search(lli n,vector<lli> &arr, lli ele)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
            return i;
    }
    return -1;
}
lli allxor(lli n,vector<lli> &arr,lli ind)
{
    lli res = 0; // works even if ind = -1;
        for(int i=0;i<n;i++)
        {
            if(i==ind) continue;
            else{
                res = res^arr[i];
            }
        }
    return res;
}
int main()
{   ios::sync_with_stdio(0);
    lli n;
    cin>>n;
    vector <lli> arr;
    arr.reserve(n);
    lli bits[64] = {0};
    lli ele;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        arr.push_back(ele);
        add_bits(bits,ele);
    }
    //at this point i have the bits set up for my number.
    for(int i=0;i<64;i++){
        if(bits[i]%2==0 && bits[i]>0) bits[i] = 1;//it is a viable option to be changed
        else bits[i] = 0;
    }

    bool flag = false;
    int ind=-1;
    lli num;
    for(int i=0;i<64;i++)
    {   num = calc(bits);
        // calculating the number which can increase our xor sum after being removed is present in array.
        ind = search(n,arr,num);
        // searching it in the array.
        if(ind!=-1)
            {flag = true;
            break;}
        else
            {bits[i] = 0; // still have to search ahead as a number maybe found.
            continue;}
    }
    cout<<allxor(n,arr,ind);
    return 0;
}
