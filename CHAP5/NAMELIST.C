/***      NAMELIST lit jusqu'… dix noms et les r‚affiche    ***/

#include <stdio.h>                 /* pour printf, puts, gets */

main()
  {
    char names [10][20];
    int i = 0;                        /* Variable de contr“le */

    printf("\033[2J");
    printf("Le programme lit jusqu'… dix noms, les range\n"
    "dans une liste puis les affiche. Fin par \"#\".\n");

    do                                    /* boucle de saisie */
      {
        printf("\nNom : ");
        gets(names[i++]);              /* incr‚mentation de i */
      }
    while (i < 10 && names[i-1][0] != '#');

    printf("\033[2J");        /* ‚cran propre avant affichage */
    printf("La liste contient les noms suivants :\n\n");
    i = 0;            /* r‚initialisation de i pour affichage */
    while(i < 10 && names[i][0] != '#') /* boucle d'affichage */
        puts(names[i++]);
  }
