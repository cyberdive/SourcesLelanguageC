/* numeater lit au moyen d'un while des nombres pairs et s'arrˆte dŠs qu'un
   nombre impair a ‚t‚ saisi. Ensuite, il affiche le nombre d'entiers pairs
                                                                     saisis.  */

#include <stdio.h>                                      /* pour printf, scanf */

main()
{
  long n = 2;   /* initialise avec nb. pair afin que la condition de boucle soit
                                                                         TRUE */
  int cnt = 0;  /* pour compter les nombres pairs saisis : initialisation … 0 */

  printf("\033[2J");
  printf("Le programme avale les entiers pairs,\n");
  printf("jusqu'… ce que vous tapiez un nombre impair.\n");
  printf("Vous saurez alors combien de nombres pairs vous avez saisis.");
  while (!(n % 2))                      /* tant qu'un nombre pair a ‚t‚ entr‚ */
    {
     printf("\n\nUn nombre pair SVP : ");
     scanf("%ld", &n);
     cnt++;                          /* comptage du nombre de valeurs saisies */
    }
   printf("\n\nVous avez entr‚ %d nombres pairs :", cnt-1);
}

