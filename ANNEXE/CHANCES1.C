	/*  chances1 calcule les probabilit‚s de gagner au loto  */
	
	#include <stdio.h>                                           /*  pour printf  */
	
	main()
	  {
	    double f0 = 1.0, f1, f2, f3, f4, f5, f6;  /*  factorielles : type double  */
	   double f40, f41, f42, f43, f49;            /*  vu la grandeur des nombres  */
	   double three6, four6, five6, six6;     /*  possibilit‚s d'avoir choisi parmi 
	                                                     les 6 nombres du tirage  */
	   double zero43, one43, two43, three43;  /*  possibilit‚s d'avoir choisi parmi 
	                                                       les 43 autres nombres  */
	   double six49;               /*  nombre total de combinaisons de 6 nombres  */
	   int i;                                           /*  variable de contr“le  */
	
	   printf("\033[2J");
	   printf("PROBABILITES DE GAGNER AU LOTO (6 nombres tir‚s parmi 49):\n\n");
	
	/*  calcul des factorielles  */
	   for (i = 1, f49 = 1.0; i < 50; i++)
	      {
	         f49 = f49 * i;
	         switch (i)
	            {
	               case  1:   f1 = f49; 
	                              break;
	               case  2:   f2 = f49; 
	                              break;
	               case  3:   f3 = f49; 
	                              break;
	               case  4:   f4 = f49; 
	                              break;
	               case  5:   f5 = f49; 
	                              break;
	               case  6:   f6 = f49; 
	                              break;
	               case 40:   f40 = f49; 
	                               break;
	               case 41:   f41 = f49; 
	                               break;
	               case 42:   f42 = f49; 
	                               break;
	               case 43:   f43 = f49;
	            }
	         }
	
	/*  calcul est affichage des probabilit‚s  */
	      six49 = f49/(f6 * f43);
	
	     /*  trois num‚ros  */
	     three6 = f6/(f3 * f3);                     /*  3 nombres sur les 6 bons  */
	     three43 = f43/(f3 * f40);            /*  3 nombres parmi les 43 mauvais  */
	     printf("\nLa probabilit‚ d'avoir 3 bons num‚ros est de \n");
	   printf("\t%.f sur %.f soit 1 sur %.f\n\n", three6 * three43, six49,
	      six49/(three6*three43));
	
	   /*  quatre num‚ros  */
	   four6 = f6/(f4 * f2);                        /*  4 nombres sur les 6 bons  */
	   two43 = f43/(f2 * f41);                /*  2 nombres parmi les 43 mauvais  */
	   printf("\nLa probabilit‚ d'avoir 4 bons num‚ros est de \n");
	   printf("\t%.f sur %.f soit 1 sur %.f\n\n", four6 * two43, six49,
	      six49/(four6*two43));
	
	   /*  cinq num‚ros  */
	   five6 = f6/(f5 * f1);                        /*  5 nombres sur les 6 bons  */
	   one43 = f43/(f1 * f42);                 /*  1 nombre parmi les 43 mauvais  */
	   printf("\nLa probabilit‚ d'avoir 5 bons num‚ros est de \n");
	   printf("\t%.f sur %.f soit 1 sur %.f\n\n", five6 * one43, six49,
	      six49/(five6*one43));
	
	   /*  six num‚ros  */
	   six6 = f6/(f6 * f0);                             /*  6 bons num‚ros sur 6  */
	   zero43 = f43/(f0 * f43);                /*  0 nombre parmi les 43 mauvais  */
	   printf("\nLa probabilit‚ d'avoir 6 bons num‚ros est de \n");
	   printf("\t1 sur %.f\n\n", six49/(six6*zero43));
	}                                                           /*  fin du main  */

