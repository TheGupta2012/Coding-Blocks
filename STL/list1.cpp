#include<bits/stdc++.h>
using namespace std;
bool rev(string a,string b)
{
  return (a>b);
}
int main()
{ // JUST the doubly linked lists of the C++ stl
  cout<<"Lists...";
  list<int> l;
  //initialise
  list <int> l1{1,2,3,6,8};
  list <string> l2{"apple","banana"};
  l2.push_back("pine");
  for(auto i:l2)
  {
    cout<<i<<"->";
  }
  l2.sort(rev);//sort method of list class
  cout<<endl;
  for(auto i:l2)
    cout<<i<<"->";//lexi sorted order.
    cout<<endl;
    cout<<l2.front()<<endl;
  l2.push_front("Mango");
  l2.pop_back();
  for(auto i:l2)
  {
    cout<<i<<"->";
  }
  return 0;
}
