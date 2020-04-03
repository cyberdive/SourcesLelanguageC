/*  intout8 montre la diff‚rence entre %d et %u.  */
#include <stdio.h>
main()
{
   printf("4 et 65532 en tant que nombres sans signe : %u %u\n\n", 4, 65532);
   printf("4 et 65532 en tant que nombres avec signe : %d %d", 4, 65532);
}
