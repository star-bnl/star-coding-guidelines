#ifndef STRONG_ENUMS_H
#define STRONG_ENUMS_H

#include <stdio.h>
#include <iostream>

using namespace std;
namespace StrongEnums
{
class A
{
  int myA;
};

class B
{
  float fda;
};


enum WeakEnum{one, two,three};
enum WeakEnum2{one2, two2,three2};


enum class C2
  {
    one, two, three, four
      };
void testStrongEnums()
{
enum class C {one, two, three};

  C myEnum=C::one;
  C2 myEnum2;
  //doesn't work, is weak..
  //  C myEnum3=one;
  WeakEnum myWeakEnum=two;
  //  myEnum=one;
  //  myEnum2=C2::one;
  cout <<"hello, strong enums!"<<endl;
  cout <<" myenum is : "<< myWeakEnum<<endl;
  //doesn't compile...
  //  cout <<"strong enum is: " << myEnum<<endl;

}
}
#endif
