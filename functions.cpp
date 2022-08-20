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

int compare(double  x, double  y, const double  epsylon)
{
    if(fabs(x - y) < epsylon)
        return 1;
    else
        return 0;
}

void linear(double * b, double * c)
{
    assert(b != NULL);
    assert(c != NULL);

    assert(isfinite(*b));
    assert(isfinite(*c));

    double x_1 = NAN;

    if(compare(*b, 0, epsylon) != 1 && compare(*c, 0, epsylon) != 1)
    {
        x_1 = -(*c) / (*b);
        printf("The solution is 1 root: %lf\n", x_1);
    }
    if(compare(*b, 0, epsylon) == 1 && compare(*c, 0, epsylon) != 1)
    {
        printf("The equation can't be solved.\n");
    }
}


void solve(double * x, double * y, double * z)
{
    assert(x != NULL);
    assert(y != NULL);
    assert(z != NULL);

    double x_1 = NAN;
    double x_2 = NAN;
    double d = NAN;
    double a, b, c; 

    a = * x;
    b = * y;
    c = * z;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    while (compare(a, 0, epsylon) != 1 || compare(b, 0, epsylon) != 1 || compare(c, 0, epsylon) != 1)
    {
        if( compare(a, 0, epsylon) != 1)
        {
            if(compare(b, 0, epsylon) != 1 && compare(c, 0, epsylon) != 1)
            {
                d = b * b - 4 * a * c;               //дискриминант
        
                if (d < 0)
                {  
                    printf("The equation can't be solved.\n");
                }
                if (compare(d, 0, epsylon) == 1)
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
            if(compare(b, 0, epsylon) == 1 && compare(c, 0, epsylon) != 1)
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
            if(compare(b, 0, epsylon) != 1 && compare(c, 0, epsylon) == 1)
            {
                x_1 = 0.000000;
                x_2 = -b / a;
                printf("The solutions of equation are 2 roots: %lf, %lf\n", x_1, x_2);
            }
        }
        else
            linear(&b, &c);

        announce(&a, &b, &c);
    }
    
    printf("The infinite number of solutions.\n");

}