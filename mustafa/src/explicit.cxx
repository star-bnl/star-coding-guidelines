#include <iostream>

using namespace std;

class A
{
  public:
    A(int x): data0(x) {}
    explicit A(int x, int y): data0(x), data1(y) {}
    int get_data0() const { return data0;}
    int get_data1() const { return data1;}

  private:
    int data0 = 0;
    int data1 = 0;
};

void print(const A& a)
{
  cout<<a.get_data0()<<" "<<a.get_data1()<<endl;
}

int main()
{
  A tmp {3,6};
  print(tmp);

  print({5,7}); // invoking a converting constructor

  return 0;
}
