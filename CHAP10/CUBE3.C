/***   CUBE3 calcule le volume d'un cube via une fonction sans paramätre  ***/

#include <stdio.h>

double cube2(void)             /* dÇfinit fct. 'cube2' : 'void' indique qu'il */
                                                 /* n'y a pas de paramätres   */
  {
     double e;   /* variable locale Ö la fonction cube2   */
     printf("Longueur de l'aràte du cube : ");
     scanf("%lf", &e);
     return (e * e * e);
  }

main()
  {
     /* appel de la fonction 'cube2' et affichage de la valeur de retour */
     
     printf("\nLe volume du cube est : %f", cube2());

  }
