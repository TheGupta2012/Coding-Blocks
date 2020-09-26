#include<bits/stdc++.h>
#include<experimental/random>
using namespace std;
using namespace experimental;
int main()
{  cout<<"Enter k for the first k max:";
  int k;
  cin>>k;
  priority_queue<int> pq;
  for(int i=0;i<15;i++)
  { int ele;
    ele = randint(1,100);
    if(k>0)
    {
      k--;
      pq.push(ele);
      continue;
    }
    else
    {
      if(ele > pq.front())
      {
        
      }
    }

  }
  return 0;
}
