#include<bits/stdc++.h>
using namespace std;
int main()
{
  priority_queue <int> pq_max;
  priority_queue <int,vector<int>,greater<int>> pq;
  int n;
  for(int i=0;i<5;i++)
  {
    cout<<"Enter element:";
    cin>>n;
    pq.push(n);
    pq_max.push(n);
  }
  while(!pq.empty())
  {
    cout<<"Min:"<<pq.top()<<" ";
    cout<<"Max:"<<pq_max.top()<<" ";

    pq.pop();
    pq_max.pop();
  }

  return 0;
}
