#ifndef INLINE_NS_H
#define INLINE_NS_H


namespace InlineNS
{

namespace inner_ordinaryNS
{
  int ordinary=3;

}


inline namespace inner_inlineNS
{

  int nonOrdinary=4;

}



//what will happen now?? 
//if inline is missing compiler complains (cannot be reopened as non-inline NS)
inline namespace inner_inlineNS
{
  //will this be the same?

  int ordinary=6;
}

void testInlineNS()
{
  //not sure what to say about inline namespaces...

  cout <<"ordinary from inline is: "<< ordinary <<endl;
  int ordinary=2;
  cout <<"now ordinary is : " << ordinary << "inline ordinary: "<< inner_inlineNS::ordinary <<endl;
  int nonOrdinary=5;

}


}
#endif


#ifdef __VERSION_1
inline
#endif
namespace version1_NS
{

}
