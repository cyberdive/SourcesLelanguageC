/* forever1 montre l'utilisation d'une boucle infinie. On affiche indÇfiniment
   ici une phrase dont on remplace les caractäres, un Ö un et de la droite vers
                                           la gauche, par un autre caractäre. */

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
     for (i = 1; i < 9; i++)            /* pour chaque caractäre de C is FUN. */
         {
      printf("\b\b");                                  /* deux pas en arriäre */
      printf("_");                  /* affichage du caractäre de remplacement */
         }
     printf("\r");          /* Pour la prochaine rÇpÇtition, on place le curseur
                                                   au dÇbut de la màme ligne. */
    }                                                /* fin du " for " infini */
}                                                                /* fin du main */

