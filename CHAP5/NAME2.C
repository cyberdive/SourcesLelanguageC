/***   NAME2 range une chaåne dans un tableau   ***/
/***   via "scanf" et l'affiche avec "printf"   ***/

#include <stdio.h>          /* pour printf, scanf */

main()
  {
     char name [40];
     
     printf("\033[2J");
     printf("Votre nom : ");
     scanf("%s", name);
     printf("\nVotre nom est %s.", name);
  }
