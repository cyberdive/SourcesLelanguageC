	/*  DIGCHECK v‚rifie … l'aide d'une cl‚ (produite par le m‚canisme mis en 
	     oeuvre dans DIGCAT.C) la validit‚ d'un matricule de 8 chiffres.  */
	#include <stdio.h>                                         /*  printf, scanf  */
	#include <conio.h>                                                 /*  getch  */
	main()
	{
	   long pnr;                                                   /*  matricule  */
	   short digits [7];                           /*  chiffres 1-7 du matricule  */
	   short qsum [7];                                   /*  sommes des chiffres  */
	   short sqsum;                                         /*  somme des sommes  */
	   short lastdigit;                         /*  dernier chiffre du matricule  */
	   int k;                                           /*  variable de contr“le  */
	   char reply = 'o';                                /*  variable de contr“le  */
	   while (reply == 'o')
	   {
	   printf("\033[2J");
	   printf("\n\nLe programme contr“le la validit‚ de matricules.\n");
	   printf("Entrez un matricule de 8 chiffres : ");
	   scanf("%ld", &pnr);
	/*  traitement du matricule  */
	   lastdigit = (short) (pnr % 10);          /*  isolation du dernier chiffre  */
	   pnr = pnr / 10;                        /*  r‚duction du mat. … 7 chiffres  */
	   for (k = 6; k >= 0; k--)               /*  ‚clatement des autres chiffres  */
	   {
	   digits[k] = (short) (pnr % 10);
	   pnr = pnr / 10;
	   }
	   for (k = 1; k < 7; k += 2)                  /*  pond‚ration des chiffres  */
	   digits[k] = digits[k] * 3;                          /*  avec 1 3 1 3 etc.  */
	   for ( k = 0, sqsum = 0; k < 7; k++)   /*  calcul des sommes des chiffres  */
	   {                                                     /*  et totalisation  */
	   qsum[k] = (digits[k] % 10) + ((digits[k] / 10) % 10);
	   sqsum = sqsum + qsum[k];
	   }
	   if ( 10 - (sqsum % 10) == lastdigit)            /*  comparaison de la cl‚  */
	   printf("\n\nLe matricule est valide.\n\n");
	   else
	   printf("\n\nLe matricule n'est pas valide.\n\n");
	   printf("V‚rification d'un autre matricule ? (o/n)");
	   reply = getche();
	   }                                                           /*  Fin while  */
	}                                                              /*  Fin main  */

