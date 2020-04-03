/***   STRNGREL lit deux chaånes, les compare lexicographiquement    ***/
/***   et affiche le rÇsultat de la comparaison                      ***/

#include <stdio.h>                                /* pour printf, gets */
#include <string.h>                                     /* pour strcmp */
#include <conio.h>                                      /* pour getche */


main()
  {
    char first [81];
    char second [81];
    
    do
      {
        printf("\033[2J");
        printf("Le programme compare deux chaånes lexicographiquement.");
    
        printf("\n\nChaåne 1 : ");
        gets(first);
    
        printf("\n\n Chaåne 2 : ");
        gets(second);
    
        if (strcmp(first, second) > 0)       /* Çvaluation du rÇsultat */
           printf("\nChaåne 1 plus grande que chaåne 2.");
           else if (strcmp(first, second) < 0)
           printf("\n Chaåne 1 plus petite que chaåne 2.");
           else
           printf("\n Chaåne 1 Çgale Ö chaåne 2.");
  
       printf("\n\n<EntrÇe> pour continuer. Fin par <ECHAP>.");
       first[0] = getche();
  
      } while (first[0] != 27);            /* fin do while par <ECHAP> */
  }
