#include<bits/stdc++.h>
using namespace std;
unordered_map <int,string> m;
string number_name(long long n)
{   string res = "";
    if(n<10) // when number less than 10 just append the digit name
    {   cout<<"Appending "<<m[n]<<endl;
        res+= " " + m[n];
        return res;
    }
    else
    {   //after the function is called we are doinig some work
        int dig = n%10;
        cout<<"Calling for "<<n/10<<endl;
        cout<<"Would append "<<dig<<endl; // call for n/10 
        res += number_name(n/10);
        // bottom up direction.
        res += " "+m[dig]; // and append the current digit of the recursion.
        cout<<"Result is "<<res<<endl;
        return res;
    }
}
int main()
{
    long long n;
    cin>>n;
    m[0] = "zero";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    cout<<"Your number is :"<<n<<endl;
    cout<<number_name(n);
    return 0;
}
