/***  showmax2 calcule le maximum de deux nombres saisis par l'utilisateur  ***/

#include <stdio.h>                                           /* printf, scanf */

long lcomp(long a, long b)               /* d‚finition de la fonction 'lcomp' */
  {
     return (a - b);
  }

main()
  {
     long x, y, result;
     
     printf("\033[2J");
     printf("Le programme d‚termine le plus grand de deux entiers\n"
            "compris entre -2 000 000 000 et +2 000 000 000.");
   
     printf("\n\nPremier entier : ");
     scanf("%ld", &x);
     printf("\n\nSecond entier : ");
     scanf("%ld", &y);
   
     /* affichage du plus grand des deux nombres */
   
     if ((result = lcomp(x, y)) > 0)  /* si valeur renvoy‚e par 'lcomp' > 0 ? */
          printf("\n\nLe maximum est %ld.", x);
     else if (result < 0)             /* si valeur renvoy‚e par 'lcomp' < 0 ? */
          printf("\n\nLe maximum est %ld.", y);
     else
          printf("\n\nLes deux nombres sont ‚gaux.");
  }
