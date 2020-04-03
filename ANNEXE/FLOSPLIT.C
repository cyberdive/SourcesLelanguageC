	/*  FLOSPLIT saisit une s‚rie de valeurs r‚elles (100 au plus) et totalise 
	     s‚par‚ment leurs parties entiŠres et leurs parties d‚cimales.  */
	#include <stdio.h>                                                /*  printf  */
	#include <conio.h>                                                 /*  getch  */
	#include <stdlib.h>                                                 /*  atof  */
	main()
	{
	   struct floatval
	   {
	   double avantvirg;
	   double apresvirg;
	   };
	   struct floatval f [100];
	   char albuf [81];                                /*  buffer alphanum‚rique  */
	   char alavant [81];                      /*  partie entiŠre alphanum‚rique  */
	   char alapres [81];                     /*  partie d‚cimale alphanum‚rique  */
	   int i, k = 0;                                   /*  variables de contr“le  */
	   double avantsum = 0;                       /*  Somme des parties entiŠres  */
	   double apressum = 0;                      /*  Somme des parties d‚cimales  */
	   double controlsum = 0;                              /*  somme de contr“le  */
	   int pos;                                     /*  Index fin partie entiŠre  */
	   int last;                                       /*  Index derniŠre valeur  */
	   printf("\033[2J");
	   printf("Entrez des nombres r‚els. (Fin par \'f\'):\n\n");
	   gets(albuf);                                          /*  premiŠre saisie  */
	   while (albuf[0] != 'f'  &&  k < 100)
	   {
	   i = 0;
	   while (albuf[ i ] != '.')                     /*  stockage partie entiŠre  */
	   {
	   alavant[ i ] = albuf[ i ];
	   i++;
	   }
	   alavant[ i ] = '\0';                                    /*  caractŠre nul  */
	   pos = i;                                               /*  m‚morise index  */
	   while (albuf[ i ] != '\0')                   /*  stockage partie d‚cimale  */
	   {
	   alapres[i-pos] = albuf[ i ];
	   i++;
	   }
	   alapres[i-pos] = '\0';
	/****************** conversion et m‚morisation   **********************/
	   f[k].avantvirg = atof(alavant);
	   f[k].apresvirg = atof(alapres);
	   controlsum = controlsum + atof(albuf);
	   avantsum = avantsum + f[k].avantvirg;
	   apressum = apressum + f[k].apresvirg;
	   k++;
	   if (k < 100)
	   gets(albuf);
	   else
	   {
	   printf("\n\n100 valeurs d‚j… entr‚es. Fin de saisie.\n");
	   printf("<Entr‚e> pour continuer.");
	   getch();
	   }
	   }   /*  Fin while  */
	/************************** affichage *********************/
	   if (k > 0)                                 /*  au moins une valeur saisie  */
	   {
	   last = k - 1;                                   /*  Index derniŠre valeur  */
	   printf("\033[2J");
	   printf("\n\nVous avez entr‚ les valeurs suivantes :\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%f\t", f[ i ].avantvirg + f[ i ].apresvirg);
	   if (!((i+1) %4) &&  i != last)                         /*  sur 4 colonnes  */
	   printf("\n\n");
	   if (!((i+1) % 40) &&  i != last)                  /*  dix lignes par page  */
	   {
	   printf("\n\n<Entr‚e> pour page suivante.");
	   getch();
	   printf("\033[2J");
	   }
	   }
	   printf("\n\nSomme des parties entiŠres : %.0f", avantsum);
	   printf("\n\nSomme des parties d‚cimales : %f", apressum);
	   printf("\n\nSomme des parties entiŠres et d‚cimales : %f", avantsum + apressum);
	   printf("\n\nSomme des valeurs originelles : %f", controlsum);
	   }                                                      /*  Fin if (k > 0)  */
	   else
	   printf("\n\nAucune valeur n'a ‚t‚ saisie.");
	}

