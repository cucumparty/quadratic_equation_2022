#include "file.h"


int main()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x_1 = NAN;
    double x_2 = NAN;
    int root_number = 0;

    #ifdef DEBUG_MOD

        int test_number = 0;
        double test_x_1 = NAN;
        double test_x_2 = NAN;
        int test_root_number = 0;

        FILE *fp;

        int i = 0;


        if((fp = fopen("unit_tests.h", "r")) == NULL)
        {
            fprintf(stdout, "The file unit_tests.h can't be opened.\n");
            exit(EXIT_FAILURE);
        }

        fscanf(fp, "%d", &test_number);

        for (i = 1; i < (test_number + 1); i ++)
        {
            fscanf(fp, "%lf", &a);
            fscanf(fp, "%lf", &b);
            fscanf(fp, "%lf", &c);

            fscanf(fp, "%d", &test_root_number);
            fscanf(fp, "%lf", &test_x_1);
            fscanf(fp, "%lf", &test_x_2);

            root_number = solve(a, b, c, &x_1, &x_2);

            if(compare(root_number, test_root_number, epsylon) == 1 && compare(test_x_1, x_1, epsylon) == 1 && compare(test_x_2, x_2, epsylon) == 1 )
                printf("Test  %d completed\n", i);
            else
                printf("Test  %d  was not completed\n", i);

            x_1 = 0;
            x_2 = 0;
        }
        
        if(fclose(fp) != 0)
            fprintf(stderr, "Error by closing the file.\n ");


    #endif
    
    #ifndef DEBUG_MOD
   
    printf("This is a program to solve a quadratic equation!\n");

    announce(&a, &b, &c);

    while (compare(a, 0, epsylon) != 1 || compare(b, 0, epsylon) != 1 || compare(c, 0, epsylon) != 1)
    {
        root_number = solve(a, b, c, &x_1, &x_2);
        announce(&a, &b, &c);
    }
    
    printf("The infinite number of solutions.\n");
    printf("Hope you liked this program!\n");
    return 0;
    #endif
}

