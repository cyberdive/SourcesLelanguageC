/* sales lit les CA mensuels de 3 entreprises, par trimestres, les totalise et
   les affiche. Il utilise pour cela une triple imbrication de type "while".  */

#include <stdio.h>                                       /* pour printf, scanf*/
#include <conio.h>                                             /* pour getche */

main()
{

int e, m, t;                                          /* variables de boucles */
float ca;                                                      /* CA mensuels */
float s;                                             /* somme des CA mensuels */

t = 1;                /* variable de la boucle la plus externe : initialis‚e au
                                                            premier trimestre */

 while (t < 5)              /* boucle la plus externe : Pour chaque trimestre */

  {
  printf("\033[2J");                    /* nouvel ‚cran pour chaque trimestre */
  printf("Trimestre %d", t);
  e = 'A';                    /* variable de la boucle m‚diane initialis‚e : 'A'
                                   (= 65 d‚cimal) pour la premiŠre entreprise */

  while (e < 'D')     /* boucle m‚diane: pour chacune des entreprises A, B, C */
   {
    s = 0.0;              /* initialisation _ 0 du total de chaque entreprise */
    m = 1;                       /* variable de la boucle interne initialis,e */
    printf("\n\nEntreprise %c\n\n", e);
    while (m < 4)                  /* boucle interne : Pour chacun des 3 mois */
     {
      printf("\nCa du mois %d: ", m);
      scanf("%f", &ca);                                       /* saisie du CA */
      s = s + ca;                                       /* totalisation du CA */
      m++;                                                    /* mois suivant */
     }                                                /* fin du while interne */
      printf("\nCA total de l'entreprise %c: %.2f\n\n\n\n", e, s);
      e++;                                             /* entreprise suivante */
     }                                                 /* fin du while m‚dian */
    if (t < 4 )                      /* pour ne pas afficher le message suivant
                                                 aprŠs le quatriŠme trimestre */
      {
       printf("Appuyez sur une touche pour passer au trimestre suivant ");
       getche();
      }
 t++;                                                    /* trimestre suivant */
 }                                                    /* fin du while externe */
}                                                              /* fin du main */

