/*** VOWELS2 affiche les fr‚quences des voyelles dans une saisie.           ***/ 
/*** Les fr‚quences sont rang‚es dans un tableau  qui est initialis‚ … sa   ***/
/*** d‚finition. Le caractŠre de fin de saisie EOF est produit par une      ***/
/*** combinaison de touches : VOWELS2 indique … l'utilisateur de taper      ***/
/*** <CTRL>+<Z>, valable sous le systŠme d'exploitation DOS. Pour d'autres  ***/
/*** systŠmes, modifiez de maniŠre conforme le message relatif … <CTRL>+<Z> ***/


#include <stdio.h>                               /* pour printf, getchar, EOF */

main()
  {
    int c;
    int v [5] = {0};           /* pour les fr‚quences des voyelles a … u tous */
                              /* les ‚l‚ments du tableau sont initialis‚s … 0 */

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
    printf("%d\t%d\t%d\t%d\t%d", v[0], v[1], v[2], v[3], v[4]);
  }                                                               /* fin main */
