#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#ifndef FILE_H_
#define FILE_H_

const double epsylon = 0.000001;

void announce(double * a, double * b, double * c);
double get_double(void);
int compare(double  x, double  y, const double  epsylon);
void linear(double * b, double * c);
void solve(double * a, double * b, double * c);

#endif