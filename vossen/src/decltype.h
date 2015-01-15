#ifndef DECLTYPE_H
#define DECLTYPE_H

namespace Decltypes
{

class A
{
 public:
  int makeObject() const
  {return 8;};
  A(){};
};


template <typename Builder>
auto
  makeAndProcessObject (const Builder& builder) -> decltype( builder.makeObject() )
  {
    auto val = builder.makeObject();
    // do stuff with val
    return val;
  }


void testDeclType()
{

  A a;
  int x=7;
  decltype(x) y=x;
  //same thing
  auto y2=x;


  auto f = [] (int a, int b) -> int { return a*b;};

  decltype(f) f2=f;
  //works as well, so why use decltype here?
  auto f3=f;

  cout <<" playing with decltype ";
  cout <<"value of make and process: " <<   makeAndProcessObject(a)<<endl;
  cout <<"running f(1,2): " << f(1,2) <<" f2: "<< f2(1,2) <<" f2: "<< f3(1,2) <<endl;


}

}
#endif
