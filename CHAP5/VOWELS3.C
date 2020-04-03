/*** VOWELS3 calcule et affiche les fr‚quences des voyelles dans une saisie.***/
/*** Les fr‚quences sont rang‚es dans un tableau  qui est initialis‚ … sa   ***/
/*** d‚finition. L'affichage des fr‚quences se fait ‚galement par une       ***/
/*** boucle. Le caractŠre de fin de saisie EOF est produit par une          ***/
/**** combinaison de touches : VOWELS3 indique … l'utilisateur de taper     ***/
/*** <CTRL>+<Z>, valable sous le systŠme d'exploitation DOS. Pour d'autres  ***/
/*** systŠmes, modifiez de maniŠre conforme le message relatif … <CTRL>+<Z> ***/

#include <stdio.h>                               /* pour printf, getchar, EOF */

main()
  {
    int c;
    int v [5];                      /* pour les fr‚quences des voyelles a … u */
    int k;                                            /* variable de contr“le */

    for (k = 0; k < 5; k++)         /* initialise … 0 les ‚l‚ments du tableau */
          v[k] = 0;

    printf("Le programme compte les voyelles dans ce que vous avez saisi.\n");
    printf("Entrez un texte. Fin par <CTRL>+<Z>:\n");
    while ((c = getchar()) != EOF)
           switch (c)
              {
                 case 'A':
                 case 'a':  v[0]++;  break;
                 case 'E':
                 case 'e':  v[1]++;  break;
                 case 'I':
                 case 'i':  v[2]++;  break;
                 case 'O':
                 case 'o':  v[3]++;  break;
                 case 'U':
                 case 'u':  v[4]++;
               }
    printf("\nFr‚quences des voyelles :\n\n");
    printf("a\te\ti\to\tu\n\n");
    for (k = 0; k < 5; k++)              /* affichage des ‚l‚ments du tableau */
    printf("%d\t", v[k]);                                   /* via une boucle */
  }                                                               /* fin main */
