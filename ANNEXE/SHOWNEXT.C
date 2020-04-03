	/*  shownext donne le prochain num‚ro valide (libre)
	     pouvant ˆtre attribu‚ … un produit  */
	
	#include <stdio.h>                                                /*  printf  */
	#include <conio.h>                                                /*  getche  */
	
	main()
	   {
	      char group;                                     /*  groupe de produits  */
	      int numA = 1, numB = 1, numC = 1;              /*  num‚ros de produits  */
	      char rep1;                                      /*  attribuer num‚ro ?  */
	      char rep2 = 'o';                                  /*  changer groupe ?  */
	      int i;                                       /*  variable de contr“le  */
	
	   printf("\033[2J");
	/*  saisie des num‚ros de produits  */
	
	      do
	         {
	            if (rep2 == 'o')                           /*  si nouveau groupe  */
	               {
	                  printf("\033[2J");
					   printf("\n\nEntrer le groupe de produits (A-C). ",
							"Fin par 0.\n");
					   group = getche();
							}
	                     switch (group)
	                        {
	                           case 'A': printf("\nProchain num‚ro libre : %c%d",
	                                             group, numA);
	                                        rep1 = 'x';          /*  pour forcer la 
	                                                           question suivante  */
	                                        break;
	                           case 'B': printf("\n Prochain num‚ro libre: %c%d",
	                                             group, numB);
	                                         rep1 = 'x';                /*  idem  */
	                                         break;
	                           case 'C': printf("\n Prochain num‚ro libre: %c%d",
	                                              group, numC);
	                                          rep1 = 'x';               /*  idem  */
	                                         break;
	                           case '0': rep1 = 'n';          /*  sauter toutes les 
	                                                        instructions jusqu'… la 
	                                                       fin de la boucle. Fin de 
	                                                                  la boucle.  */
	                           default: rep1 = 'n';   /*  si saisie erron‚e, sauter 
	                                                        toutes les instructions 
	                                                           jusqu'… la fin de la 
	                                                  boucle. Nouvelle saisie 20  */
	                     }
	                     while (rep1 != 'o' && rep1 != 'n')
	                        {
	                           printf("\nAttribuer num‚ro ? (o/n)");
	                           rep1 = getche();
	                        }
	
	                    if (rep1 == 'o')
	                        {
	                           printf("\nNum‚ro attribu‚.");
	
	                           if (group == 'A')
	                              numA++;
	                           else if (group == 'B')
	                              numB++;
	                           else
	                              numC++;
	
	                           printf("\nChanger le groupe ? (o/n)");
	                           rep2 = getche();
	                        }
	                     else
	                        rep2 = 'o';       /*  si rep1 ‚gal … 'n' et rep2 ‚gal … 
	                                             'n', c'est … dire si le groupe n'a 
	                                           pas ‚t‚ chang‚ avant et si le num‚ro 
	                                                  n'a pas ‚t‚ attribu‚, il faut 
	                                                           choisir … nouveau  */
	
	                  } while (group != '0');                   /*  fin do while  */
	/*  affichage des num‚ros de produits  */
	               printf("\n\n");                         /*  s‚parer affichage  */
	               if(numA-1 || numB-1 || numC-1)      /*  si au moins un num‚ro  */
	                 {                                        /*  a ‚t‚ attribu‚  */
	                    printf("Les num‚ros suivants ont ‚t‚ attribu‚s :\n\n");
	                    for ( group = 'A'; group < 'D'; group++)
	                       {
	                          for (i = 1; i < numA; i++)
	                             {
	                                printf("%c%d\t", group, i);
	                                if (i % 4 == 0)
	                                printf("\n");
	                             }
	                          if (group == 'A')
	                             numA = numB;       /*  pour le groupe B : reporter 
	                                                  le nombre de produits dans la 
	                                                   variable de contr“le numA  */
	                          else if (group == 'B')
	                             numA = numC;          /*  idem pour le groupe C  */
	                          printf("\n\n");         /*  s‚parer les affichages  */
	                       }                              /*  fin du for externe  */
	                 }                                   /*  fin du if sup‚rieur  */
	           }                                                   /*  fin main  */

