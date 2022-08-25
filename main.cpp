#include "file.h"

int main(int argc, char* argv[])
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x_1 = NAN;
    double x_2 = NAN;
    int root_quantity = 0;

    if(argc > 1)
    {
        if(strcmp(argv[1], "-h") == 0)
            printf("The file name is %s\n", argv[0]);
    }

    #ifndef DEBUG_MOD
   
    printf("This is a program to solve a quadratic equation!\n");

    AnnounceCoeff(&a, &b, &c);

    while (CompareNumbers(a, 0, epsylon) != 1 ||
           CompareNumbers(b, 0, epsylon) != 1 || 
           CompareNumbers(c, 0, epsylon) != 1)
    {
        root_quantity = SolveSquare(a, b, c, &x_1, &x_2);
        PrintRoots(root_quantity, x_1, x_2);
        AnnounceCoeff(&a, &b, &c);
    }
    
    printf("The infinite number of solutions.\n");
    printf("Hope you liked this program!\n");

    #endif

    #ifdef DEBUG_MOD

        FILE *fp;
        
        if((fp = fopen("unit_tests.txt", "r")) == NULL)
        {
            fprintf(stdout, "The file can't be opened.\n");
            return EXIT_FAILURE;
        }

        DebugSolveSquare(fp, a, b, c, root_quantity, x_1, x_2);
        
        if(fclose(fp) != 0)
            fprintf(stderr, "Error by closing the file.\n ");
            
    #endif

    return 0;
}

