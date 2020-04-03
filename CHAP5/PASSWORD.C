/***  PASSWORD lit un mot de passe sans l'afficher … l'‚cran et v‚rifie,    ***/
/***  via la fonction "strlen", si on n'a pas d‚pass‚ une certaine longueur ***/
/***  maximale pr‚d‚finie                                                   ***/

#include <stdio.h>                                             /* pour printf */
#include <conio.h>                                      /* pour getche, getch */
#include <string.h>                                    /* pour strlen, strcpy */

main()
  {
    char buffer[81];                                 /* pour ranger la saisie */
    char pword[9];                                            /* mot de passe */
    char reply, new, i;                              /* Variables de contr“le */

    do
      {
         printf("\033[2J\n\n\n");
         printf("Entrez un mot de passe (8 caractŠres au plus) : ");

         i = 0;
         while (buffer[i] = getch() != '\r')       /* lecture du mot de passe */
               i++;
         buffer[i] = '\0';                                  /*  caractŠre nul */

         if (strlen(buffer) > 8)                 /* si mot de passe trop long */
            {
               printf("\n\nMot de passe trop long.");
               printf("<Entr‚e> pour nouvelle saisie. Fin par <ECHAP>.");
               new = getche();
            }
         else                                         /* mot de passe correct */
            {
               strcpy(pword, buffer);               /* m‚moriser mot de passe */
               printf("\n\nMot de passe enregistr‚. Visualisation ? (o/n)");
               if ((reply = getche()) == 'o')
                   printf("\n\nVotre mot de passe est \"%s\"", pword);
                   new = 27;        /* pour finir do while, new doit recevoir */
                                                                                               ction "strlen", si on n'/* la valeur <ECHAP> (= 27) */
            }
         } while (new != 27);                     /* tant que nouvelle saisie */
  }
