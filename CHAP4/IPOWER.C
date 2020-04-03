/* ipower calcule it‚rativement la puissance d'un nombre entier avec un exposant
   positif et entier. */

  #include <stdio.h>                                    /* pour printf, scanf */
  #include <conio.h>                                           /* pour getche */

main()
{
  int a;                                                              /* Base */
  int n;                                                          /* Exposant */
  long p = 1;     /* variable r‚sultat : Base puissance exposant, initialis‚e */
  char reply = 'o'; /* variable de contr“le de la boucle externe, initialis‚e */
  int i = 1;        /* variable de contr“le de la boucle interne, initialis‚e */

  while (reply == 'o')                                      /* boucle externe */
    {
    printf("\033[2J");
    printf("Entrez une base entiŠre : ");
    scanf("%d", &a);
    printf("\nEntrer un exposant entier positif : ");
    scanf("%d", &n);

    while (i <= n)                      /* boucle interne; nombre de passages */
    {                                    /* donn‚ par la valeur de l'exposant */
      if (a == 0 || a == 1)                                /* si  base 0 ou 1 */
      break;                                             /* it‚ration inutile */

      p = p * a;                         /* autrement on ‚lŠve … la puissance */
      i++;                              /* variable de contr“le r‚initialis‚e */
              }                                       /* fin du while interne */

       if (n == 0)                                           /* si exposant 0 */
           printf("\n\n%d puissance %d vaut 1.", a, n);
       else
           printf("\n\n%d puissance %d vaut %ld", a, n, a ? p : 0);

       printf("\n\nAutre calcul ? (o/n)");
       reply = getche();
    }                                                 /* fin du while externe */
}                                                              /* fin du main */

