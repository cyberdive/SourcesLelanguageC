/****   'cube' calcule le volume d'un cube    ***/

#include <stdio.h>

double cube(double x)                   /* d�finition de la fonction 'cube'   */
  {
     return(x * x * x);
  }

main()
  {
     double e;                               /* longueur de l'ar�te du cube   */
     double volume;                                       /* Volume du cube   */
     
     printf("Longueur de l'ar�te : ");
     scanf("%lf", &e);
     
     volume = cube(e);       /* Appel de la fonction 'cube' et affectation de */
                              /* la valeur retourn�e � la variable 'volume'   */
   
     printf("\nLe volume du cube est : %f", volume);
  }
