/***  SEP.C divise un entier positif en groupes de trois chiffres … partir  ***/
/***  de la droite. L'utilisateur peut choisir le s‚parateur entre les      ***/
/***  groupes. Pour manipuler les tableaux utilis‚s dans le programme,      ***/
/***  on passe par des pointeurs.                                           ***/

/***      pr‚processeur     ***/

#include <stdio.h>                             /* printf, putchar, puts, gets */
#include <conio.h>                                                  /* getche */
#include <ctype.h>                                                 /* isdigit */
#include <stdlib.h>                                                 /* atoi   */
#include <string.h>                                         /* strcpy, strlen */
#define BOOL int

/******************************/

main()
  {
    /*** variables ***/
    char buffer [128];                               /* nombre alphanum‚rique */
    char clearbuf [128];          /* nombre alphanum‚rique sans z‚ros de tˆte */
    char output [172];       /* nb. en groupes de 3 chiffres avec s‚parateurs */
    char    * pb = buffer,                     /* pointeurs vers les tableaux */
    *pc = clearbuf,                              /* buffer, clearbuf, output, */
    *po = output;                   /* initialis‚s avec les adresses de d‚but */
    int symbol;                                                 /* s‚parateur */
    int count;                                        /* compteur de chiffres */
    BOOL ok;                             /* flag pour saisie correcte, 0 ou 1 */
    int i, k;                                        /* variables de contr“le */
/******************************/

    printf("\033[2J");
    printf("Le programme s‚pare un nombre entier positif d‚cimal "
           "… partir de la droite\n en groupes de trois chiffres."
           " Le s‚parateur est un caractŠre\n au choix (pas un chiffre).");

/***  saisie du s‚parateur  ***/
    do                                    /* saisie (contr“l‚e) du s‚parateur */
       {
          printf("\n\nS‚parateur : ");
          symbol = getche();
          if (symbol < 32)
             printf("\nPas de caractŠre de contr“le comme s‚parateur !");
             if (isdigit(symbol))
                printf("\nPas de chiffre comme s‚parateur ! ");
       } while (symbol < 32  ||  isdigit(symbol));

/***    saisie du nombre    ***/
    do                                        /* saisie (contr“l‚e) du nombre */
       {
          ok = 1;
          printf("\n\nVotre nombre (pas plus de 50 chiffres) : ");
          gets(buffer);                    /* nom de tableau comme pointeur : */
                                     /* gets re‡oit l'adr. du premier ‚l‚ment */
          count = 0;
          while (*(buffer + count) && ok)    /* buffer[count] != 0 et ok != 0 */
              {
                if (!isdigit(*(buffer + count)))         /* si pas de chiffre */
                   {
                      printf("\nPas d'entier positif !");
                      ok = 0;
                   }
                count++;
              }
       } while (!ok);

/***  suppression des z‚ros de tˆte    ***/
    if (count > 1 && atoi(buffer))         /* si plus d'un seul chiffre et si */
       {                                    /* on n'a pas saisi que des z‚ros */
                                     /* supprimer les z‚ros de tˆte superflus */
                              
          while (* pb == '0')                     /* sauter les z‚ros de tˆte */
               pb++;
          while (* pc++ == * pb++)               /* nombre sans z‚ros de tˆte */
               ;                                       /* rang‚ dans clearbuf */

          strcpy(buffer, clearbuf);              /* reporter nombre d‚pouill‚ */
                                                               /* dans buffer */

       }

/***  afficher le nombre avec les s‚parateurs    ***/
    if ((count = strlen(buffer)) > 3)     /* pas de s‚parateur si <4 chiffres */

       {
          for (i = count-1, k = 0, pb = buffer; i >= 0; i--, k++)
            {
               po[k] = pb[i];               /* accŠs … buffer et … output via */
                                            /* des pointeurs index‚s. A cause */
                                            /* des s‚parateurs, le nombre est */
                                              /* rang‚ … l'envers dans output */

               if (((count - i) % 3) == 0  &&  i != 0)
                                                     /* tous les 3 caractŠres */
                    po[++k] = symbol;                        /* un s‚parateur */
            }
          po[k] = '\0';                   /* terminer output avec un car. nul */
          for (i = k-1; i >= 0; i--)              /* et l'afficher en partant */
             putchar(*(output + i));                             /* de la fin */
       }
    else
       puts(buffer);                    /* aucune pr‚paration si < 4 chiffres */
  }                                                             /*   fin main */
