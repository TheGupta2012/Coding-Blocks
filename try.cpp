#include"template.h"
int main()
{
  cout<<"Hey";
  lli k=10;
  cout<<setbits(k)<<endl;
  ind_set m;
  m.insert(8);
    m.insert(83);
      m.insert(1);
        m.insert(9);
  cout<<m.find_ind(8)<<endl;
  return 0;
}
