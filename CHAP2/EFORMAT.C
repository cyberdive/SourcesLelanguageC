/*  eformat affiche des valeurs … virgule flottante sous forme exponentielle.  */
#include <stdio.h>
main()
{
   printf("%e  %E  %e  %E", 314.0, 0.00314, 0.0314E4, 314.0e-5);
}
