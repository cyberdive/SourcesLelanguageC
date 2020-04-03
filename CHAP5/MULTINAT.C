/*** MULTINAT lit des valeurs, les range dans un ***/
/*** tableau … 2 dimensions et les affiche       ***/
                                                    

#include <stdio.h>                                      /* pour printf, scanf */


main()
  {
     int k[3][4];                            /* tableau 2D pour les effectifs */
     int i, j;                                       /* Variables de contr“le */
     long s = 0;                                   /* nombre total d'employ‚s */
     
     printf("\033[2J");
     printf("Saisie des effectifs d'une multinationale."
            "3 filiales ayant chacune 4 agences r‚gionales.\n\n");
 
  /* saisie des valeurs */
 
     for (i = 0; i < 3; i++)                                        /* lignes */
         for(j = 0; j < 4; j++)                                   /* colonnes */
            {
              printf("Filiale %d Agence %d : ", i+1, j+1);
              scanf("%d", &k[ i ][ j ]);
            }
 
  /* calcul du total des effectifs */
  
     for (i = 0; i < 3; i++)                                        /* lignes */
         for(j = 0; j < 4; j++)                                   /* colonnes */
               s = s + k[ i ][ j ];
 
  /* affichage des valeurs */
  
     printf("\n\n\tA0\tA1\tA2\tA3\n");
     for (i = 0; i < 3; i++)                                        /* lignes */
         {
            printf("F%d\t", i);
            for(j = 0; j < 4; j++)                                /* colonnes */
                  printf("%d\t", k[ i ][ j ]);
                  printf("\n");
         }
  
     printf("\n\nNombre total d'employ‚s : %ld", s);

  }
