/* lowerlet lit une majuscule saisie au clavier et la convertit en minuscule  */
#include <stdio.h>                                  /*  pour printf, getchar  */
main()
{
     char c;                                         /*  pour le caract�re lu */
     printf("\033[2J");                                    /*  efface l'�cran */
     printf(     "Ce programme transforme une majuscule en une minuscule.\n");
     printf("tapez une majuscule : ");
     c = getchar();            /* lecture de la majuscule dans la variable c  */
     printf("\n\nMajuscule : %c\tMinuscule : %c", c, c+'a'-'A');
}
