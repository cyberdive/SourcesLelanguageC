/* noinit montre des erreurs de programme produites par des variables
                                                             non initialis‚es */

#include <stdio.h>                                      /* pour printf, scanf */

main()
{
  long n;
  int cnt;                                 /* compte les nombres pairs saisis */

  printf("\033[2J");
  printf("Le programme avale les entiers pairs,\n");
  printf("jusqu'… ce que vous tapiez un nombre impair.\n");
  printf("Vous saurez alors combien de nombres pairs vous avez saisis.");

  while (!(n % 2))                      /* tant qu'un nombre pair a ‚t‚ entr‚ */
   {
    printf("\n\nUn nombre pair SVP : ");
    scanf("%ld", &n);
    cnt++;
   }

  printf("\n\nVous avez entr‚ %d nombres pairs :", cnt-1);
}

