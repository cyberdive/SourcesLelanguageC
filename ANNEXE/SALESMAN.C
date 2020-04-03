	/*  SALESMAN range des donn‚es concernant des salari‚s dans un tableau de 
	     structures et affiche en outre une liste du personnel tri‚e selon un des 
	     champs (chiffre d'affaires r‚alis‚).  */
	#include <stdio.h>                          /*  getchar, scanf, printf, gets  */
	#include <string.h>                                               /*  strcpy  */
	#include <conio.h>                                         /*  getche, getch  */
	main()
	{
	   int i = 0, k;                                   /*  variables de contr“le  */
	   int last;                                /*  Index dernier enregistrement  */
	   int nextorstop;                                  /*  variable de contr“le  */
	   char reply;                                      /*  variable de contr“le  */
	   int page = 0;                                       /*  compteur de pages  */
	   char temp1 [20];                             /*  buffer pour permutations  */
	   char temp2 [7];                              /*  buffer pour permutations  */
	   float temp3;                                 /*  buffer pour permutations  */
	   struct date
	   {
	   short jour;
	   short mois;
	   short an;
	   };
	   struct salesman
	   {
	   char nom [20];
	   char prenom [15];
	   struct date datnaiss;                                           /*  n‚ le  */
	   char mat [7];                /*  matricule alphanum‚rique sur 6 positions  */
	   short ancte;                                     /*  anciennet‚ en ann‚es  */
	   float ca;                                                  /*  CA r‚alis‚  */
	   char mess [5];                                  /*  message ("oui"/"non")  */
	   char grat [5];                            /*  gratification ("oui"/"non")  */
	   };
	   struct elementliste
	   {
	   char nom [20];
	   char mat [7];
	   float ca;
	   };
	   struct salesman smen [100];
	   struct elementliste calist [100];
	   do
	   {
	   printf("\033[2J");
	   printf("\n\nSaisie des CA des repr‚sentants (100 au plus). Fin par 0 :\n\n");
	/********************   saisie des enregistrements   **************/
	   printf("\n\nFiche no . %d", i+1);
	   printf("\n\nNom : ");
	   gets(smen[ i ].nom);
	   if( smen[ i ].nom[0] != '0')
	   {
	   printf("\nPr‚nom : ");
	   gets(smen[ i ].prenom);
	   printf("\nDate de naissance  (jj.mm.aaaa) : ");
	   scanf("%hd.%hd.%hd", &smen[ i ].datnaiss.jour, &smen[ i ].datnaiss.mois, &smen[ i ].datnaiss.an);
	   while (getchar() != '\n')       /*  vidage du tampon de saisie : suppression 
	                                                        du <Entr‚e> de scanf  */
	   printf("\nMatricule sur 6 positions : ");
	   gets(smen[ i ].mat);
	   printf("\nAnciennet‚ (en ann‚es) : ");
	   scanf("%hd", &smen[ i ].ancte);
	   printf("\nCA r‚alis‚ : ");
	   scanf("%f", &smen[ i ].ca);
	   while (getchar() != '\n')                            /*  vidage du tampon  */
	   ;
	   if( smen[ i ].ca >= 100000)
	   {
	   strcpy(smen[ i ].mess, "non");
	   strcpy(smen[ i ].grat, "oui");
	   printf("\n\nMatricule %s marqu‚ pour prime.",
	   smen[ i ].mat);
	   printf("\n<Entr‚e> pour continuer.");
	   getch();
	   }
	   else if (smen[ i ].ca < 100000 && smen[ i ].ancte > 1)
	   {
	   strcpy(smen[ i ].mess, "oui");
	   strcpy(smen[ i ].grat, "non");
	   printf("\n\nMatricule %s marqu‚ pour avertissement.",
	   smen[ i ].mat);
	   printf("\n<Entr‚e> pour continuer.");
	   getch();
	   }
	   else
	   {
	   strcpy(smen[ i ].mess, "non");
	   strcpy(smen[ i ].grat, "non");
	   }
	   }                                       /*  Fin if (smen[ i ].nom != '0')  */
	   i++;
	   } while (i < 100  &&  smen[i-1].nom[0] != '0');
	   /********************   affichage   ***********************/
	   if (i > 1)                              /*  on a saisi au moins une fiche  */
	   {
	   if (i == 100)                          /*  pas de marque de fin de saisie  */
	   {
	   printf("\n\n100 fiches enregistr‚es. Plus d'autre saisie possible.");
	   printf("\n<Entr‚e> pour continuer.");
	   getch();
	   last = i - 1;                                    /*  Index derniŠre fiche  */
	   }
	   else                                    /*  marque de fin de saisie tap‚e  */
	   last = i - 2;                                          /*  idem plus haut  */
	   do
	   {
	   do
	   {
	   printf("\033[2J");
	   printf("\n\n\n\t\tSUITE DU TRAITEMENT:\n");
	   printf("\t\t___________________\n\n");
	   printf("\t\tVisualisation des fiches\t[v]\n\n");
	   printf("\t\tListe des CA\t\t[l]\n\n");
	   printf("\t\tFin du programme\t\t[f]\n\n");
	   printf("\n\t\tVotre choix : ");
	   reply = getche();
	   } while (reply != 'v'  &&  reply != 'l'  &&  reply != 'f');
	   switch (reply)
	   {
	   case 'v':   printf("\033[2J");
	   for (i = 0; i <= last; i++)
	   {
	   printf("\n\nFiche no . %d\n\n", i+1);
	   printf("Nom : %s, %s\n",
	   smen[ i ].nom, smen[ i ].prenom);
	   printf("N‚ le : %hd.%hd.%hd \n",smen[ i ].datnaiss.jour, smen[ i ].datnaiss.mois, smen[ i ].datnaiss.an);
	   printf("Matricule : %s\n", smen[ i ].mat);
	   printf("Anciennet‚ : % hd ann‚es\n", smen[ i ].ancte);
	   printf("CA r‚alis‚ : %.2f\n", smen[ i ].ca);
	   printf("Avertissement : %s\n", smen[ i ].mess);
	   printf("Gratification: %s", smen[ i ].grat);
	   if (!((i+1) % 2) && (i != last))
	   {
	   printf("\n\n<Entr‚e> pour page suivante. "
	   "Retour au menu par <ECHAP>.");
	   if ((nextorstop = getch()) == 27)
	   i = last +1;
	   else
	   printf("\033[2J");
	   }
	   }                                                             /*  Fin for  */
	   if (nextorstop != 27)
	   {
	   printf("\n\n<Entr‚e> pour revenir au menu.");
	   getch();
	   }
	   break;
	   case 'l':   printf("\033[2J");
	   for (i = 0; i <= last; i++)
	   {                          /*  reporter les donn‚es dans la liste … trier  */
	   strcpy(calist[ i ].nom, smen[ i ].nom);
	   strcpy(calist[ i ].mat, smen[ i ].mat);
	   calist[ i ].ca = smen[ i ].ca;
	   }
	   for (k = last; k != 0; k--)                           /*  tri de la liste  */
	   for (i = 0; i < k; i++)
	   if (calist[ i ].ca < calist[i+1].ca)
	   {
	   strcpy(temp1, calist[ i ].nom);
	   strcpy(temp2, calist[ i ].mat);
	   temp3 = calist[ i ].ca;
	   strcpy(calist[ i ].nom, calist[i+1].nom);
	   strcpy(calist[ i ].mat, calist[i+1].mat);
	   calist[ i ].ca = calist[i+1].ca;
	   strcpy(calist[i+1].nom, temp1);
	   strcpy(calist[i+1].mat, temp2);
	   calist[i+1].ca = temp3;
	   }
	   /**************   affichage de la liste   ******************/
	   printf("LISTE DES C.A.\t\t\t\tPage %d\n\n\n", ++page);
	   printf("Nom\t\tMatricule\t\tCA\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%s\t\t%s\t\t\t%.2f\n",
	   calist[ i ].nom, calist[ i ].mat, calist[ i ].ca);
	   if ((((i+1) % 15) == 0) &&  (i != last))
	   {
	   printf("\n\n<Entr‚e> pour page suivante.");
	   getch();
	   printf("\033[2J");
	   printf("LISTE DES CA\t\t\t\tPage %d\n\n\n", ++page);
	   printf("Nom\t\tMatricule\t\tCA\n\n");
	   }
	   }
	   printf("\n\n<Entr‚e> pour revenir au menu.");
	   getch();
	   page = 0;
	   break;
	   case 'f':   printf("\n\n\n\t\t***\tFin du programme\t***");
	   }                                                          /*  Fin switch  */
	   } while (reply != 'f');                                  /*  Fin do while  */
	   }                                                      /*  Fin if (i > 1)  */
	   else
	   printf("\n\nAucune fiche n'a ‚t‚ saisie.");
	}

