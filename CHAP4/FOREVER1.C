/* forever1 montre l'utilisation d'une boucle infinie. On affiche ind�finiment
   ici une phrase dont on remplace les caract�res, un � un et de la droite vers
                                           la gauche, par un autre caract�re. */

#include <stdio.h>                                             /* pour printf */

main()
{
  int i;                                                /* variable de boucle */
  printf("\033[2J\n\n\n\n\n");
  for(;;)                                                   /* boucle infinie */
    {
     for (i = 1; i < 31; i++)                            /* indenter le texte */
     printf(" ");
     printf("C is FUN ");             /* notez l'espace _ la fin de C is FUN. */
     for (i = 1; i < 9; i++)            /* pour chaque caract�re de C is FUN. */
         {
      printf("\b\b");                                  /* deux pas en arri�re */
      printf("_");                  /* affichage du caract�re de remplacement */
         }
     printf("\r");          /* Pour la prochaine r�p�tition, on place le curseur
                                                   au d�but de la m�me ligne. */
    }                                                /* fin du " for " infini */
}                                                                /* fin du main */

