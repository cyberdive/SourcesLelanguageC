/*** TRIANGLE calcule la surface d'un triangle … partir des longueurs    ***/
/*** des c“t‚s, celles-ci ‚tant pass‚es sur la ligne de commande.        ***/

#include <stdio.h>                                               /* printf */
#include <math.h>                                            /* atof, sqrt */
#include <stdlib.h>                                                /* exit */

main(int argc, char *argv[])
 {
   double a, b, c, s;
   
   if (argc != 4)
      {
        printf("\n\nNombre de paramŠtres erron‚.");
        exit(1);
      }    
   
   a = atof(argv[1]);
   b = atof(argv[2]);
   c = atof(argv[3]);
   
   if (a+b <= c  ||  a+c <= b  ||  b+c <= a)
      {
        printf("\n\nParamŠtres invalides. Triangle incoh‚rent.");
        exit(2);
      }
   else
      {
        s = (a + b + c) / 2;
        printf("\n\nLe triangle a une surface de : %f", sqrt(s * (s-a)
                       * (s-b) * (s-c)));
      }
 }
