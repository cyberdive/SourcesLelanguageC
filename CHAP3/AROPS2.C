/*  arops2 calcule et affiche des expressions arithm‚tiques bas‚es sur des
					 constantes  et sur des variables  */
#include <stdio.h>                                        /*  pour printf  */
main()
{
     int x = 4, y = 2;     /*  d‚finition et initialisation des op‚randes  */
					  /*  variables comme op‚randes :  */
     printf("Somme = %d\tDiff‚rence = %d\tProduit = %d\tQuotient =
						%d\n\n", x+y, x-y, x*y, x/y);
			     /* variables et constantes comme op‚randes :  */

     printf("Somme = %d\tDiff‚rence = %d\tProduit = %d\tQuotient =
						    %d", x+2, 4-y, x*2, 4/y);
}
