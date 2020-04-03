/*frame dessine, via des boucles imbriqu‚es, des cadres de tailles diff‚rentes*/

#include <stdio.h>                                      /* pour printf, scanf */
#include <conio.h>                                             /* pour getche */

main()
{
 char response; /* r‚ponse de l'utilisateur, variable de contr“le du do while */
  int high;                                               /* hauteur du cadre */
  int wide;                                               /* largeur du cadre */
  int ligne;                  /* lignes : variable de contr“le du for externe */
  int col;     /* colonnes (caractŠres) : variable de contr“le du for interne */

do
 {
  printf("\033[2J");
  printf("Le programme dessine un cadre de taille variable.\n\n");

/* saisie de la taille du cadre : */

  printf("Hauteur du cadre : ");
  scanf("%d", &high);
  printf("\nLargeur du cadre : ");
  scanf("%d", &wide);

/* affichage du cadre : */
  
  printf("\033[2J");                          /* efface l'‚cran pour le cadre */
/* ligne du haut :
   Les deux bords lat‚raux sont compris dans la largeur qui vient d'ˆtre saisie.
   Afin de ne pas les compter deux fois, il faut diminuer de 2 la variable 
                                             " wide " dans la boucle " for ". */

  printf("\n+");                                     /* coin sup‚rieur gauche */
  for (col = 1; col < wide-2; col++)                     /* colonnes m‚dianes */
 printf("-");
  printf("+");                                        /* coin sup‚rieur droit */
  
  /* lignes m‚dianes :
  Les lignes du haut et du bas sont comprises dans la hauteur du cadre.
  Afin de ne pas les compter deux fois, il faut diminuer de 2 la variable
                                             " high " dans la boucle " for ". */
  for (ligne = 1; ligne < high-2; ligne++)
  {
   printf("\n|");                                              /* bord gauche */
  for (col = 1; col < wide-2; col++)
       printf(" ");                                                 /* espace */
   printf("|");                                                 /* bord droit */
 }

/* lignes du bas : */

 printf("\n+");                                      /* coin inf‚rieur gauche */
 for (col = 1; col < wide-2; col++)                      /* colonnes m‚dianes */
  printf("-");
   printf("+");                                       /* coin inf‚rieur droit */

                  /* pour savoir si l'utilisateur veut continuer … dessiner : */
  printf("\n\nAutre cadre ? (o/n)");
   response = getche();                               /* saisie de la r‚ponse */
 } while (response == 'o');                           /* nouveau cadre si 'o' */

}                                                              /* fin du main */

