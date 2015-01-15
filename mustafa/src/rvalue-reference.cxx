#include <cstddef>
#include <iostream>

using namespace std;

class dataHandler
{
  private:
    int* mData;

  public:
    dataHandler(int x=-999): mData(new int(x)) {cout<<__PRETTY_FUNCTION__<<endl;}

    // copy constructor
    dataHandler(const dataHandler& x): mData(new int(x.data())) {cout<<__PRETTY_FUNCTION__<<endl;}

    // copy assignment operator
    dataHandler& operator=(const dataHandler& rhs)
    {
      cout<<__PRETTY_FUNCTION__<<endl;

      if(this == &rhs) return *this;
      *(this->mData) = *(rhs.mData); // copy value
      return *this;
    }

    // move constructor
    dataHandler(dataHandler&& x)
    {
      cout<<__PRETTY_FUNCTION__<<endl;
      this->mData = x.mData;
      x.mData = nullptr;
    }

    // move assignment operator
    dataHandler& operator=(dataHandler&& rhs)
    {
      cout<<__PRETTY_FUNCTION__<<endl;

      if(this == &rhs) return *this;

      this->mData = rhs.mData;
      rhs.mData = nullptr;

      return *this;
    }

    ~dataHandler(){ cout<<__PRETTY_FUNCTION__<<endl; if(mData) delete mData;}

    inline int data() const { return *mData;}
    inline void data(int const d) { *mData = d;}
};

dataHandler get_a_dataHandler()
{
  dataHandler t(6);
  return t;
}

int main()
{
  cout<<"Testing move semantics..."<<endl;
  dataHandler t0;
  t0 = get_a_dataHandler(); // should call move assignment operator.

  dataHandler t1(get_a_dataHandler()); // should call move constructor (unless optimized away. See RVO/elision). 
 
  cout<<"... GoodBye! ..."<<endl;

  return 0;
}
