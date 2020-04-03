/***  VOWERROR montre des erreurs d'affichage dues Ö des valeurs indÇfinies ***/
/*** dans des tableaux. Le caractäre de fin de saisie EOF est produit par   ***/
/*** une combinaison de touches : VOWERROR indique Ö l'utilisateur de taper ***/
/*** <CTRL>+<Z>, valable sous le systäme d'exploitation DOS. Pour d'autres  ***/
/*** systämes, modifiez de maniäre conforme le message relatif Ö <CTRL>+<Z> ***/


#include <stdio.h>                               /* pour printf, getchar, EOF */

main()
  {

     int c;
     int v [5];                     /* pour les frÇquences des voyelles a Ö u */

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
    
     printf("\nFrÇquences de voyelles :\n\n");
     printf("a\te\ti\to\tu\n\n");
     printf("%d\t%d\t%d\t%d\t%d", v[0], v[1], v[2], v[3], v[4]);
  }                                                               /* fin main */
