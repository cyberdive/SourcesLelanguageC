/***   CUBE2 calcule le volume d'un parall�l�pip�de   ***/

#include <stdio.h>

double parallel(double x, double y, double z)
                                     /* d�finition de la fonction 'parallel' */
   {
      return(x * y * z);
   }

main()
   {
      double longueur, largeur, hauteur;
      printf("Longueur, largeur, hauteur du parall�l�pip�de : ");
      scanf("%lf %lf %lf", &longueur, &largeur, &hauteur);
   
      /* appel de la fonction 'parallel' et affichage de la valeur de retour */
      printf("\nLe volume du parall�l�pip�de est : %f", 
              parallel(longueur, largeur, hauteur));
   }
