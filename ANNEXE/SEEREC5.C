	/*  SEEREC5 ‚tend la version SEEREC4 en y ajoutant la fonction 'crstr' 
=       ("Cr‚ation de nouveaux enregistrements")  */
	#include <stdio.h>                /*  printf, scanf, fonctions de fichiers  */
	#include <io.h>                  /*  open, close, read, write, tell, lseek  */
	#include <fcntl.h>                  /*  constantes symboliques pour 'open'  */
	#include <stdlib.h>                                  /*  atol, exit, qsort  */
	#include <string.h>                                     /*  strcpy, strcmp  */
	#include <conio.h>                                       /*  getch, getche  */
	struct location
	{
	   long offset;                   /*  offset du premier string de chaque groupe 
	                                          de chaŒnes ayant la mˆme initiale.  */
	   char letter;                      /*  initiale d'une chaŒne de caractŠres  */
	};
	char buffer[11];                                              /*  tampon E/S  */
	char blanks[] = "          ";                    /*  string vide : 10 blancs  */
	int datafile, newfile;                /*  fichier de donn‚es, fichier tampon  */
	FILE *offile;                                             /*  fichier offset  */
	int noffs;                                  /*  nombre d'offsets d'initiales  */
	long nstrings;                                         /*  nombre de strings  */
	char noopen[ ]   =   "\nErreur … l'ouverture du fichier de donn‚es.";
	char norecord[ ]   =   "\nAucun enregistrement ne commence par cette lettre.";
	extern int brand(int p, int q);
	extern void randlet(char d[ ][11]);
	extern void menu (void);
	extern void initzero(struct location *r);             /*  initialise tableau de 
	                                                              structures … 0  */
	extern int initfile(struct location *r);    /*  initialise tableau struct. avec 
	                                                              fichier offset  */
	extern int scomp(char s1[ ], char s2[ ]);
	extern void writrec(char d[ ][11], char first, struct location *r);
	extern void showa(void);
	extern void showb(struct location *r);
	extern void showcs(void);
	extern void show20(void);
	extern int nextpage(void);
	extern void udstr(struct location *r);            /*  modification de string  */
	extern void destr(struct location *r);             /*  suppression de string  */
	extern crstr(struct location *r);                /*  cr‚ation nouveau string  */
	extern void writoffset(struct location *r);   /*  ‚crit offsets dans fichier  */
	main()
	{
	   char data[500][11];
	   struct location reloc[27];
	   char firstletter;
	   int rep, flag;
	   /*  initialise tableau de structures  */
	   initzero(reloc);   
	   /*  v‚rifie si fichier de donn‚es existe  */
	   if ((datafile = open("data.fil", O_RDWR)) == -1)     /*  si fichier n'existe
	                                                                         pas  */
	   {
	   /*  cr‚ation des lettres al‚atoires  */
	   randlet(data);   
	   /*  tri  */
	   qsort((void*)data, 500, sizeof(char[11]), scomp);
	   /*  ouverture/cr‚ation fichier  */
	   if ((datafile = open("data.fil", O_RDWR | O_CREAT, 0666)) == -1)
	   {
	   fprintf(stderr, noopen);
	   exit(1);
	   }
	   /*  m‚morise initiale du premier string  */
	   firstletter = reloc[1].letter = data[0][0];
	   /*  ‚crit strings dans fichier  */
	   writrec(data, firstletter, reloc);
	   writoffset(reloc);            /*  ‚crit offset de l'initiale dans fichier  */
	   }
	   else   /*  le fichier de donn‚es existe d‚j…  */
	   noffs = initfile(reloc);         /*  initialise tableau struct. avec fichier
	                                                                     offsets  */
	   lseek(datafile, 0L, 2);
	   nstrings = tell(datafile) / 10;             /*  ‚tablit nombre de strings  */
	   lseek(datafile, 0L, 0);
	   do
	   {
	   flag = 0;
	   menu();                                                  /*  affiche menu  */
	   switch(rep = getche())
	   {
	   case 'a':                                                /*  affiche tout  */
	   showa();
	   flag = 1;
	   break;
	   case 'b':                            /*  affiche strings de mˆme initiale  */
	   showb(reloc);
	   flag = 1;
	   break;
	   case 'c':                            /*  affiche strings de num‚ros x - y  */
	   showcs();
	   flag = 1;
	   break;
	   case 'd':                             /*  affiche strings non cons‚cutifs  */
	   show20();
	   flag = 1;
	   break;
	   case 'e':                                      /*  modification de string  */
	   udstr(reloc);
	   flag = 1;
	   break;
	   case 'f':                                       /*  suppression de string  */
	   destr(reloc);
	   flag = 1;
	   break;
	   case 'g':                                          /*  cr‚ation de string  */
	   crstr(reloc);
	   flag = 1;
	   break;
	   default:
	   ;
	   }                                                          /*  Fin switch  */
	   if (flag)
	   {
	   printf("\n<Entr‚e> pour revenir au menu.");
	   getch();
	   }
	   } while (rep != 'q');
	   close(datafile);
	   fclose(offile);
	}


