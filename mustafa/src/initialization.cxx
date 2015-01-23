#include <iostream>

using namespace std;


struct S
{
  int x;
  S(): x(10) {}
};

class C
{
  public:
    int mX;
    int mY;
    S mS;

    // mS and mY are not explicitely initialized in the initializer list
    // mS default consturctor will always be called. 
    // mY is a POD therefore it will be:
    //    Zero-initialized if instance of C is created with new operator.
    //    Otherwise, left un-initialized.
    C(): mX(5) { cout<<mX<<" "<<mS.x<<" "<<mY<<endl; }

};

int main()
{
  C c0; // C::mY will not be initialized.
  C* c1 = new C(); // C::mY will be zero-initialized. 
  C* c2 = new C;   // C::mY will be zero-initialized.
}
