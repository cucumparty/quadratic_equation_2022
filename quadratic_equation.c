#include <stdio.h>
#include <math.h>

double get_double(void);

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double x_1 = 0;
    double x_2 = 0;
    double d = 0;

    printf("This is a program to solve a quadratic equation!\n");
    printf("Enter number coefficents a, b and c (or 0 for every coefficent for exit).\n");
    printf("Enter number coefficent a:\n");
    a = get_double();
    printf("Enter number coefficent b:\n");
    b = get_double();
    printf("Enter number coefficent c:\n");
    c = get_double();

    while (a != 0 || b != 0 || c != 0)
    {
        d = b * b - 4 * a * c;                  //дискриминант
        
        if (d < 0)
        {
            printf("The equation can't be solved.\n");
            
        }
        if (d == 0)
        {
            x_1 = -b / (2 * a);
            printf("The solution of equation is 2 repeating roots: %lf, %lf\n", x_1, x_1);
        }
        if (d > 0)
        {
            x_1 = (-b + sqrt(d)) / (2 * a);
            x_2 = (-b - sqrt(d)) / (2 * a);
            printf("The solution of equation is 2 roots: %lf, %lf\n", x_1, x_2);
        }

        printf("Enter number coefficents a, b and c (or 0 for every coefficent for exit).\n");
        printf("Enter number coefficent a:\n");
        a = get_double();
        printf("Enter number coefficent b:\n");
        b = get_double();
        printf("Enter number coefficent c:\n");
        c = get_double();
    }
     printf("Hope you liked this program!\n");
    return 0;
}

double get_double(void)
{
    double input;
    char ch;
    while(scanf("%lf", &input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.Please enter the number!\n");
    }
    return input;
}