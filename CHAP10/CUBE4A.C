/* cube4 calcule le volume d'un cube */
#include <stdio.h>
main()
{
   double cube(double x);   /* d‚claration de la fonction 'cube' : obligatoire car
       'cube' est appel‚e avant d'ˆtre d‚finie */
   double e;
   double volume;
   printf("Longueur de l'arˆte : ");
   scanf("%lf", &e);
   volume = cube(e);   /* Appel de la fonction 'cube' et affectation de
      la valeur retourn‚e … la variable 'volume' */
   printf("\nLe volume du cube est : %f", volume);
}
double cube(double x)   /* d‚finition de la fonction 'cube' */
{
   return(x * x * x);
}
