#ifndef LAMBDAS_H
#define LAMBDAS_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>


using namespace std;


function<int (float)> retLambda(int a, int& b)
{
  int c=5;
  //if this is & (i.e. pass by reference, it doesn't work... (a,b, are nonsense)
  return [=] (float d)mutable ->int {cout <<"lambda param: "<< d <<", a: "<< a <<" b : " << b << " c: "<< c <<endl; 
    b=7;
    cout <<" lambda b is now " << b <<endl;
    return a+b+c;};

}

void testVarByReference()
{
  int a=1;
  int b=2;
  int c=3.0;
  auto f=retLambda(a,b);
  cout <<" lambda returns " <<  f(c)<<endl;
  cout <<" b is now " << b <<endl;
}

namespace Lambdas
{


void testLambdas()
{
 
  testVarByReference();

  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout <<"run over vector with lambda " <<endl;
  std::for_each(std::begin(v),std::end(v),[](int n)
		{std::cout<<n<<std::endl;});

  auto is_odd=[](int n)->bool{return n%2==true;};
  auto pos=std::find_if(std::begin(v),std::end(v),
			  is_odd);
  cout <<"odd position: "<<endl;
  if(pos!=std::end(v))
    std::cout<<*pos<<std::endl;


  int a=5;
  auto testCopy=[&a]()mutable {a=7;};
  testCopy();
  cout <<"a is now " << a <<endl;


}




}
#endif
