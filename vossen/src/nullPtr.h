#ifndef NULLPTR_H
#define NULLPTR_H

#include <stdio.h>
#include <iostream>

using namespace std;

namespace NullPtr
{
class A
{
  int myA;
};

class B
{
  float fda;
};


void testNullPtr()
{
  cout <<"hello, world!"<<endl;

  int* pointer = nullptr;
  int* pointer1 = NULL;
  int* pointer2 = 0;


  A* pA=new A();
  B* pB=new B();


  pA=nullptr;
  //  pB=pA;


  if(pointer==pointer1)
    {
      cout <<" nullptr is NULL" <<endl;
    }
  if(pointer==pointer2)
    {
      cout <<" nullptr is 0" <<endl;
    }
  if(pointer1==pointer2)
    {
      cout <<" 0 is NULL" <<endl;
    }


  int* something=pointer1;
  something=pointer;

  //doesn't work
  //  int number=nullptr;
  //  int number1=0;
  //  int number2=NULL;

   if(pointer==pointer1)
    {

    }


}
}
#endif
