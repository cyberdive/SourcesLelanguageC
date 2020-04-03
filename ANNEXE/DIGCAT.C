	/*  DIGCAT saisit une s‚rie d'au plus 100 matricules de 7 chiffres et y ajoute un chiffre suppl‚mentaire servant de cl‚ de contr“le. Cette derniŠre est produite par un proc‚d‚ classique (sommes des chiffres, op‚rations modulo) … partir des 7 chiffres du matricule.  */
	#include <stdio.h>                                         /*  printf, scanf  */
	#include <conio.h>                                                 /*  getch  */
	main()
	{
	   long pnr[100];                                              /*  matricule  */
	   long dupnr;                                    /*  duplicata du matricule  */
	   short digits [7];                           /*  chiffres 1-7 du matricule  */
	   short qsum [7];                                   /*  sommes des chiffres  */
	   short sqsum = 0;                       /*  sommes des sommes des chiffres  */
	   short pdigit;                                                     /*  cl‚  */
	   int i = 0, k;                                   /*  variables de contr“le  */
	   int last;                            /*  Index du dernier matricule saisi  */
	   printf("\033[2J");
	   printf("\n\nLe programme cr‚e un matricule de 8 chiffres "
			   " avec cl‚ de contr“le.\n");
	   printf("Entrez des matricules (100 au plus) form‚s chacun de 7 chiffres. "
			   "Fin par 0 :\n\n");
	/*  saisie des matricules  */
	   do
	   scanf("%ld", &pnr[i++]);
	   while (i < 100  &&  pnr[i-1] != 0);
	   if (i > 1)                                /*  un matricule saisi au moins  */
	   {
	   if (i == 100)
	   {
	   last = i-1;                          /*  on n'a pas tap‚ de marque de fin  */
	   printf("\n\nOn a saisi 100 matricules. Capacit‚ ‚puis‚e.\n");
	   printf("<Entr‚e> pour continue.");
	   getch();
	   }
	   else
	   last = i - 2;                              /*  on a tap‚ la marque de fin  */
	/*  traitement du matricule  */
	   for ( i = 0; i <= last; i++)
	   {
	   dupnr = pnr[i];                              /*  duplication du matricule  */
	   for (k = 6; k >= 0; k--)               /*  ‚clatement du mat. en chiffres  */
	   {
	   digits[k] = (short) (dupnr % 10);            /*  m‚morise dernier chiffre  */
	   dupnr = dupnr / 10;                          /*  supprime dernier chiffre  */
	   }
	   for (k = 1; k < 7; k += 2)                  /*  pond‚ration des chiffres  */
	   digits[k] = digits[k] * 3;                          /*  avec 1 3 1 3 etc.  */
	   for ( k = 0, sqsum = 0; k < 7; k++)    /*  forme les sommes des chiffres  */
	   {                                                     /*  et les totalise  */
	   qsum[k] = (digits[k] % 10) + ((digits[k] / 10) % 10);
	   sqsum = sqsum + qsum[k];
	   }
	   pdigit = 10 - (sqsum % 10);                           /*  m‚morise la cl‚  */
	   pnr[i] = pnr[i] * 10 + pdigit;                        /*  ajout de la cl‚  */
	   }                                                   /*  Fin for sup‚rieur  */
	/*  affichage des matricules complets  */
	   printf("\n\n\nLes matricules avec cl‚s donnent :\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%ld\t", pnr[i]);
	   if ( !((i+1) % 4))                           /*  affichage sur 4 colonnes  */
	   printf("\n");
	   }
	   }                                                      /*  Fin if (i > 1)  */
	}                                                              /*  Fin main  */

