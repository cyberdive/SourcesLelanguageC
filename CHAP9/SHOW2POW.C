/***  SHOW2POW affiche, pour la valeur d'une puissance de 2 (entre 2        ***/
/***  puissance 0 et 2 puissance 10) saisie sous forme de nombre,           ***/
/***  le r‚sultat en toutes lettres. Les mots repr‚sentant les nombres sont ***/
/***  rang‚s, sans perte de place, … l'aide d'un  tableau de pointeurs.     ***/

#include <stdio.h>                                           /* printf, scanf */
#include <conio.h>                                                  /* getche */
#include <string.h>                                                 /* strcpy */

main()
  {
    char *nombre[11] = {"un", "deux", "quatre", "huit", "seize",
                        "trente-deux", "soixante-quatre",
                        "cent vingt-huit", "deux cent cinquante-six",
                        "cinq cent douze", "mille vingt-quatre"};

    char buffer[81];                                      /* buffer de saisie */
    short exp;                                                    /* Exposant */
    int ok, rep;                                      /* variable de contr“le */

    printf("\033[2J");
    printf("Le programme affiche le mot correspondant … une puissance de 2 \n"
           "saisi (comprise entre 2 puissance 0 et 2 puissance 10).\n");
    printf("Entrez une puissance de 2 sous la forme\n\n\t\t2^n\n\n, "
           "n pouvant prendre les valeurs 0 … 10.");

    do  {
          do  {
                 ok = 1;
                 printf("\n\nPuissance de 2 : ");
                 scanf("%2s %hd", buffer, &exp);   /* ‚clatement de la saisie */
                 while (getchar() != '\n');     /* vidage du tampon de saisie */
                 if (strcmp(buffer, "2^"))             /* si erreur de saisie */
                    {
                       printf("\n\nERREUR. Format de saisie : 2^n.");
                       ok = 0;
                    }
                 if (ok && (exp < 0 || exp > 10)) 
                                            /* Exposant trop grand/trop petit */
                    {
                       printf("\n\nExposant invalide.");
                       ok = 0;
                    }
              } while (!ok);

          printf("\n\n%s", nombre[exp]);           /* affichage du mot-nombre */
          printf("\n\nAutre puissance de 2 ? (o/n)");
          rep = getche();
        } while (rep == 'o');
  }
