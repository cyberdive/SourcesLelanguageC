	/*  checkdat lit une date et v‚rifie sa validit‚  */
	
	#include <stdio.h>                                  /*  pour printf, scanf  */
	#include <conio.h>                                         /*  pour getche  */
	
	main()
	   {
	      int day, mon, year;                                 /*  jour, mois, an  */
	      char reply;                                   /*  variable de contr“le  */
	
	      do
	         {
			  printf("\033[2J");
			  printf("V‚rification de la date :\n\n");
	            printf("Entrez une date sous la forme JJ.MM.AAAA : ");
			  scanf("%d.%d.%d", &day, &mon, &year);
	
	
			  if (day < 1 || day > 31)     /*  jour trop petit ou trop grand  */
	               {
	                  printf("\n\nJour erron‚. <Entr‚e> pour continuer.");
	                  getche();
	               }
	
	/*  Jour trop grand pour un mois de 30 jours  */
	
	          else if ((mon == 4 || mon == 6 || mon == 9 || mon == 11) && day > 30)
	               {
	                  printf("\n\n Jour erron‚. <Entr‚e> pour continuer.");
	                  getche();
	               }
	
			  else if (mon < 1 || mon > 12) /*  mois trop petit ou trop grand  */
	               {
	                  printf("\n\n Mois erron‚. <Entr‚e> pour continuer.");
	                  getche();
	               }
	/*  Jour trop grand pour f‚vrier (ann‚e non bissextile)  */
			  else if (year % 4 != 0)
	               {
	                  if (mon == 2 && day > 28)
	                     {
							printf("\n\nF‚vrier n'a que 28 jours."
								      "<Entree> pour continuer.");
	                        getche();
	                     }
	                else
	                     {
	                        printf("\n\nDate valide.\n");
	                        printf("v‚rifier une autre date ? (o/n)");
	                        reply = getche();
	                     }
	               }
	/*  jour trop grand pour f‚vrier (ann‚e bissextile)  */
	
	          else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	               {
	                  if (mon == 2 && day > 29)
	                     {
							printf("\n\nAnn‚e bissextile."
										"F‚vrier a 29 jours."
										"<Entree> pour continuer.");
	                        getche();
	                     }
	                  else                                     /*  date correcte  */
	                     {
	                        printf("\n\nDate valide.\n");
	                        printf("Autre date ? (o/n)");
							reply = getche();
	                     }
	               }
	         } while (reply == 'o');                         /*  fin du do while  */
	   }   /*  fin du main  */

