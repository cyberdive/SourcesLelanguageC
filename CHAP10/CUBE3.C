/***   CUBE3 calcule le volume d'un cube via une fonction sans param�tre  ***/

#include <stdio.h>

double cube2(void)             /* d�finit fct. 'cube2' : 'void' indique qu'il */
                                                 /* n'y a pas de param�tres   */
  {
     double e;   /* variable locale � la fonction cube2   */
     printf("Longueur de l'ar�te du cube : ");
     scanf("%lf", &e);
     return (e * e * e);
  }

main()
  {
     /* appel de la fonction 'cube2' et affichage de la valeur de retour */
     
     printf("\nLe volume du cube est : %f", cube2());

  }
