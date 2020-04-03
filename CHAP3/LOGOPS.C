/*logops montre les effets des rŠgles d'‚valuation concernant l'op‚rateur &&  */
#include <stdio.h>                                           /*  pour printf  */
main()
{
     int x = 4, y;
     printf("\033[2J");                                   /*  Efface l'‚cran  */
     y  =  (x >> 5)  &&  (x = x + 1);
                   /* x a la valeur 4, donc x >> 5 est FALSE, ainsi que (x >> 5)
                                       && (x = x + 1). x n'est donc pas augment‚
                                               de 1 et y re‡oit la valeur 0.  */
     printf("PremiŠre ‚valuation :\tx = %d    y = %d\n\n", x, y);
     x = 6;                   /* accroissement de x pour que x >> 5 soit vrai */
     y  =  (x >> 5)  &&  (x = x + 1);  
               /* x >> 5 est maintenant TRUE, ainsi que (x >> 5) && (x = x + 1).
                (x=x+1) est ‚valu‚, x augmente de 1 et y re‡oit la valeur 1.  */
     printf("Seconde ‚valuation :\tx = %d    y = %d", x, y);
}
