/**
 * @file Calc.hpp
 * @brief Basic calculation functions and logic.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-06-08
 */




#ifndef WXCALC_SRC_CALC_HPP
#define WXCALC_SRC_CALC_HPP




#include <stdexcept>
#include <cstdint>




namespace WxCalc
{


class Calc
{
  public:
    enum operation_type {
      OP_ADD,
      OP_SUB,
      OP_MUL,
      OP_DIV
    };

    /**
     * @brief Perform an operation and return the result.
     *
     * @param left The left input.
     * @param right The right input.
     * @param op The operation.
     *
     * @return The result (left op right).
     */
    static double performOperation(
        double left,
        double right,
        int op);
};


}


#endif
