/***  showmax1 calcule le maximum de deux nombres saisis par l'utilisateur  ***/

#include <stdio.h>                                           /* printf, scanf */

long lcomp(long a, long b)               /* d‚finition de la fonction 'lcomp' */

  {
     if (a > b)                                            /* a sup‚rieur … b */
         return (a);
     else if (a < b)                                       /* a inf‚rieur … b */
        return (b);
     else                                           /* les nombres sont ‚gaux */
        return (0);
  }

main()
  {
     long x, y;
     
     printf("\033[2J");
     printf("Le programme d‚termine le plus grand de deux entiers\n"
            "compris entre -2 000 000 000 et +2 000 000 000.");
            
     printf("\n\nPremier entier : ");
     scanf("%ld", &x);
   
     printf("\n\nSecond entier : ");
     scanf("%ld", &y);
   
     /* affichage du plus grand des deux nombres */
     
     if (lcomp(x, y) == x)              /* si valeur renvoy‚e par 'lcomp' = x */
         printf("\n\nLe maximum est %ld.", x);
     else if (lcomp(x,y) == y)          /* si valeur renvoy‚e par 'lcomp' = y */
         printf("\n\nLe maximum est %ld.", y);
     else
         printf("\n\nLes deux nombres sont ‚gaux.");
  }