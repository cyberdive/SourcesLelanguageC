/*  wide affiche des valeurs avec sp‚cification de largeur d'affichage.  */
#include <stdio.h>
main()
{
   printf("%d\n%1d\n%4d\n\n", 17, 17, 17);
   printf("%f\n%4f\n%16f\n\n", 3.141593, 3.141593, 3.141593);
   printf("%s\n%4s\n%12s\n\n", "string", "string", "string");
}
