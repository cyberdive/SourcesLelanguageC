/*       SCOPE3 montre une utilisation erron‚e de variables locales          */
#include <stdio.h>
int global = 1000;        /* Variable globale : port‚e = tout le fichier     */

main()

/*     d‚but bloc externe de main     */

{
     int local1 = 2000;          /*     Variable locale  : port‚e = main     */
     printf("Bloc externe main : La valeur de global est %d\n", global);
     printf("Bloc externe main : La valeur de local1 est %d\n", local1);
     printf("Bloc externe main : La valeur de local2 est %d\n", local2);

/* erreur */

     printf("Bloc externe main : La valeur de local3 est %d\n\n", local3);

/* erreur */

     { /* d‚but bloc interne de main     */
     int local2 = 3000;              /* Variable locale  : port‚e = bloc     */
     printf("Bloc interne main : La valeur de global est %d\n", global);
     printf("Bloc interne main : La valeur de local1 est %d\n", local1);
     printf("Bloc interne main : La valeur de local2 est %d\n", local2);
     printf("Bloc interne main : La valeur de local3 est %d\n", local3);

/* erreur */

     } /*     fin bloc interne main     */
     fonc();                            /*     appel de la fonction fonc     */

/* fin bloc externe main     */

}

fonc()       /* le programme contient une autre fonction que main : fonc     */
{
     int local3 = 4000;           /*     Variable locale : port‚e = fonc     */
     printf("\n\nfonc : La valeur de global est %d", global);
     printf("\nfonc : La valeur de local1 est %d", local1);        /* erreur */
     printf("\nfonc : La valeur de local2 est %d", local2);        /* erreur */
     printf("\nfonc : La valeur de local3 est %d", local3);
}

