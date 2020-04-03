	/*  chances2 calcule les probabilit‚s de gagner au loto  */
	
	#include <stdio.h>                                           /*  pour printf  */
	
	main()
	   {
	      double f2, f4, f6, f39, f43, f49;                     /*  Factorielles  */
	      double six49;        /*  nombre des combinaisons de 6 nombres parmi 49  */
	      double n6;                        /*  nombre de combinaisons avec 3, 4, 5 
	                                                     ou 6 bons num‚ros sur 6  */
	      double n43;                       /*  nombre de combinaisons avec 3, 2, 1 
	                                                 ou 0 mauvais num‚ros sur 43  */
	      int i;                                        /*  variable de contr“le  */
	      int k;                                         /*  variable auxiliaire  */
	
	      printf("\033[2J");
	       printf("PROBABILITES 20DE 20GAGNER AU LOTO (6 nombres tir‚s parmi 49) :\n\n");
	/*  calcul des factorielles  */
	
	     for (i = 1, f49 = 1.0; i < 50; i++)
	        {
	           f49 = f49 * i;
	           switch (i)
	              {
	                 case 2:   f2 = f49;   
	                               break;
	                 case 4:   f4 = f49;   
	                               break;
	                 case 6:   f6 = f49;   
	                               break;
	                 case 39:   f39 = f49;   
	                                 break;
	                 case 43:   f43 = f49;
	              }
	        }
	/*  calcul et affichage des probabilit‚s  */
	        six49 = f49/(f6 * f43);           /*  nombre de toutes les combinaisons
	                                            de 6 num‚ros  */
	
	   for (i = 40, k = 0; i < 44; i++, k++)
	      {
	          n43 = f43/((f4 / (4-k)) * (f39 * i));     /*  nombre des combinaisons 
	                                  avec 3, 2, 1 ou 0 mauvais num‚ros parmi 43  */
	          n6 = f6/((f2 * (k+3)) * (f4 / (4-k)));    /*  nombre des combinaisons 
	                                          de 3, 4, 5 ou 6 bons num‚ros sur 6  */
	         if (k < 3)                             /*  3, 4, ou 5 bons num‚ros  */
	            {
				  printf("\nLa probabilit‚s de choisir %d bons num‚ros est de \n",
	                       k+3);
	                 printf("\t%.f sur %.f soit 1 sur %.f\n\n",
	                      n6*n43, six49, six49/(n6*n43));
	            }
	         else                                             /*  6 bons num‚ros  */
	            {
				 printf("\n La probabilit‚s de choisir %d bons num‚ros est de \n",
						 k+3);
	                printf("\t%.f sur %.f", n6*n43, six49);
	             }
	         f2 = f2 * (k+3);         /*  factorielle imm‚diatement sup‚rieure pour 
	                                             prochain passage dans la boucle  */
	         f39 = f39 * i;                                    /*  cf. plus haut  */
	         f4 = f4/(4-k);                /*  factorielle imm‚diatement inf‚rieure 
	                                        pour prochain passage dans la boucle  */
	      }                                                       /*  fin du for  */
	   }                                                         /*  fin du main  */
	   

