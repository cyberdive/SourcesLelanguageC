/* IOLOOP2 lit, via une boucle, un nombre quelconque de caract�res et les
   affiche.
   La fin de la saisie est provoqu�e par une certaine combinaison de touches
   g�n�rant le caract�re EOF. IOLOOP2 est �crit pour des machines DOS et invite
   donc l'utilisateur � taper <<CTRL>>+<<Z>> pour mettre fin � la saisie. Sur
              d'autres syst�mes, il faut adapter le programme en cons�quence. */

#include <stdio.h>                            /* pour getchar, putchar et EOF */

main()
{
  int input;
  printf("Entrez un caract�re. Fin de saisie par <<CTRL>>+<<Z>>.\n");

  while ((input = getchar()) != EOF)

/* lecture d'un caract�re et comparaison avec EOF :
                  l'ent�te de boucle comporte :    initialisation
                                                   �valuation de la condition
                                                   r�initialisation           */
                                                  
   putchar(input);                                  /* affichage du caract�re */
}

