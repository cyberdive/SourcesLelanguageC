	/*  SHONUMER transforme en lettres un nombre donn‚ compris entre 0 et 999.  */
	#include <stdio.h>                                     /*  printf, getchar  */
	#include <stdlib.h>                                               /*  atoi  */
	#include <ctype.h>                                             /*  isdigit  */
	#include <string.h>                                             /*  strcpy  */
	main()
	{
	   /*** tableaux des nombres en lettres ***/
	   char *low [20] = {   "z‚ro", "un", "deux", "trois", "quatre", "cinq", "six", "sept",
	   "huit", "neuf", "dix", "onze", "douze", "treize", "quatorze",
	   "quinze", "seize", "dix-sept'', ''dix-huit", "dix-neuf"   };
	   char *ten [10] = {   "", "", "vingt", "trente", "quarante", "cinquante", "soixante",
	   "soixante-dix", "quatre-vingt", "quatre-vingt dix"   };
	   char *hun [10] = {   "", "cent", "deux cent", "trois cent", "quatre cent",
	   "cinq cent", "six cent", "sept cent", "huit cent", "neuf cent"   };
	   char a0 [4];                                    /*  nombre alphanum‚rique  */
	   char a [4];                  /*  nombre alphanum‚rique sans z‚ros de tˆte  */
	   int c;                                                        /*  chiffre  */
	   int num;                                       /*  nombre num‚rique saisi  */
	   int i, k;                                       /*  variables de contr“le  */
	   int cnt;                                /*  compteur de caractŠres saisis  */
	   int ok;                                  /*  Flag pour contr“le de saisie  */
	   printf("\033[2J");
	   printf("ECRIRE NOMBRES EN LETTRES (ENTIERS ENTRE 0 ET 999).\n");
	   do
	   {
	   cnt = 0;
	   ok = 1;
	   printf("\n\nNombre : ");
	   while ((c = getchar()) != '\n')
	   {
	   if (!isdigit(c))                                    /*  si pas un chiffre  */
	   {
	   printf("\n\nNombre invalide.");
	   ok = 0;
	   while (getchar() != '\n')
	    ;
	   break;
	   }
	   else if (cnt > 2)
	   {
	   printf("\n\nTrop de chiffres.");
	   ok = 0;
	   while (getchar() != '\n')
	   ;
	   break;
	   }
	   else
	   a0[cnt++] = c;                                         /*  ranger chiffre  */
	   }
	   } while (!ok);
	   a0[cnt] = '\0';                                /*  ajout du caractŠre nul  */
	   /***   d‚termination et affichage du nombre en toutes lettres   ***/
	   if ((num = atoi(a0)) < 20)                              /*  nombre < 20  */
	   printf("\n\n%s", low[num]);
	   else                                                     /*  nombre > 20  */
	   {
	   /*** suppression des z‚ros de tˆte   ***/
	   if (cnt > 1 && atoi(a0) != 0)                    /*  au moins 2 chiffres  */
	   {   /*  et pas que des z‚ros  */
	   k = i = 0;
	   while (a0[ i ] == '0')                           /*  sauter z‚ros de tˆte  */
	   i++;
	   while (a0[ i ] != '\0')
	   {
	   a[k] = a0[ i ];
	   i++;
	   k++;
	   }
	   a[k] = '\0';
	   }
	   switch(strlen(a))                        /*  calcul du nombre de chiffres  */
	   {
	   case 2:
	   if ((atoi(a) % 10) == 0)                    /*  pas de chiffre des unit‚s  */
	   printf("\n\n%s", ten[atoi(a)/10]);
	   else if ((atoi[a]%10) == 1)                  /*  chiffre des unit‚s = 1  */
	   printf("\n\n%s et un", ten[atoi(a)/10]);
	   else                                          /*  chiffre des unit‚s != 1  */
	   printf("\n\n%s %s", ten[atoi(a)/10], low[atoi(a)%10]);
	   break;
	   case 3:
	   if ((atoi(a)%100) == 0)                      /*  pas d'unit‚s ni dizaines  */
	   printf("\n\n%s", hun[atoi(a)/100]);
	   else if ((atoi(a)%100) < 20)                   /*  101 … 119 par exemple  */
	   printf("\n\n%s%s", hun[atoi(a)/100], low[atoi(a)%100]);
	   else if ((atoi(a)%10) == 0)                         /*  dernier chiffre 0  */
	   printf("\n\n%s%s", hun[atoi(a)/100], ten[(atoi(a)%100)/10]);
	   else if ((atoi(a)%10) == 1)                         /*  dernier chiffre 1  */
	   printf("\n\n%s %s et un", hun[atoi(a)/100], ten[(atoi(a)%100)/10]);
	   else                                                  /*  autres chiffres  */
	   printf("\n\n%s %s %s", hun[atoi(a)/100], ten[(atoi(a)%100)/10], low[atoi(a)%10]);
	   }                                                          /*  Fin switch  */
	   }                                                  /*  Fin else sup‚rieur  */
	}                                                              /*  Fin main  */


