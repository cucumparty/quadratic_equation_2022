#include "file.h"

void announce(double * a, double * b, double * c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Enter number coefficents a, b and c (or 0 for every coefficent for exit).\n");
    printf("Enter number coefficent a:\n");
    *a = get_double();
    printf("Enter number coefficent b:\n");
    *b = get_double();
    printf("Enter number coefficent c:\n");
    *c = get_double();
}

double  get_double(void)
{
    double input;
    char ch;
    while(scanf("%lf", &input) != 1)
    {
        while((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a number.Please enter the number!\n");
    }
    return input;
}

void solve(double * x, double * y, double * z)
{
    assert(x != NULL);
    assert(y != NULL);
    assert(z != NULL);

    double x_1 = NAN;
    double x_2 = NAN;
    double d = NAN;
    double epsylone = 0.000001;
    double a, b, c; 

    a = * x;
    b = * y;
    c = * z;

    assert(isfinite(a) != 0);
    assert(isfinite(b) != 0);
    assert(isfinite(c) != 0);

    while (a != 0 || b != 0 || c != 0)
    {
        if( a != 0 && b != 0 && c != 0)
        {
            d = b * b - 4 * a * c; 
            double epsylon = 0.000001;                 //дискриминант
        
            if (d < 0)
            {
                printf("The equation can't be solved.\n");
            }
            if (d < (d + epsylon) && d > (d - epsylon))
            {
                x_1 = -b / (2 * a);
                printf("The solutions of equation are 2 repeating roots: %lf, %lf\n", x_1, x_1);
            }
            if (d > 0)
            {
                x_1 = (-b + sqrt(d)) / (2 * a);
                x_2 = (-b - sqrt(d)) / (2 * a);
                printf("The solutions of equation are 2 roots: %lf, %lf\n", x_1, x_2);
            }
        }


        if(a == 0 && b == 0 && c != 0)
            printf("The equation can't be solved.\n");

        if(a == 0 && b != 0)
        {
            x_1 = -c / b;
            printf("The solution is 1 root: %lf\n", x_1);
        }

        if(b == 0 && a != 0 && c != 0)
        {
            if(a * c > 0)
                printf("The equation can't be solved.\n");
            else
            {
                x_1 = sqrt(-c / a);
                x_2 = -sqrt(-c / a);
                printf("The solutions of equation are 2 roots: %lf, %lf\n", x_1, x_2);
            }
        }
    
        if(c == 0 && a != 0)
        {
            x_1 = -b / a;
            printf("The solutions of equation are 2 roots: 0.0000000, %lf\n", x_1);
        }

        announce(&a, &b, &c);
        printf("The infinite number of solutions.\n");
    }

}


