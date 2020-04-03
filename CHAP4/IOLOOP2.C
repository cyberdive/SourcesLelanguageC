/* IOLOOP2 lit, via une boucle, un nombre quelconque de caractäres et les
   affiche.
   La fin de la saisie est provoquÇe par une certaine combinaison de touches
   gÇnÇrant le caractäre EOF. IOLOOP2 est Çcrit pour des machines DOS et invite
   donc l'utilisateur Ö taper <<CTRL>>+<<Z>> pour mettre fin Ö la saisie. Sur
              d'autres systämes, il faut adapter le programme en consÇquence. */

#include <stdio.h>                            /* pour getchar, putchar et EOF */

main()
{
  int input;
  printf("Entrez un caractäre. Fin de saisie par <<CTRL>>+<<Z>>.\n");

  while ((input = getchar()) != EOF)

/* lecture d'un caractäre et comparaison avec EOF :
                  l'entàte de boucle comporte :    initialisation
                                                   Çvaluation de la condition
                                                   rÇinitialisation           */
                                                  
   putchar(input);                                  /* affichage du caractäre */
}

