//
//  ProjectMain.cpp
//  
//
//  Created by Anselm Vossen on 11/30/14.
//
//

#include "ProjectMain.h"
#include "nullPtr.h"
#include "strongEnums.h"
#include "lambdas.h"
#include "initializerLists.h"
#include "decltype.h"
#include "alignments.h"
#include "inlineNS.h"

constexpr int someFunction(int x)
{
  return x*4;
};

int main(int argc, char** argv)
{
  NullPtr::testNullPtr();
  StrongEnums::testStrongEnums();
  Lambdas::testLambdas();
  InitLists::testInitLists();
  Decltypes::testDeclType();    
  InlineNS::testInlineNS();
  Alignment::testAlignment();
  int y=someFunction(30);

  return 0;
}
