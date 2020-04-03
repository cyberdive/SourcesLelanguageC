/* divmod lit deux entiers, les divise et affiche le r‚sultat ainsi que le reste
                                                               de la division */
#include <stdio.h>                                    /*  pour printf, scanf  */
main()
{
     long x, y;                                 /*  en cas de valeurs ‚lev‚es */
     printf("\033[2J");                                    /*  efface l'‚cran */
     printf("Ce programme divise des entiers.\n");
     printf("Entrez deux nombres entiers.\n");
                                            /* division par 0 interdite, d'o— */
     printf("Le second doit ˆtre non nul : ");
     scanf("%ld %ld", &x, &y);                          /* saisie des valeurs */
     printf("\n\n%ld divis‚ par %ld donne %ld reste %ld", x, y, x/y, x%y);
}
