/*  EXTERN1 accŠde … une variable de classe extern avant que celle-ci ne soit
dans le programme. Une d‚claration de la variable est donc ici n‚cessaire. */

#include <stdio.h>

main()
{
     extern int e;        /*     d‚claration de la variable extern e, d‚finie
			     seulement aprŠs main. La variable est utilisable
			       dans main … partir de cette d‚claration     */
     e = 1;
     printf("main : valeur de e (extern) : %d", e);
     fonc();                                  /*     appel de fonction     */
}
int e;       /* d‚finition de la variable globale e de classe extern. Se fait
	    ici seulement aprŠs que la  variable ait d‚j… ‚t‚ utilis‚e     */
fonc()                        /* aucune d‚claration extern de e n'est requise
		pour fonc, car fonc se trouve aprŠs la d‚finition de e     */
{
     printf("\nfonc : valeur  de e (extern) : %d", e);
}

