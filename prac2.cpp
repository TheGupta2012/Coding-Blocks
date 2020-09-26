#include <bits/stdc++.h>
using namespace std;
int main()
{ ios::sync_with_stdio(false);
  // to avoid doubling of the memory due to push_back
  // reserve method is used.
  // at every point if your capacity is achieved , the vector copying
  // would be done in a larger vector and this makes it slow.
  //use v.reserve...

  vector<int> v;
  v.reserve(1000);// this v.reserve is a good method to save capacity
  // before hand.
  cout<<"Enter 5 elements:-\n";
  for(int i=0;i<6;i++)
  {
    int ele;
    cin>>ele;
    v.push_back(ele);
    cout<<"Current capacity:"<<v.capacity();
    cout<<endl;
  }
  for(auto i:v)
    cout<<i<<" ";

  return 0;
}
