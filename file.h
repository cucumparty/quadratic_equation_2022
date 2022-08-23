#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------
//! Use DEBUG_MOD to run unit tests to check the program
//!
//! @note Comment DEBUG_MOD if you want to use the program as usual
//------------------------------------------------------

#define DEBUG_MOD

//! Constant for comparing

const double epsylon = 0.000001;

//! Boolean variables

enum m_boolean{
    TRUE = 1,
    FALSE = 0
};

//! Names for number of roots

enum roots{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = -1
};

//----------------------------------------------------------------
//! Announce coefficients in the square equation ax^2 + bx + c = 0
//!
//! @param [in] Pointer to the a-coefficient
//! @param [in] Pointer to the b-coefficient
//! @param [in] Pointer to the c-coefficient
//----------------------------------------------------------------

void announce(double* a, double* b, double* c);

//-------------------------------------------
//! Check if the entered symbol the number is
//! 
//! @return Non-numeric symbols
//-------------------------------------------

double get_double(void);

//-----------------------------------------------
//! Compare 2 double numbers with help of epsylon
//!
//! @param [in] First number
//! @param [in] Second number
//! @param [in] epsylon 
//! 
//! @return 1 if two double numbers are equal(0 if not)
//------------------------------------------------

int compare(double  x, double  y, const double  epsylon);

//--------------------------------------------------------
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
//--------------------------------------------------------

int solve(double a, double b, double c, double* x_1, double* x_2);

//--------------------------------
//! Solve the equation bx + c = 0
//!
//! @param [in] b-coefficient
//! @param [in] c-coefficient
//! @param [out] Pointer to the root
//!
//! @return Number of roots
//--------------------------------

int linear(double b, double c, double* x_1);

//---------------------------------------------------------------------------------------
//! Announce coefficients, number of roots and roots for debug from file "unit_tests.txt"
//!
//! @param [in] Pointer to file "unit_tests.txt"
//! @param [in] Pointer to the a-coefficient from file
//! @param [in] Pointer to the b-coefficient from file
//! @param [in] Pointer to the c-coefficient from file
//! @param [in] Pointer to the number of roots from file
//! @param [in] Pointer to the first root from file
//! @param [in] Pointer to the second root from file
//----------------------------------------------------------------------------------------

void debug_scan(FILE* fp, double* a, double* b, double* c, int* test_root_quantity, double* test_x_1, double* test_x_2);

//----------------------------------------------------------------------------------
//! Solve the square equation ax^2 + bx + c = 0 with the coefficients from file and check the resulting roots with our function <int solve> with test roots
//!
//! @param [in] Pointer to file "unit_tests.txt"
//! @param [in] a-coefficient
//! @param [in] b-coefficient
//! @param [in] c-coefficient
//! @param [in] quantity of roots
//! @param [in] 1st root
//! @param [in] 2nd root
//! 
//! @note The function compares quantity of roots and roots from file with the results of our program
//-----------------------------------------------------------------------------------

void debug_solution(FILE* fp, double a, double b, double c, int root_quantity, double x_1, double x_2);

//----------------------------------------------
//! Switch for printing the roots
//!
//! @param [in] Pointer to file "unit_tests.txt"
//! @param [in] a-coefficient
//! @param [in] b-coefficient
//! @param [in] c-coefficient
//! @param [in] quantity of roots
//! @param [in] 1st root
//! @param [in] 2nd root
//-----------------------------------------------

void print_roots(int n, double x_1, double x_2);
#endif