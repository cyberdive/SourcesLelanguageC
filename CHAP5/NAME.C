/*** NAME lit une cha�ne caract�re par caract�re, ***/
/*** la range dans un tableau et l'affiche        ***/


#include <stdio.h>                           /* pour printf, getchar, putchar */

main()
  {
     char name [40];
     int i = 0;
     printf("\033[2J");
     printf("Votre nom : ");
     while ((name[i] = getchar()) != '\n')        /* saisie en mode caract�re */
           i++;
  
     name[i] = '\0';                /* accroche le caract�re nul � la cha�ne. */
                                         /* Le caract�re '\n' est donc �cras� */
  
     printf("\nVotre nom est ");
     i = 0;                                                /* r�initialise i  */
     while (name[i] != '\0')                              /* affichage du nom */
           {
              putchar(name[i]);
              i++;
           }
  }
