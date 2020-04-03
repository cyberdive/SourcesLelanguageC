	/*  BUBBLINT saisit des valeurs dans un tableau " int ", puis les trie en ordre croissant ou d‚croissant. Le tri se fait selon le principe du tri … bulles (proc‚d‚ d'‚change) : les ‚l‚ments contigus sont compar‚s deux … deux en partant du d‚but du tableau et ils sont permut‚s si l'‚l‚ment de rang inf‚rieur a une plus grande valeur que celle de l'‚l‚ment de rang sup‚rieur.  */
	#include <stdio.h>                                 /*  printf, scanf, getche  */
	#include <conio.h>
	main()
	{
	   int x[100];                                         /*  tableau d'entiers  */
	   int i = 0;                                       /*  variable de contr“le  */
	   int last;                          /*  Index de la derniŠre valeur saisie  */
	   int d;                                      /*  nombre de passages de tri  */
	   int temp;                        /*  variable auxiliaire pour permutation  */
	   char reply;                                      /*  variable de contr“le  */
	   printf("\033[2J");
	   printf("Le programme saisit jusqu'… 100 entiers positifs compris entre \n"
	   "0 et 30000 et les trie en ordre croissant ou d‚croissant (au choix).\n"
	   "Fin par -1.\n\n");
	   printf("Entrez les nombres positifs :\n\n");
	                                                      /*  saisie des valeurs  */
	   do
	   {
	   scanf("%d", &x[ i ]);
	   i++;
	   } while (x[i-1] != -1  &&  i < 100);
	   if (i == 100)                    /*  boucle non stopp‚e par l'utilisateur  */
	   last = i-1;                     /*  m‚morise index derniŠre valeur saisie  */
	   else                             /*  boucle termin‚e par caractŠre de fin  */
	   last = i-2;                                             /*  idem plus haut  */
	/*  affichage du tableau non tri‚  */
	   if (i == 2)                             /*  une seule valeur a ‚t‚ saisie  */
	   printf("\n\nLe tableau ne contient que la valeur : %d\n\n", x[i-2]);
	   else if (i > 2)                    /*  au moins 2 valeurs ont ‚t‚ saisies  */
	   {   
	   printf("\033[2J");
	   printf("\n\nLe tableau contient les valeurs :\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%d\t", x[ i ]);
	   if (i && (!(i % 8)))                          /*  huit colonnes par ligne  */
	   printf("\n");
	   }
	/*  tri du tableau  */
	   printf("\n\nTri du tableau ?\n"
	   "Ascendant = a   Descendant = d  Non = n :  ");
	   reply = getche();
	   switch (reply)
	   {
	   case 'a':   for (d = last; d != 0; d--)
	   for (i = 0; i < d; i++)
	   if (x[ i ] > x[i+1])                              /*  valeur 1 > valeur 2  */
	   { /*  on permute  */
	   temp = x[ i ];
	   x[ i ] = x[i+1];
	   x[i+1] = temp;
	   }
	   printf("\n\nLe tableau a ‚t‚ tri‚ en ordre ascendant :\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%d\t", x[ i ]);
	   if (i && (!(i % 8)))                             /*  8 colonnes par ligne  */
	   printf("\n");
	   }
	   break;
	   case 'd':   for (d = last; d != 0; d--)
	   for (i = 0; i < d; i++)
	   if (x[ i ] < x[i+1])   /*  valeur 1 < valeur 2  */
	   {   /*  on permute  */
	   temp = x[ i ];
	   x[ i ] = x[i+1];
	   x[i+1] = temp;
	   }
	   printf("\n\nLe tableau a ‚t‚ tri‚ en ordre descendant :\n\n");
	   for (i = 0; i <= last; i++)
	   {
	   printf("%d\t", x[ i ]);
	   if (i && (!(i % 8)))                             /*  8 colonnes par ligne  */
	   printf("\n");
	   }
	   }                                                          /*  Fin switch  */
	   }                                                            /*  Fin else  */
	}                                                              /*  Fin main  */

