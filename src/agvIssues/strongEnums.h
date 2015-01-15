#ifndef STRONG_ENUMS_H
#define STRONG_ENUMS_H

#include <stdio.h>
#include <iostream>

using namespace std;
namespace StrongEnums
{


enum WeakEnum{one, two,three};
enum WeakEnum2{one2, two2,three2};


enum class C2 {
    one, two, three, four
      };

 enum class  strongEnum : int{first, second};

void testStrongEnums()
{
enum class C {one, two, three};

  C myEnum=C::one;
  C2 myEnum2;
  //doesn't work, is weak..
  //  C myEnum3=one;
  WeakEnum myWeakEnum=two;
  //cannot assign int to enum
  //  myWeakEnum=1;
  //  myEnum=one;
  //  myEnum2=C2::one;
  strongEnum mStrongEnum=strongEnum::first;
  int c=static_cast<int>(strongEnum::first);
  cout <<"hello, strong enums!"<<endl;
  cout <<" myenum is : "<< myWeakEnum<<endl;
  //for some reason doesn't work w/o cast...
  cout <<" strong enum first: " << (int) mStrongEnum <<endl;
  mStrongEnum=strongEnum::second;
  cout <<" strong enum second: " << static_cast<int>( mStrongEnum )<<endl;
  //    cout <<" strong enum first: " << strongEnum::first <<endl;
  //doesn't compile...even though underlying type should be int by default...
  // cout <<"strong enum is: " << myEnum<<endl;

}
}
#endif
