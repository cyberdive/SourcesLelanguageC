/***    showsize calcule la dimension (l'occupation m‚moire)        ***/
/***    de diff‚rents tableaux                                      ***/


#include <stdio.h>                                     /* pour printf */

main()
  {
    double d [10];
    float f [10];
    long l [10];
    int i [10];
    short s [10];
    char c [10];


    printf("%d %d %d %d %d %d\n",
        sizeof(d), sizeof(f), sizeof(l), sizeof(i), sizeof(s), sizeof(c));
        printf("%d %d %d %d %d %d",
            sizeof(double[10]), sizeof(float[10]), sizeof(long[10]),
               sizeof(int[10]), sizeof(short[10]), sizeof(char[10]));
  }
