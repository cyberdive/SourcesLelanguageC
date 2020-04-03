/*     BINOMCO1 d‚termine le coefficient binomial pour n entier positif et k
					       entier avec  0 < k < n.     */
#include <stdio.h>
main()
{
     int i;                                  /*     variable de boucle     */
     int n, k;                /*     Variables du coefficient binomial     */

     double kfac, nkfac;                           /*     factorielles     */
     double nfac;

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

     for (i= 1 , nfac = 1.0 ; i <= n; i++)    /*  calcul des factorielles  */
     {
       nfac = nfac * i;

       if (i == k)
	 kfac = nfac;
       if (i == (n-k))
	 nkfac = nfac;

     }
     printf("\n\nLe coefficient binomial C%d,%d vaut %f", n, k, nfac / (kfac * nkfac));
}

