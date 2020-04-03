/*** TYPECHEK re‡oit des valeurs saisies de diff‚rents types (entiers,      ***/
/*** r‚els) et les range selon … leur type … l'aide d'une variable union.   ***/


#include <stdio.h>                                             /* pour printf */
#include <string.h>                                            /* pour strcmp */
#include <stdlib.h>                                        /* pour atol, atof */
#include <conio.h>                                              /* pour getch */

main()
  {
     char albuf[40];                                 /* buffer alphanum‚rique */
     int i;                                           /* Variable de contr“le */
     int decpoint;                              /* Flag pour le point d‚cimal */
     union values                  /* pour m‚moriser des r‚els ou des entiers */
       {
         long l;
         double d;
       } x;
     do
       {
         printf("\033[2J");
         printf("Saisie d'entiers ( 9 chiffres au plus) ou de r‚els.\n"
                "Fin par \'quit\': ");
         gets(albuf);              /* saisie d'un nombre sous forme de chaŒne */
         i = 0;
         decpoint = 0;                              /* initialisation du flag */
         if (strcmp(albuf, "quit") != 0)
                                   /* si premiŠre saisie diff‚rente de 'quit' */
            {
                                           /* on recherche le point d‚cimal : */

              while (albuf[i] != '\0'  &&  decpoint != 1)
                {
                   if (albuf[i] == '.')
                       decpoint = 1;
                       i++;
                }
              if (decpoint)                           /* point d‚cimal trouv‚ */
                {
                   x.d = atof(albuf);
                                  /* conversion en valeur … virgule flottante */
                   printf("\n\nNombre r‚el %f m‚moris‚ comme valeur … virgule"
                          " flottante.", x.d);
                   printf("\n\n<Entr‚e> pour continuer.");
                   getch();
                }
              else
                {
                   x.l = atol(albuf);        /* conversion en valeur  entiŠre */
                   printf("\n\nNombre entier %ld m‚moris‚ comme "
                          "valeur entiŠre.", x.l);
                   printf("\n\n<Entr‚e> pour continuer.");
                   getch();
                }
            }                                                /* fin if strcmp */
       } while (strcmp(albuf, "quit") != 0);
  }
