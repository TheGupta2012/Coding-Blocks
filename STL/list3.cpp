#include<bits/stdc++.h>
using namespace std;
int main()
{
  list <int> l{1,1,3,3,7,8};
  for(int i:l)
    cout<<i<<"->";
  //now , how to insert an element after a certain elements
  auto it= l.begin();
  cout<<"Enter element after which you want to insert :";
  int n;
  cin>>n;
  while(n--)
   it++;
  /*if(it==l.end())
    l.push_back(n);
  else*/
  cout<<*it<<" element after which \n";
    l.insert(it,100);

  cout<<endl;
  for(auto i:l) cout<<i<<"->";
  return 0;

}
