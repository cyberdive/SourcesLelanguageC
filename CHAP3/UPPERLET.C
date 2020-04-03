/* upperlet lit une minuscule saisie au clavier et la convertit en majuscule  */
#include <stdio.h>                                  /*  pour printf, getchar  */
main()
{
     char c;                                         /*  pour le caractäre lu */
     printf("\033[2J");                                    /*  efface l'Çcran */
      printf(     "Ce programme transforme une minuscule en une majuscule.\n");
     printf("tapez une minuscule : ");
     c = getchar();            /* lecture de la minuscule dans la variable c  */
     printf("\n\nMinuscule : %c\tMajuscule : %c", c, c-'a'+'A');
}
