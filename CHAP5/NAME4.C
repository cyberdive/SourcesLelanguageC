/***  NAME4 range une chaåne dans un tableau ***/
/***  via "gets" et l'affiche avec "puts"    ***/

#include <stdio.h>  /* pour printf, gets, puts */

main()
  {
     char name [40];
     
     puts("\033[2J");
     printf("Votre nom : ");
     gets(name);        /* saisie de la string */
     printf("\nVotre nom est ");
     puts(name);     /* affichage de la string */
  }
