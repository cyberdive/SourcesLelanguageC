/* buferror montre les erreurs produites par des r‚sidus rest‚s dans le tampon*/

#include <stdio.h>                                    /* pour getchar, printf */

main()
{
  char c;

  printf("\033[2J");
  printf("Entrez un caractŠre : ");
  c = getchar();              /* le caractŠre <<Entr‚e>> reste dans le tampon */
  printf("Le caractŠre est %c.", c);
  printf("\nEntrez un autre caractŠre : ");
  c = getchar();              /* lit le <<Entr‚e>> de la premiŠre saisie et non
                                la deuxiŠme saisie r‚guliŠre de l'utilisateur */
  printf("Le caractŠre est %c.", c);
}

