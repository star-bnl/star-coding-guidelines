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

int main(int argc, char** argv)
{
  NullPtr::testNullPtr();
  StrongEnums::testStrongEnums();
  Lambdas::testLambdas();
    
    
    
    return 0;
}
