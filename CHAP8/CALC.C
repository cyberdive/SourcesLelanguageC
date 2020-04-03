/* CALC calcule, pour un prix qui est saisi, la TVA ainsi que le prix TTC. */
#include <stdio.h>
#define TVA     18.6        /*  d‚finition de la constante symbolique TVA  */
main()
{
     float prix;
     printf("\033[2J");
     printf("\n\nPrix : ");
     scanf("%f", &prix);
     printf("\n\nTVA … 18,60 %% : %.2f", (prix/100) * TVA);
     printf("\nPrix TTC (TVA … 18,60 %%) : %.2f", prix + (prix/100) * TVA);
}

