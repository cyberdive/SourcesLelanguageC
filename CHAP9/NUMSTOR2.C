/***  NUMSTOR2 range un nombre quelconque de valeurs dans un tableau        ***/
/***  dynamique. Les ‚l‚ments d'une portion contigu‰ quelconque du tableau  ***/
/***  peuvent ensuite ˆtre additionn‚s et affich‚s.                         ***/
/***  La validit‚ des nombres saisis est contr“l‚e.                         ***/

#include <stdio.h>                                            /* printf, gets */
#include <ctype.h>                                                 /* isdigit */
#include <stdlib.h>                                             /* atof, exit */
#include <conio.h>                                           /* getche, getch */
#include <string.h>                                                 /* strcmp */
#define YES    'o'

main()
  {
    char buffer[81];                       /* buffer de saisie alphanum‚rique */
    double *darray;               /* pointeur vers d‚but du tableau dynamique */
    double *backup;           /* si darray re‡oit le pointeur nul par realloc */
    char rep1, rep2;                                 /* variables de contr“le */
    int i;                                            /* variable de contr“le */
    int n;                                                        /* compteur */
    int ok;                                     /* Flag pour erreur de saisie */
    int dpoint;                                    /* Flag pour point d‚cimal */
    int start;                                       /* d‚but du sous-tableau */
    int end;                                           /* fin du sous-tableau */
    double *s;                      /* pointeur vers le d‚but du sous-tableau */
    double *e;                        /* pointeur vers la fin du sous-tableau */
    double sum;                             /* Somme des nombres s‚lectionn‚s */

    /***  allocation de m‚moire pour le premier ‚l‚ment du tableau  ***/

    if ((darray = (double *) malloc(sizeof(double))) == NULL)
      {
        printf("\n\nmalloc : allocation du bloc impossible !");
        exit(1);                                       /* sortie du programme */
      }

    /*** allocation r‚ussie ***/

      printf("\033[2J");
      printf("Le programme additionne un nombre quelconque de valeurs\n");
      printf("et affiche le total, ces nombres ‚tant pris dans un\n")
      printf("groupe quelconque contigu,\n");
      printf("pris parmi des valeurs saisies (n … (n+k)).\n");

    /***  saisie des valeurs  *************/
      
      n = 0;                                /* initialise compteur d'‚l‚ments */
      do                                                  /* boucle de saisie */
        {
          do                                         /* contr“le de la saisie */
             {
               ok = 1;
               printf("\n\n%d. Nombre (Fin par \"q\"): ", n+1);
               gets(buffer);                         /* saisie alphanum‚rique */
               if (strcmp(".", buffer) == 0)      /* point d‚cimal seul saisi */
                  {
                    printf("\nNombre invalide.");
                    ok = 0;
                  }
               else                                   /* contr“le de validit‚ */
                  {
                    i = 0;
                    dpoint = 0;
                    while (buffer[i] != '\0'  &&  ok)
                       {
                          if (buffer[i] == '.'  &&  dpoint == 0)
                              dpoint = 1;            /* un seul point d‚cimal */
                          else if (!isdigit(buffer[i])  &&  strcmp("q", buffer))
                                                   /* si aucun chiffre et pas */
                                            /* uniquement le caractŠre de fin */
                             {
                                printf("\nNombre invalide.");
                                ok = 0;
                             }
                          i++;
                       }
                  }                                               /* fin else */
             } while (!ok);                         /* fin contr“le de saisie */
 
          if (buffer[0] != 'q')                                /* si pas fini */
             {
                darray[n++] = atof(buffer);  /* conversion nb. + m‚morisation */
                backup = darray;         /* m‚morise adr. bloc pour affichage */
                if((darray = (double *) realloc(darray, (n+1) *
                   sizeof(double))) == NULL)        /* agrandissement du bloc */
                  {
                    printf("\n\nrealloc : Agrandissement du bloc impossible !");
                    break;               /* quitte la boucle externe do while */
                  }
             }                                               /* fin if buffer */
        } while (buffer[0] != 'q');             /* fin de la boucle de saisie */
 
/***  affichage  *********************/
      if (n > 0)                                /* au moins une valeur saisie */
        {
          if (darray == NULL)                          /* bloc non modifiable */
             darray = backup;       /* pour afficher les valeurs d‚j… saisies */
          printf("\n\n%d nombres ont ‚t‚ saisis.\n", n);
          printf("Afficher le tableau ? (o/n)");
          if ((rep1 = getche()) == YES)
             {
               printf("\n");
               for (i = 0; i < n; i++)
                   {
                      printf("\nValeur no %d :\t%f", i+1, darray[i]);
                      if (i != n-1  && ((i+1)%18) == 0)
                         {                             /* 18 valeurs par page */
                            printf("\n\n<Entr‚e> pour page suivante");
                            getch();
                            printf("\033[2J");
                         }
                   }                                               /* fin for */
             }                                                 /* fin if rep1 */
          printf("\n\n");
          printf("Totaliser le tableau ? (o/n)");
          if ((rep2 = getche()) == YES)
             {
               printf("\n\nDu nombre no : ");
               scanf("%d", &start);
               while (start < 0 || start > n)/* mauvais d‚but de sous-tableau */
                   {
                     printf("\nD‚but de zone invalide.");
                     printf("\nDu nombre no : ");
                     scanf("%d", &start);
                   }
               printf("\n\nAu nombre no : ");
               scanf("%d", &end);
               while (end < start || end > n) /* mauvaise fin de sous-tableau */
                   {
                     printf("\nFin de zone invalide.");
                     printf("\nAu nombre no : ");
                     scanf("%d", &end);
                   }
               s = &darray[start-1];    /* initialiser pointeur vers d‚but et */
               e = &darray[end-1];                     /* fin de sous-tableau */
               sum = 0.0;
               while (s <= e)             /* tant que adr. d‚part <= adr. Fin */
               sum += *s++;                 /* addition avec ptr. d‚r‚f‚renc‚ */
               printf("\n\nLa somme des valeurs %d … %d est de : %f", 
                           start, end, sum);
             }                                                /* fin if rep2 */
        }                                                    /* fin if n > 0 */
    if(darray != NULL)
        free(darray);                                  /* lib‚ration m‚moire */
  }    /* fin main */

