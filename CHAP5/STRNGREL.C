/***   STRNGREL lit deux cha�nes, les compare lexicographiquement    ***/
/***   et affiche le r�sultat de la comparaison                      ***/

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
        printf("Le programme compare deux cha�nes lexicographiquement.");
    
        printf("\n\nCha�ne 1 : ");
        gets(first);
    
        printf("\n\n Cha�ne 2 : ");
        gets(second);
    
        if (strcmp(first, second) > 0)       /* �valuation du r�sultat */
           printf("\nCha�ne 1 plus grande que cha�ne 2.");
           else if (strcmp(first, second) < 0)
           printf("\n Cha�ne 1 plus petite que cha�ne 2.");
           else
           printf("\n Cha�ne 1 �gale � cha�ne 2.");
  
       printf("\n\n<Entr�e> pour continuer. Fin par <ECHAP>.");
       first[0] = getche();
  
      } while (first[0] != 27);            /* fin do while par <ECHAP> */
  }
