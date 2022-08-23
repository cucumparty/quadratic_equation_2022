#include "file.h"

void announce(double* a, double* b, double* c)
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
    double input = NAN;
    char ch = '\0';

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

int linear(double b, double c, double* x_1)
{
    assert(x_1 != NULL);

    assert(isfinite(b));
    assert(isfinite(c));

    if(compare(b, 0, epsylon) == FALSE)
    {
        if (compare(c, 0, epsylon) == FALSE)
            *x_1 = -c / b;
        else 
            *x_1 = 0;
        return 1;
    }
    else
    {
        if(compare(c, 0, epsylon) == FALSE)
            return 0;
        else
            return -1;
    }
}


int solve(double a, double b, double c, double* x_1, double* x_2)
{
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    double discriminant = NAN;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if( compare(a, 0, epsylon) == FALSE)
    {
        if(compare(b, 0, epsylon) == FALSE && compare(c, 0, epsylon) == FALSE)
        {
            discriminant = b * b - 4 * a * c;               
        
            if (discriminant < 0)
                return 0;
            if (compare(discriminant, 0, epsylon) == TRUE)
            {
                *x_1 = -b / (2 * a);
                *x_2 = *x_1;
                return 2;
            }
            if (discriminant > 0)
            {
                *x_1 = (-b + sqrt(d)) / (2 * a);
                *x_2 = (-b - sqrt(d)) / (2 * a);
                return 2;
            }
        }
        if(compare(b, 0, epsylon) == TRUE && compare(c, 0, epsylon) == FALSE)
        {
            if(a * c > 0)
                return 0;
            else
            {
                *x_1 = sqrt(-c / a);
                *x_2 = -sqrt(-c / a);
                return 2;
            }
        }
        if(compare(c, 0, epsylon) == TRUE)
        {
            if(compare(b, 0, epsylon) == FALSE)
            {
                *x_1 = 0.0;
                *x_2 = -b / a;
                return 2;
            }
            else
            {
                *x_1 = 0.0;
                *x_2 = 0.0;
                return 2;
            }
        }
    }
    else
        return linear(b, c, x_1);

    return 0;
}

void debug_solution(FILE* fp, double a, double b, double c, int root_number, double x_1, double x_2)
{
    int test_number = 0;
    double test_x_1 = NAN;
    double test_x_2 = NAN;
    int test_root_number = 0;
    int i = 0;

    fscanf(fp, "%d", &test_number);

    for (i = 1; i < (test_number + 1); i ++)
    {
        debug_scan(fp, &a, &b, &c, &test_root_number, &test_x_1, &test_x_2);

        root_number = solve(a, b, c, &x_1, &x_2);
        print_roots(root_number, x_1, x_2);

        if(compare(root_number, test_root_number, epsylon) == TRUE && 
           compare(test_x_1, x_1, epsylon) == TRUE && 
           compare(test_x_2, x_2, epsylon) == TRUE )
            printf("Test  %d completed\n", i);
        else
            printf("Test  %d  was not completed\n", i); 
                         
        x_1 = 0;
        x_2 = 0;
    }
}

void debug_scan(FILE* fp, double* a, double* b, double* c, int* test_root_number, double* test_x_1, double* test_x_2)
{
    fscanf(fp, "%lf", a);
    fscanf(fp, "%lf", b);
    fscanf(fp, "%lf", c);

    fscanf(fp, "%d", test_root_number);
    fscanf(fp, "%lf", test_x_1);
    fscanf(fp, "%lf", test_x_2);
}

void print_roots(int root_number, double x_1, double x_2)
{
    switch(root_number)
    {
        case ZERO_ROOTS:
            printf("The equation can't be solved.\n");
            break;
        case ONE_ROOT:
            printf("The solution is 1 root: %lf\n", x_1);
            break;
        case TWO_ROOTS:
            printf("The solutions of equation are 2 roots: %lf, %lf\n", x_1, x_2);
            break;
        case INF_ROOTS:
            printf("The infinite number of solutions.\n");
            break;
        default:
            printf("Error");
            break;
    }
}