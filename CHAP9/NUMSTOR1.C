/*** NUMSTOR1 range jusqu'… 50 nombres dans un tableau. Les ‚l‚ments d'une  ***/
/*** portion contigu‰ quelconque du tableau peuvent ensuite ˆtre additionn‚s***/
/*** et affich‚s. La validit‚ des nombres saisis est contr“l‚e.             ***/

#include <stdio.h>                                            /* printf, gets */
#include <ctype.h>                                                 /* isdigit */
#include <stdlib.h>                                                   /* atof */
#include <conio.h>                                           /* getche, getch */
#include <string.h>                                                 /* strcmp */
#define YES    'o'

main()
  {

/***        variables     ***/

   char buffer[81];                        /* buffer de saisie alphanum‚rique */
   double num[50];                          /* m‚morise les nombres convertis */
   char rep1, rep2;                                  /* variables de contr“le */
   int i;                                             /* variable de contr“le */
   int n;                                                         /* compteur */
   int ok;                                      /* Flag pour erreur de saisie */
   int dpoint;                                     /* Flag pour point d‚cimal */
   int start;                                        /* d‚but du sous-tableau */
   int end;                                            /* fin du sous-tableau */
   double *s;                       /* pointeur vers le d‚but du sous-tableau */
   double *e;                         /* pointeur vers la fin du sous-tableau */
   double sum;                              /* Somme des nombres s‚lectionn‚s */
   printf("\033[2J");
   printf("Le programme additionne jusqu'… 50 nombres \n");
   printf("et affiche le total, ces nombres ‚tant pris \n");
   printf("dans un groupe quelconque contigu, pris parmi\n");
   printf("des valeurs saisies (n … (n+k)).\n");

/***  saisie des valeurs  ***/
    n = 0;
    do
      {
        do                                           /* contr“le de la saisie */
           {
             ok = 1;
             printf("\n\n%d. Nombre (Fin par \"q\"): ", n+1);
             gets(buffer);                           /* saisie alphanum‚rique */
             if (strcmp(".", buffer) == 0)                   /* point d‚cimal */
               {
                 printf("\nNombre invalide.");
                 ok = 0;
               }
             else                                     /* contr“le de validit‚ */
               {
                 i = 0;
                 dpoint = 0;
                 while (buffer[i] != '\0'  &&  ok)
                    {
                       if (buffer[i] == '.'  &&  dpoint == 0)
                           dpoint = 1;               /* un seul point d‚cimal */

                       else if (!isdigit(buffer[i])  &&  strcmp("q", buffer))
                                                   /* si aucun chiffre et pas */
                                            /* uniquement le caractŠre de fin */
                           {
                              printf("\nNombre invalide.");
                              ok = 0;
                           }
                       i++;
                    }
             }                                                    /* fin else */
           } while (!ok);                             /* fin do while interne */
        if (buffer[0] != 'q')                                  /* si pas fini */
           {
             num[n] = atof(buffer);         /* conversion nb. + m‚morisation */
             n++;
           }
      } while (buffer[0] != 'q'  &&  n < 50);


/***        affichage     ***/

    if (n > 0)                                  /* au moins une valeur saisie */
      {
        if (n > 49)                          /* interruption sans car. de fin */
           printf("\n\nCapacit‚ ‚puis‚e. Pas d'autre saisie possible.");
           printf("\n\n%d nombres ont ‚t‚ saisis.\n", n);
           printf("Afficher le tableau ? (o/n)");
           if ((rep1 = getche()) == YES)
               {
                 printf("\n");
                 for (i = 0; i < n; i++)
                     {
                        printf("\nValeur no %d :\t%f", i+1, num[i]);
                        if (i != n-1  && ((i+1)%18) == 0)
                           {
                              printf("\n\n<Entr‚e> pour page suivante");
                              getch();
                              printf("\033[2J");
                           }
                     }
               }
            printf("\n\n");
            printf("Totaliser le tableau ? (o/n)");
         if ((rep2 = getche()) == YES)
            {
               printf("\n\nDu nombre no : ");
               scanf("%d", &start);
               while (start < 0 || start > n)
                                             /* mauvais d‚but de sous-tableau */
                 {
                    printf("\nD‚but de zone invalide.");
                    printf("\nDu nombre no : ");
                    scanf("%d", &start);
                 }
               printf("\n\nAu nombre no : ");
               scanf("%d", &end);
               while (end < start || end > n)
                                              /* mauvaise fin de sous-tableau */
                 {
                    printf("\nFin de zone invalide.");
                    printf("\nAu nombre no : ");
                    scanf("%d", &end);
                 }
               s = &num[start-1];          /* initialiser pointeur vers d‚but */
               e = &num[end-1];                             /* et fin de zone */
               sum = 0.0;
               while (s <= e)             /* tant que adr. d‚part <= adr. Fin */
                    sum += *s++;            /* addition avec ptr. d‚r‚f‚renc‚ */
                    printf("\n\nLa somme des valeurs %d … %d est de : %f",
                            start, end, sum);
            }                                                  /* fin if rep2 */
      }                                                       /* fin if n > 0 */
  }                                                               /* fin main */
