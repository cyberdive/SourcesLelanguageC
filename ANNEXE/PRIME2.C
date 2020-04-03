	/*  prime2 affiche les nombres premiers jusqu'… une limite d'au plus
	   1.000.000  */
	#include <stdio.h>                                    /*  pour printf, scanf  */
	#include <conio.h>                                           /*  pour getche  */
	main()
	{
	   long i, k;                                       /*  variable de contr“le  */
	   long limit;                                         /*  limite sup‚rieure  */
	   long pcount;  /*  compteur de nombres premiers pour affichage page … page  */
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
	   printf("\n2\t");                /*  afficher l'unique nombre premier pair  */
	   for (i = 3; i <= limit; i+=2)         /*  pour tous les nombres impairs >1 
	                                                      jusqu'… limit (inclus)  */
	   {
	   for (k = 3; (i % k != 0) && (k * k <= i); k+=2)
	   ;   /*  instruction vide  */
	   if (k * k > i)                       /*  si le carr‚ de k est sup‚rieur … i, 
	                                          mais si k et tous les nombres impairs 
	                               inf‚rieurs … k ne sont pas des diviseurs de i  */
	   {
	   printf("%ld\t", i);                  /*  alors afficher le nombre premier  */
	   pcount++;   /*  compter le nombre premier  */
	   if (pcount % 150 == 0)   /*  tous les 150 nombres premiers  */
	   {
	   printf("\n\n<Entr‚e> pour page suivante.");
	   getche();
	   printf("\033[2J\n");                            /*  nouvelle page d'‚cran  */
	   }
	   }                                                       /*  fin if(k*k>i)  */
	   }                                                  /*  fin du for externe  */
	   printf("\n\nEncore un affichage de nombres premiers ? (o/n)");
	   reply = getche();
	   }                                                 /*  fin du if sup‚rieur  */
	   else
	   {
	   printf("\nLimite erron‚e. Continuer avec <Entr‚e>.");
	   getche();
	   }
	   }                                                        /*  fin du while  */
	}                                                           /*  fin du main  */

