/* buferror montre les erreurs produites par des r�sidus rest�s dans le tampon*/

#include <stdio.h>                                    /* pour getchar, printf */

main()
{
  char c;

  printf("\033[2J");
  printf("Entrez un caract�re : ");
  c = getchar();              /* le caract�re <<Entr�e>> reste dans le tampon */
  printf("Le caract�re est %c.", c);
  printf("\nEntrez un autre caract�re : ");
  c = getchar();              /* lit le <<Entr�e>> de la premi�re saisie et non
                                la deuxi�me saisie r�guli�re de l'utilisateur */
  printf("Le caract�re est %c.", c);
}

