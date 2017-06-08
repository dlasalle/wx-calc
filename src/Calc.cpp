/**
 * @file Calc.cpp
 * @brief Implementation of the Calc class.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-06-08
 */




#include "Calc.hpp"




namespace WxCalc
{


double Calc::performOperation(
    double const left,
    double const right,
    int const op)
{
  double result;

  switch (op) {
    case OP_ADD: {
      result = left + right;
      break;
    }
    case OP_SUB: {
      result = left - right;
      break;
    }
    case OP_MUL: {
      result = left * right;
      break;
    }
    case OP_DIV: {
      if (right != 0) {
        result = left / right;
      } else {
        throw std::runtime_error("Cannot divide by zero.");
      }
      break;
    }
    default: {
      // TODO: handle this in a meaningful way for the user.
      throw std::runtime_error("Unknown OP: " + std::to_string(op));
    }
  }

  return result;
}


}
