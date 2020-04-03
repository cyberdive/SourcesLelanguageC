/*   EXTERN2 accŠde … une variable de classe extern avant qu'elle ne soit
     d‚finie dans le programme. Pour cela, une d‚claration de la variable est
				     n‚cessaire avant son utilisation.     */
#include <stdio.h>
main()
{
     {
     extern int e;    /* d‚claration de la variable extern e. La variable est
		  ensuite utilisable dans le bloc int‚rieur de 'main'.     */
     e = 1;
     printf("Bloc int‚rieur de main : valeur de e (extern): %d", e);
     fonc();                                      /* appel de fonction     */
     }
}
int e;               /* d‚finition de la variable globale e de classe extern.
			     Se produit aprŠs utilisation dans 'main'.     */
fonc()              /* aucune d‚claration extern de e n‚cessaire pour fonc */
{                      /* car fonc se trouve aprŠs la d‚finition de e.     */
     printf("\nfonc : valeur de e (extern): %d", e);
}

