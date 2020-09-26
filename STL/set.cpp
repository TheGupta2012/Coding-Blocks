#include<bits/stdc++.h>
using namespace std;
int main()
{
  // set is a data structure that is used to have unique elements.
  // can't update the element of value.
  // insert
  // iterate
  // check
  // delete
  // Implementation-> RED BLACK TREES.
  int arr[] = {1,3,5,1,29,2,5,3,22};
  int size = sizeof(arr)/sizeof(int);
  set <int> s(arr,arr+size);
  for(auto o:s) // o is an int object.
    cout<<o<<endl;
  s.erase(222);// erase can accept the value you want to delete or the
  // iterator that points to the element you want to delete.
  cout<<"Updated\n";
  for(auto i:s)
    cout<<i<<endl;
    return 0;
}
