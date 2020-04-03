/*          compvals affiche les valeurs d'expressions de comparaison         */
#include <stdio.h>                                    /*  pour printf, scanf  */
main()
{
     long x, y;                                 /*  en cas de valeurs ‚lev‚es */
     printf("\033[2J");                                    /* Efface l'‚cran  */
                                                   /*  lecture des nombres :  */
     printf("Ce programme compare les valeurs de deux nombres.\n");
     printf("Entrez deux nombres entiers :\n");
     printf("x = ");
     scanf("%ld", &x);
     printf("\ny = ");
     scanf("%ld", &y);
                                               /*  affichage des r‚sultats :  */
     printf("\n\nR‚sultat de la comparaison pour x = %ld  et y = %ld r
                                       (1 = OUI  0 = NON):\n\n", x, y);
     printf("x ‚gal … y ?\t\t\t%d\n", x==y);
     printf("x diff‚rent de y ?\t\t\t%d\n", x!=y);
     printf("x plus grand que y ?\t\t\t%d\n", x>y);
     printf("x plus grand ou ‚gal … y ?\t\t%d\n", x>=y);
     printf("x plus petit que y ?\t\t%d\n", x>y);
     printf("x plus petit ou ‚gal … y ?\t%d", x>=y);
}
