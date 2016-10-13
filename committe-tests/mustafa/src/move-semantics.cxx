#include <iostream>

using namespace std;
 
struct C 
{
  C() { cout << __PRETTY_FUNCTION__ << " has been called."<<endl; }
  C(const C&) { cout << __PRETTY_FUNCTION__ << " has been called."<<endl; }
  C(C&&) { cout << __PRETTY_FUNCTION__ << " has been called."<<endl; }
  C& operator=(C const & rhs) { cout<<__PRETTY_FUNCTION__ << " has been called."<<endl; return *this; }
};
 
C get_a_C() 
{
  return C();
}

int main()
{
  std::cout << "Hello, World!\n";

  C obj; 
  obj = get_a_C();
}
