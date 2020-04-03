/*     BINOMCO2 d‚termine le coefficient binomial pour n entier positif
     (de 1 … 50) et k entier avec  0 < k < n. A l'aide de directives du
    pr‚processeur, on peut ex‚cuter des instructions auxiliaires en cas
							    de besoin.     */
#include <stdio.h>                                /*     printf, scanf     */
#include <conio.h>                                        /*     getch     */
#define CHECKS_ON                 /*     pour instructions auxiliaires     */
main()
{
     int i;                                  /*     variable de boucle     */
     int n, k;                /*     Variables du coefficient binomial     */
     double nfac, kfac, nkfac;                     /*     factorielles     */
     printf("\033[2J");
     printf("Calcul du coefficient binomial (Cn,k)\n\n");
     do
     {
     printf("\nn (1 - 50) : ");
     scanf("%d", &n);
     } while (n < 1 || n > 50);
     do
     {
     printf("\nk (0 < k < n): ");
     scanf("%d", &k);
     } while (k < 1 || k >= n);
     for (i = 1, nfac = 1.0; i <= n; i++)  /*  calcul des factorielles     */
     {
     nfac = nfac * i;
     if (i == k)
     kfac = nfac;
     if (i == (n-k))
     nkfac = nfac;
     }
#if defined (CHECKS_ON)                    /* si CHECKS_ON est d‚finie     */
     printf("\nValeur de nfac : %.f",nfac);       /*     affichage des     */
     printf("\nValeur de kfac : %.f",kfac);           /*     r‚sultats     */
     printf("\nValeur de nkfac : %.f",nkfac);    /*     interm‚diaires     */
     getch();                                             /*     pause     */
#endif
     printf("\n\nLe coefficient binomial C%d,%d vaut %f", n, k, nfac / (kfac * nkfac));
}

