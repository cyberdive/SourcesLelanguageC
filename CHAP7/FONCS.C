#include <stdio.h>                                      /*   pour printf   */


fonc1()
{
				 /* La commande suivante provoque une erreur.
				 La variable e n'est pas connue dans fonc1 */
  printf("\nfonc1:\tLa valeur de e est %d", e);
}

fonc2()
{
  extern int e;                       /* D‚claration locale de la variable e.
			       La variable n'est disponible que dans fonc2 */
  printf("\fonc2:\tLa valeur de e est %d", e);
}

