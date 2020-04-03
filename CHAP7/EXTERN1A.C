/*     EXTERN1A affiche une variable non initialis‚e de classe extern.     */
#include <stdio.h>
main()
{
     extern int e;             /* d‚claration de la variable externe e     */
     printf("main : valeur de e (extern) = %d", e);
     fonc();                                      /* appel de fonction     */
}
int e;                             /* d‚finition de la variable externe 'e' :
					initialisation automatique … 0     */
fonc()
{
     printf("\nfonc : valeur de e (extern) = %d", e);
}

