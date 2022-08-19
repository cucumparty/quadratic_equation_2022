#include "file.h"

int main()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
   
    printf("This is a program to solve a quadratic equation!\n");

    announce(&a, &b, &c);

    solve(&a, &b, &c);

    printf("Hope you liked this program!\n");
    return 0;
}

