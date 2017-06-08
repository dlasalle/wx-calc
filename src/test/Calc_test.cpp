/**
 * @file Calc_test.cpp
 * @brief Unit tests for the Calc class.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-06-08
 */



#include <iostream>
#include "Calc.hpp"


#define TEST(func) \
  do { \
    if (func()) { \
      std::cout << #func << " test passed." << std::endl; \
    } else { \
      std::cerr << #func << " test failed." << std::endl; \
      return 1; \
    } \
  } while (0)

using namespace WxCalc;

namespace
{

bool addTest() 
{
  double x = 2.0;
  double y = 3.0;

  double result = Calc::performOperation(x,y,Calc::OP_ADD);

  return result == x + y;
}

bool subtractTest() 
{
  double x = 2.0;
  double y = 3.0;

  double result = Calc::performOperation(x,y,Calc::OP_SUB);

  return result == x - y;
}

bool multiplyTest() 
{
  double x = 2.0;
  double y = 3.0;

  double result = Calc::performOperation(x,y,Calc::OP_MUL);

  return result == x * y;
}

bool divideTest() 
{
  double x = 3.0;
  double y = 2.0;

  // make sure we result in a number that is perfectly representable by IEEE754
  // that is only has negative powers of two in the mantissa.
  double result = Calc::performOperation(x,y,Calc::OP_DIV);

  return result == x / y;
}

}

int main(
    int,
    char **)
{
  TEST(addTest);
  TEST(subtractTest);
  TEST(multiplyTest);
  TEST(divideTest);

  return 0;
}
