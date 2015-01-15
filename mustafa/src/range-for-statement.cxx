#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v {1,2,3,4,5};
  int a[] {1,2,3,4,6};

  for(auto& i:v)
  {
    cout<<i<<endl;  // reference to element
    i +=1;          // modifies element
  }

  for(auto i:v)
  {
    cout<<i<<endl;  // copy of element
  }

  return 0;
}
