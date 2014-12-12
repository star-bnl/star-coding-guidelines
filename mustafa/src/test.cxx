#include <iostream>
using namespace std;

struct A 
{
    int data;
    A() = default;
    A(const A&) = default;
    //NonCopyable & operator=(const NonCopyable&) = delete;
};

int main() {
  
  A a;
  a.data = 10;
  A b(a);
  A c;
  c = a;

  cout<<b.data<<endl;
  cout<<c.data<<endl;
  return 0;
}
