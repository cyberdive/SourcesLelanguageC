/*** NAME lit une chaåne caractäre par caractäre, ***/
/*** la range dans un tableau et l'affiche        ***/


#include <stdio.h>                           /* pour printf, getchar, putchar */

main()
  {
     char name [40];
     int i = 0;
     printf("\033[2J");
     printf("Votre nom : ");
     while ((name[i] = getchar()) != '\n')        /* saisie en mode caractäre */
           i++;
  
     name[i] = '\0';                /* accroche le caractäre nul Ö la chaåne. */
                                         /* Le caractäre '\n' est donc ÇcrasÇ */
  
     printf("\nVotre nom est ");
     i = 0;                                                /* rÇinitialise i  */
     while (name[i] != '\0')                              /* affichage du nom */
           {
              putchar(name[i]);
              i++;
           }
  }
