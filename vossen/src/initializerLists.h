#ifndef INIT_LISTS
#define INIT_LISTS

#include <map>
using namespace std;

namespace InitLists
{


class C1
{
  int x[4];
 public:
 C1(): x{0,1,2,3} {}
};

class C2
{
  int x=7; //class member initializer
 public:
  C2();
};


class C3
{

  int y[5] {1,2,3,4};
 public:
  C3();
};

class C4
{

  //() doesn't work...
  string s{"abc"};
  string s1=("abc");
  double d=0;
  char * p {nullptr};
  int y[5] {1,2,3,4};
 public:
  C4();

};

class C5
{
  int x=7; //class member initializer
 public:
  C5(){} //x is initialized to 7 when the default ctor is invoked
 C5(int y) : x(y) {} //overrides the class member initializer
};

void testInitLists()
{
 C5 c; //c.x = 7
  C5 c2(5); //c.x = 5

  //C++11: default initialization using {}
  int n{}; //zero initialization: n is initialized to 0
  int *p{}; //initialized to nullptr
  double d{}; //initialized to 0.0
  char s[12]{}; //all 12 chars are initialized to '\0'
  string s3{}; //same as: string s3;
  char *p2=new char [5]{}; // all five chars are initialized to '\0'

  //sequence constructor
  vector<int> vi {1,2,3,4,5,6};
  vector<double> vd {0.5, 1.33, 2.66};



  int a{0};
  string s4{"hello"};
  string s5{s4}; //copy construction
  vector <string> vs{"alpha", "beta", "gamma"};
  map<string, string> stars
    { {"Superman", "+1 (212) 545-7890"},
	{"Batman", "+1 (212) 545-0987"}};
  double *pd= new double [3] {0.5, 1.2, 12.99};
  double pdp[] {0.5, 1.2, 12.99,30};



}
}
#endif
