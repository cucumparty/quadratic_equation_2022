#include "file.h"

//#define DEBUG_MOD

int main()
{
    #ifdef DEBUG_MOD
    printf("debug mod\n");
    #endif
    
    #ifndef DEBUG_MOD
    double a = NAN;
    double b = NAN;
    double c = NAN;
   
    printf("This is a program to solve a quadratic equation!\n");

    announce(&a, &b, &c);

    solve(&a, &b, &c);

    printf("Hope you liked this program!\n");
    return 0;
    #endif
}

