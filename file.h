//!@mainpage
//!Program for solving quadratic equations. 
//!An equation of the form ax^2+bx+c=0. 3 coefficients @c a, @c b, and @c c are entered.

#ifndef FILE_H_
//! Check if this file wasn't included more than 1 time
#define FILE_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//! \mainpage Use DEBUG_MOD to run unit tests to check the program
//!
//! @note Comment DEBUG_MOD if you want to use the program as usual
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

//! Announce coefficients in the square equation ax^2 + bx + c = 0
//!
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
void AnnounceCoeff(double* a, double* b, double* c);

//! Check if the entered symbol the number is
//! 
//! @param [out] ch Non-numeric symbols
double GetDouble(void);

//! Compare 2 double numbers with help of epsylon
//!
//! @param [in] x First number
//! @param [in] y Second number
//! @param [in] epsylon Constant for comparing
//! 
//! @return TRUE if two double numbers are equal(FALSE if not)
int CompareNumbers(double  x, double  y, const double  epsylon);

//! Solve the square equation ax^2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x_1 Pointer to the 1st root
//! @param [out] x_2 Pointer to the 2nd root
//!
//! @return Number of roots
//! 
//! @note If all the coefficients zeroes the program exits.
int SolveSquare(double a, double b, double c, double* x_1, double* x_2);

//! Solve the equation bx + c = 0
//!
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x_1 Pointer to the root
//!
//! @return Number of roots
int SolveLinear(double b, double c, double* x_1);

//! Announce coefficients, number of roots and roots for debug from file "unit_tests.txt"
//!
//! @param [in] fp Pointer to file "unit_tests.txt"
//! @param [in] a Pointer to the a-coefficient from file
//! @param [in] b Pointer to the b-coefficient from file
//! @param [in] c Pointer to the c-coefficient from file
//! @param [in] test_root_quantity Pointer to the number of roots from file
//! @param [in] test_x_1 Pointer to the first root from file
//! @param [in] test_x_2 Pointer to the second root from file
void DebugScan(FILE* fp, double* a, double* b, double* c, int* test_root_quantity, double* test_x_1, double* test_x_2);

//! Solve the square equation ax^2 + bx + c = 0 with the coefficients from file and check the resulting roots with our function <int solve> with test roots
//!
//! @param [in] fp Pointer to file "unit_tests.txt"
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [in] root_quantity quantity of roots
//! @param [in] x_1 1st root
//! @param [in] x_2 2nd root
//! 
//! @note The function compares quantity of roots and roots from file with the results of our program
void DebugSolveSquare(FILE* fp, double a, double b, double c, int root_quantity, double x_1, double x_2);

//! Switch for printing the roots
//!
//! @param [in] root_quantity quantity of roots
//! @param [in] x_1 1st root
//! @param [in] x_2 2nd root
void PrintRoots(int root_quantity, double x_1, double x_2);

#endif