	/*  SEEREC3 ‚tend la version SEEREC2 en y ajoutant les fonctions 
	     SHOWCS et SHOW20 qui donnent la possibilit‚ d'afficher plusieurs strings 
	     qu'ils soient cons‚cutifs ou non.  */
	#include <stdio.h>                                       /*  printf, scanf  */
	#include <io.h>                  /*  open, close, read, write, tell, lseek  */
	#include <fcntl.h>                  /*  constantes symboliques pour 'open'  */
	#include <stdlib.h>                                  /*  atol, exit, qsort  */
	#include <string.h>                                     /*  strcpy, strcmp  */
	#include <conio.h>                                       /*  getch, getche  */
	char buffer[11];
	int fd;
	struct location
	{
	   long offset;                   /*  offset du premier string de chaque groupe 
	                                          de chaŒnes ayant la mˆme initiale.  */
	   char letter;                      /*  initiale d'une chaŒne de caractŠres  */
	};
	char noopen[ ]   =   "\nErreur … l'ouverture du fichier de donn‚es.";
	char norecord[ ]   =   "\nAucun enregistrement ne commence par cette lettre.";
	char intro[]   =   "Le programme cr‚e al‚atoirement 500 strings faits de "\
	   "majuscules, les trie et les ‚crit dans un fichier.";
	extern int brand(int p, int q);
	extern void randlet(char d[ ][11]);
	extern void menu (void);
	extern void initialize(struct location *r);
	extern int scomp(char s1[ ], char s2[ ]);
	extern void writrec(char d[ ][11], char first, struct location *r);
	extern void showa(void);
	extern void showb(struct location *r);
	extern void showcs(void);   /*  nouvelle  */
	extern void show20(void);   /*  nouvelle  */
	extern int nextpage(void);
	main()
	{
	   char data[500][11];
	   struct location reloc[27];
	   char firstletter;
	   int rep1, rep2, flag;
	   printf("\033[2J");
	   printf("%s", intro);
	   /*  cr‚ation de lettres al‚atoires  */
	   randlet(data);
	   /*  tri  */
	   qsort((void*)data, 500, sizeof(char[11]), scomp);
	   /*  ouverture/cr‚ation fichier   /
	   if ((fd = open("data.fil", O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
	   {
	   write(2, noopen, strlen(noopen));
	   exit(1);
	   }
	   initialize(reloc);                   /*  initialise tableau de structures  */
	   firstletter = reloc[1].letter = data[0][0];            /*  m‚morise initiale 
	                                                                 du string 1  */
	   writrec(data, firstletter, reloc);         /*  ‚crit strings dans fichier  */
	   printf("\nPrˆt. Affichage des chaŒnes ? (o/n)");
	   if ((rep1 = getche())== 'o')
	   {
	   do
	   {
	   flag = 0;
	   menu();                                                  /*  affiche menu  */
	   switch(rep2 = getche())
	   {
	   case 'a':                                                /*  affiche tout  */
	   showa();
	   flag = 1;
	   break;
	   case 'b':                            /*  affiche strings de mˆme initiale  */
	   showb(reloc);
	   flag = 1;
	   break;
	   case 'c':                            /*  affiche enregistrements no x … y  */
	   showcs();
	   flag = 1;
	   break;
	   case 'd':                             /*  affiche strings non cons‚cutifs  */
	   show20();
	   flag = 1;
	   break;
	   default: 
	   ;
	   }                                                          /*  Fin switch  */
	   if (flag)
	   {
	   printf("\n\n<Entr‚e> pour retourner au menu.");
	   getch();
	   }
	   } while (rep2 != 'q');
	   }                                                  /*  Fin if rep1 == 'o'  */
	}

