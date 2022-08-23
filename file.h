#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define DEBUG_MOD

//! Use DEBUG_MOD to run unit tests to check the program

#ifndef FILE_H_
#define FILE_H_

const double epsylon = 0.000001;

void announce(double* a, double* b, double* c);

//! Announce coefficients in the square equation ax^2 + bx + c = 0
//!
//! @param [in] Pointer to the a-coefficient
//! @param [in] Pointer to the b-coefficient
//! @param [in] Pointer to the c-coefficient

double get_double(void);

//! Check if the entered symbol the number is
//! 
//! @return Non-numeric symbols

int compare(double  x, double  y, const double  epsylon);

//! Compare 2 double numbers with help of epsylon
//!
//! @param [in] First number
//! @param [in] Second number
//! @param [in] epsylon 
//! 
//! @return 1 if two double numbers are equal(0 if not)

int solve(double a, double b, double c, double* x_1, double* x_2);

//! Solve the square equation ax^2 + bx + c = 0
//!
//! @param [in] a-coefficient
//! @param [in] b-coefficient
//! @param [in] c-coefficient
//! @param [out] Pointer to the 1st root
//! @param [out] Pointer to the 2nd root
//!
//! @return Number of roots
//! 
//! @note If all the coefficients zeroes the program exits.

int linear(double b, double c, double* x_1);

//! Solve the equation bx + c = 0
//!
//! @param [in] b-coefficient
//! @param [in] c-coefficient
//! @param [out] Pointer to the root
//!
//! @return Number of roots


#endif