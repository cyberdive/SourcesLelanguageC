/* whiblock montre l'effet des accolades sur l'ex‚cution des instructions du
                                                           corps de la boucle */

#include <stdio.h>                                             /* pour printf */

main()
{
  int a = -4;
  while (a != 0)
   {                                                          /* instructions */
    a++;                                                     /* sous forme de */
    printf("%d\t", a);                                                /* bloc */
   }                                                       /* entre accolades */
   printf("\n\n");
   a = -4;                                              /* a est r‚initialis‚ */
     
  while (a != 0)
  a++;                                            /* instructions non plac‚es */
   printf("%d\t", a);                              /* entre accolades de bloc */
}

