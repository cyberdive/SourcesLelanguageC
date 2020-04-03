/* IOLOOP1 lit, via une boucle, un nombre quelconque de caractŠres et les
    affiche. 
    La fin de la saisie est provoqu‚e par une certaine combinaison de touches
    g‚n‚rant le caractŠre EOF. IOLOOP1 est ‚crit pour des machines DOS et invite
    donc l'utilisateur … taper <<CTRL>>+<<Z>> pour mettre fin … la saisie. Sur
              d'autres systŠmes, il faut adapter le programme en cons‚quence. */

#include <stdio.h>                              /* pour getchar, putchar et EOF */

main()
{
  int input;
  printf("Entrez un caractŠre. Fin de saisie par <<CTRL>>+<<Z>>.\n");

  input = getchar();  /* lit premier caractŠre : initialise la variable input */

  while (input != EOF)                /* comparaison du caractŠre lu avec EOF */
  {
   putchar(input);                                    /* affiche le caractŠre */
   input = getchar();        /* lit le caractŠre suivant : r‚initialise input */
  }
}

