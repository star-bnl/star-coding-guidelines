#ifndef ALIGNMENTS_H
#define ALIGNMENTS_H
#include <iostream>
 #include <memory>
#include <string>



namespace Alignment
{

  template <std::size_t N>
struct MyAllocator
{
  char data[N];
  void* p;
  std::size_t sz;
MyAllocator() : p(data), sz(N) {}
    template <typename T>
    T* aligned_alloc(std::size_t a = alignof(T))
  {
    if (std::align(a, sizeof(T), p, sz))
      {
	T* result = reinterpret_cast<T*>(p);
	p = (char*)p + sizeof(T);
	sz -= sizeof(T);
	return result;
      }
    return nullptr;
  }
};
 

struct S1
    {
      std::string file;
    };
struct S2
{
S2(const std::string &from, const std::string &to) : from{ from }, to{ to }
  {
  }
  std::string from;
  std::string to;
};

  alignas(double) unsigned char c[1024]; // array of characters, suitably aligned for doubles
  alignas(16) char c2[100];// align on 16 byte boundary

  struct Empty {};
 
  struct Foo {
    int f2;
    float f1;
    char c;
  };
 



void testAlignment()
{
    std::cout << "alignment of empty class: " << alignof(Empty) << '\n'
              << "alignment of pointer : "    << alignof(int*)  << '\n'
              << "alignment of char : "       << alignof(char)  << '\n'
              << "alignment of Foo : "        << alignof(Foo)   << '\n' ;



    std::aligned_union<sizeof(S2), S1, S2>::type storage;

    S2 * p = new (static_cast<void*>(std::addressof(storage))) S2("from", "to");

    // ...

    p->~S2();


    MyAllocator<64> a;
 
    // allocate a char
    char* p1 = a.aligned_alloc<char>();
    if (p1)
      *p1 = 'a';
    std::cout << "allocated a char at " << (void*)p1 << '\n';
 
    // allocate an int
    int* p2 = a.aligned_alloc<int>();
    if (p2)
      *p2 = 1;
    std::cout << "allocated an int at " << (void*)p2 << '\n';
 
    // allocate an int, aligned at 32-byte boundary
    int* p3 = a.aligned_alloc<int>(32);
    if (p3)
      *p3 = 2;
    std::cout << "allocated an int at " << (void*)p3 << " (32 byte alignment)\n";
}


}

#endif
