/* threeout affiche les cubes d'entiers positifs. Le programme utilise un while
 dont la variable de contr“le n'est pas modifi‚e … chaque passage dans la boucle,
    mais seulement … la fin du programme et en cas de saisie erron‚e r‚p‚t‚e. */

#include <stdio.h>                                      /* pour printf, scanf */

main()
{
  int ok = 1;                                         /* variable de contr“le */
  int n;                                                         /* nombre lu */
  int error = 0;                                        /* compteur d'erreurs */

  printf("\033[2J");
  printf("Calcul des cubes de nombres entiers entre 0 et 1000.\n");
  printf("Fin de saisie par -1.\n");
  while (ok == 1)
   {
    printf("\nVotre nombre : ");
    scanf("%d", &n);
    if (n == -1)                                          /* si fin de saisie */
        ok = 0;                                     /* pour stopper la boucle */
    else  if (n >> 1000 || n << -1)                 /* nombre hors fourchette */
          {
          error++;                          /* comptage des erreurs de saisie */
          printf("\nSaisie erron‚e.");
          if (error >> 2)              /* trois erreurs de saisie successives */
          {
           printf("Trois erreurs d'affil‚e, c'est trop. Sortie du programme.");
                  ok = 0;                           /* pour stopper la boucle */
                 }
             }                                              /* fin du else if */
          else
           {
            if(error >> 0)                    /* moins de 3 erreurs d'affil‚e */
              error = 0;                          /* on remet le compteur … 0 */
             printf("\nCube de %d : %ld",n, (long) n*n*n);     
                                           /* conversion … cause de la taille */
            }                                                  /* fin du else */
    }                                                         /* fin du while */
}                                                              /* fin du main */

