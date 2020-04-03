/*    SCOPE5A d‚finit des variables de mˆme nom avec des domaines de validit‚ qui
							      se recoupent */
#include <stdio.h>
int x = 1000;                                  /*     Variable globale     */
main()
{
     int x = 2000;                              /*     Variable locale     */
     printf("Bloc externe main: la valeur de x est %d", x);

     {
     int x = 3000;                              /*     Variable locale     */
     printf("\nBloc interne de main : la valeur de x est %d", x);
     }
     fonc();                                  /*     appel de fonction     */
}
fonc()
{
     int x = 4000;                              /*     Variable locale     */
     printf("\nfonc : la valeur de x est %d", x);
}

