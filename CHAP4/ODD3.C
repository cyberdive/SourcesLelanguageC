/* Odd2 calcule la somme des N premiers nombres impairs pour N compris entre 1
   et 15000.
   L'utilisateur ici ne propose pas le nombre (N) des nombres impairs …
   additionner, mais une valeur sup‚rieure (max) jusqu'… laquelle il faut
   continuer l'addition.
   La somme correspondante et le nombre (N) des termes … additionner sont
   affich‚s. Le total " s_odd " est d‚fini comme " long " pour le cas o— les
   nombres seraient ‚lev‚s. La variable " k " (type " int ") est implicitement
                               convertie en " long " lors de la totalisation. */

#include <stdio.h>                                      /* pour printf, scanf */

main()
{
  long s_odd;                                    /* somme des nombres impairs */
  int k;                                                /* variable de boucle */
  int max;                                                   /* valeur limite */
  int n;                                        /* nombre de termes … ajouter */

  printf("\033[2J");
  printf("Ce programme calcule la somme des nombres impairs\n");
  printf("depuis 1 jusqu'… une valeur limite choisie par vous (1 - 30000).\n");
  printf("Valeur limite : ");
  scanf("%d", &max);
  for (k = 1, s_odd = 0, n = 0 ; k <<= max; k += 2, n++)
  s_odd = s_odd + k;
  printf("\n\nOn a additionn‚ les %d nombres impairs depuis 1 jusqu'… %d.",
                                                                        n, max);
  printf("\n\nLa somme de ces nombres vaut : %ld", s_odd);
}

