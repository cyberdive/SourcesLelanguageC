/* forever2 montre l'utilisation d'une boucle infinie. On affiche ind‚finiment
   ici une phrase dont on remplace les caractŠres, un … un et de la droite vers
   la gauche, par un autre caractŠre. Pour des questions de pr‚sentation, le
   d‚roulement est ralenti par une boucle de temporisation (avec instruction
                                                                       vide). */

#include <stdio.h>                                             /* pour printf */

main()
{
  int i;                                                /* variable de boucle */
  float f;            /* variable de contr"le pour la boucle de temporisation */

  printf("\033[2J\n\n\n\n\n");
  for(;;)                                                   /* boucle infinie */
   {
    for (i = 1; i < 31; i++)                             /* indenter le texte */
    printf(" ");
    printf("C is FUN ");              /* notez l'espace … la fin de C is FUN. */
    for (f = 1.0; f < 2500.0; f++)       /* Pause via boucle de temporisation */
                                                     /* avec instruction vide */
    for (i = 1; i < 9; i++)             /* pour chaque caractŠre de C is FUN. */
        {
     printf("\b\b");                                   /* deux pas en arriŠre */
     printf("_");                   /* affichage du caractŠre de remplacement */
     for (f = 1.0; f < 2500.0; f++)      /* Pause via boucle de temporisation */
         ;                                           /* avec instruction vide */
    }
  printf("\r");             /* Pour la prochaine r‚p‚tition, on place le curseur
                                                   au d‚but de la mˆme ligne. */
 }                                                   /* fin du " for " infini */
}                                                              /* fin du main */

