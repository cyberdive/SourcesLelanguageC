/*** SAMPLES lit, via une boucle, quelques valeurs statistiques (fr‚quences ***/
/*** de v‚hicules par jour) qui sont rang‚es dans un tableau. Les valeurs   ***/
/*** sont saisies au clavier, totalis‚es et r‚affich‚es pour contr“le (avec ***/
/*** leur total).                                                           ***/


#include <stdio.h>                                      /* pour printf, scanf */

main()
  {
     long vehicles [8];           /* nombre de v‚hicules pour chacun des sept */
                               /* jours. 8 ‚l‚ments et non 7 : Pour les jours */
                               /* 1 … 7 on utilise les ‚l‚ments vehicles[1] … */
                                                                                         /*  vehicles[7]. vehicles[0] reste libre. */
     long s = 0;                               /* total des v‚hicules compt‚s */
     short i;                                         /* Variable de contr“le */
     printf("\033[2J");
     printf("Entrez les nombres de v‚hicules pour les jours 1 - 7 :\n");

     for (i = 1; i < 8; i++)                              /* boucle de saisie */
         {
            printf("Jour %hd : ", i);
            scanf("%ld", &vehicles[i]);              /* op‚rateur d'adressage */
            s = s + vehicles[i];                              /* totalisation */
         }
 
     printf("\n\nOn a saisi les valeurs suivantes :\n\n");
     
     for (i = 1; i < 8; i++)
         printf("Jour %hd\t", i);
  
     
     printf("\n");

     for (i = 1; i < 8; i++)                            /* boucle d'affichage */
         printf("%ld\t", vehicles[i]);
     
     printf("\n\nNombre total de v‚hicules : %ld", s);
 
  }
