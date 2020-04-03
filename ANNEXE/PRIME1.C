	/*  prime1 affiche les nombres premiers jusqu'… une limite sup‚rieure d'au 
		 plus 1.000.000  */
	
	#include <stdio.h>                                    /*  pour printf, scanf  */
	#include <conio.h>                                           /*  pour getche  */
	
	main()
	   {
	      long i, k;                                     /*  variable de contr“le  */
		  long limit;                                      /*  limite sup‚rieure  */
		  long pcount;                              /*  compteur de nombres premier
													  pour affichage page … page  */
		  char reply = 'o';

		  while (reply == 'o')
			 {
				printf("\033[2J");
				printf("Affichage des nombres premiers entre 2\n");
				printf("et une limite sup‚rieure (<= 1000000).\n");
				printf("Limite : ");
				scanf("%ld", &limit);
	
				if (limit >= 2 && limit <= 1000000)
	               {
	                  pcount = 0;
	                  printf("\n2\t");                 /*  afficher l'unique nombre 
	                                                                premier pair  */
	                 for (i = 3; i <= limit; i+=2)       /*  pour tous les nombres 
	                                           impairs >1 jusqu'… limit (inclus)  */
	                    {
	                       for (k = 3; k < i; k+=2)   /*  pour les nombres impairs 
	                                                     < i  */
	                       if (i % k == 0)      /*  si on a trouv‚ des diviseurs  */
	                           break;                    /*  on stoppe la boucle  */
	
	                       if (i == k)       /*  si on n'a trouv‚ aucun diviseur  */
	                          {
	                              printf("%ld\t", i);         /*  alors afficher le 
	                                                              nombre premier  */
	                              pcount++;        /*  compter le nombre premier  */
	                             if (pcount % 150 == 0)            /*  tous les 150 
	                                                            nombres premiers  */
	                                {
	                                 printf("\n\n<Entr‚e> pour la page suivante.");
	                                   getche();
	                                   printf("\033[2J\n");   
	                                                   /*  nouvelle page d'‚cran  */
	                                }
	                         }                                /*  fin du if(i==k  */
	                   }                                  /*  fin du for externe  */
	                printf("\n\nAutre affichage ? (o/n)");
	                reply = getche();
	             }                                       /*  fin du if sup‚rieur  */
	         else
	             {
	                printf("\nLimite erron‚e. <Entr‚e> pour continuer.");
	                getche();
	             }
	      }                                                     /*  fin du while  */
	   }                                                        /*  fin du main  */

