	/*  SEERE +…… l'aige des fonctions 'udstr' et 'destr', ‚tend la version
	     SEEREC3 en y ajoutant les op‚rations "Modification" et "Suppression
	     d'enregistrements".  */
	#include <stdio.h>                /*  printf, scanf, fonctions de fichiers  */
	#include <io.h>                  /*  open, close, read, write, tell, lseek  */
	#include <fcntl.h>                  /*  constantes symboliques pour 'open'  */
	#include <stdlib.h>                                  /*  atol, exit, qsort  */
	#include <string.h>                                     /*  strcpy, strcmp  */
	#include <conio.h>
					       /*  getch, getche  */
	#define STRLEN 10

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
	char intro[]   =   "Le programme cr‚e al‚atoirement 500 strings faits de "\
	   "majuscules, les trie et les ‚crit dans un fichier.";
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
	   if ((datafile = open("data.fil", O_RDWR)) == -1)              /*  si fichier
	                                                                n'existe pas  */
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
	   else                                /*  le fichier de donn‚es existe d‚j…  */
	   noffs = initfile(reloc);                  /*  initialise tableau struct avec
	                                                             fichier offsets  */
	   lseek(datafile, 0L, 2);
	   nstrings = tell(datafile) / 10;             /*  ‚tablit nombre de strings  */
	   lseek(datafile, 0L, 0);
	   do
	   {
	   flag = 0;
	   menu();   /*  affiche menu  */
	   switch(rep = getche())
	   {
	   case 'a':   /*  affiche tout  */
	   showa();
	   flag = 1;
	   break;
	   case 'b':   /*  affiche strings de mˆme initiale  */
	   showb(reloc);
	   flag = 1;
	   break;
	   case 'c':   /*  affiche strings de num‚ros x - y  */
	   showcs();
	   flag = 1;
	   break;
	   case 'd':   /*  affiche strings non cons‚cutifs  */
	   show20();
	   flag = 1;
	   break;
	   case 'e':   /*  modification de string  */
	   udstr(reloc);
	   flag = 1;
	   break;
	   case 'f':   /*  suppression de string  */
	   destr(reloc);
	   flag = 1;
	   break;
	   default:
	   ;
	   }   /*  Fin switch  */
	   if (flag)
	   {
	   printf("\n<Entr‚e> pour revenir au menu.");
	   getch();
	   }
	   } while (rep != 'q');
	   close(datafile);
	   fclose(offile);
	}


	void menu (void)   /*  affiche menu, version ‚tendue  */
	{
	   printf("\033[2J");
	   printf("\n\n\nAFFICHAGE DES CHAINES :\n\n");
	   printf("Tout   (a)\n\n");
	   printf("Initiale   (b)\n\n");
	   printf("Num‚ros (s‚quence)   (c)\n\n");
	   printf("Num‚ros (quelconque)   (d)\n\n");
	   printf("Modification   (e)\n\n");
	   printf("Suppression   (f)\n\n");
	   printf("Quitter   (q)\n\n\n");
	   printf("Votre choix : ");
	}


	void initzero(struct location *r)   /*  initialise … 0 tableau de structures 'reloc'  */
	{
	   int i;
	   for (i = 0; i < 27; i++)
	   {
	   r[ i ].offset = 0;
	   r[ i ].letter = '\0';
	   }
	}
	int initfile(struct location *r)   /*  initialise 'reloc' avec fichier d'offsets  */
	{
	   int bytes, k, first, currentfirst;
	   /*  si fichier d'offsets n'existe pas, on le cr‚e  */
	   if ((offile = fopen("data.off", "rb+")) == NULL)
	   {
	   if (( offile = fopen("data.off", "wb+")) == NULL)
	   {
	   fprintf(stderr, "\nErreur … l'ouverture du fichier d'offsets.");
	   exit (2);
	   }
	   k = 1;
	   /*  lire fichier et stocker offsets des initiales dans le tableau de
	       structures  */
	   bytes = read(datafile, buffer, STRLEN);
	   r[1].letter = first = buffer[0];
	   r[1].offset = 0L;
	   while (bytes > 0)
	   {
	   currentfirst = buffer[0];
	   if (first != currentfirst)
	   {
	   first = currentfirst;
	   k++;
	   r[k].letter = first;
	   r[k].offset = tell(datafile) - 10;
	   }
	   bytes = read(datafile, buffer, STRLEN);
	   }
	   /*  ‚crire offsets dans fichier  */
	   fseek(offile, 0L, 0);
	   fwrite(r, sizeof(struct location), 27, offile);
	   fseek(offile, 0L, 0);
	   return (k);
	   }
	   else                                       /*  fichier d'offsets existe :  */
	   {                      /*  il sert … initialiser le tableau de structures  */
	   fseek(offile, 0L, 0);
	   fread(r, sizeof(struct location), 27, offile);
	   fseek(offile, 0L, 0);
	   /*  compte le nombre d'initiales diff‚rentes  */
	   for (k = 1; isupper(r[k].letter); k++)
	   ;
	   return (k-1);
	   }
	}


	void writoffset(struct location *r)
	{
	   if ((offile = fopen("data.off", "wb+")) == NULL)
	   {
	   fprintf(stderr, "\nErreur … l'ouverture du fichier d'offsets.");
	   exit(2);
	   }
	   fwrite(r, sizeof(struct location), 27, offile);
	}


	void udstr(struct location *r)              /*  modifie string dans fichier  */
	{
	   void getupper(char *buffer, int len); /*  lit 'len' majuscules exactement  */
	   char oldstr[11], newstr[11];    /*  ancien et nouveau contenu d'un string  */
	   int i, k, rep1, rep2;
	   int bytes, first, currentfirst;
	   int notfound;                                                    /*  Flag  */
	   long p;                                         /*  position dans fichier  */
	   long offnew;                            /*  offset pour le string modifi‚  */
	   int append;                     /*  Flag pour l'ajout … la fin du fichier  */
	   do
	   {
	   printf("\n\nQuelle chaŒne faut-il modifier ? (saisie en majuscules) :\n\n");
	   getupper(oldstr, STRLEN);
	   i = 1;
	   /*  recherche de l'initiale  */
	   while (oldstr[0] != r[ i ].letter && i < 27)
	   i++;
	   if (i < 27)   /*  initiale trouv‚e  */
	   {
	   /*  positionnement sur premier string ayant cette initiale  */
	   lseek(datafile, r[ i ].offset, 0);
	   /*  recherche du string  */
	   bytes = read(datafile, buffer, STRLEN);
	   while ((notfound = strcmp(oldstr, buffer) && (oldstr[0] == buffer[0]) && bytes > 0)
	   bytes = read(datafile, buffer, STRLEN);
	   if (notfound)                                       /*  string non trouv‚  */
	   {
	   fprintf(stderr, "\n\nString non trouv‚. "
	   "Rechercher autre string … modifier ? (o/n)");
	   if ((rep1 = getche()) == 'o'  ||  rep1 == 'O')
	   {
	   rep2 = 'o';                   /*  pour que soit remplie la cond. de boucle  */
	   continue;
	   }
	   else
	   return;
	   }
	   else                                                    /*  string existe  */
	   {
	   printf("\n\nString modifi‚ : ");
	   getupper(newstr, STRLEN);
	   if (strcmp(oldstr, newstr) == 0)
	   {
	   printf("\n\nStrings identiques. <Entr‚e> pour continuer.");
	   getch();
	   rep2 = 'o';                                             /*  cf. plus haut  */
	   continue;
	   }
	   /*  ouvre fichier interm‚diaire  */
	   if ((newfile = open("data.new", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
	   {
	   fprintf(stderr, "\n\nErreur lors du transfert de donn‚es.");
	   exit(3);
	   }
	   /*  recule de 10 octets et ‚crase ancien string par des blancs  */
	   lseek(datafile, -10L, 1);
	   write(datafile, blanks, STRLEN);
	   /*  d‚termine position dans le fichier pour le string modifi‚  */
	   lseek(datafile, 0L, 0);
	   bytes = read(datafile, buffer, STRLEN);
	   while (strcmp(newstr, buffer) > 0 && bytes > 0)
	   bytes = read(datafile, buffer, STRLEN);
	   if (bytes > 0)
	   offnew = tell(datafile) - 10;
	   else                                                   /*  fin de fichier  */
	   offnew = tell(datafile);
	   /*  met … jour fichier de donn‚es … l'aide du fichier auxiliaire  */
	   lseek(datafile, 0L, 0);                         /*  vers d‚but du fichier  */
	   p = 0L;
	   append = 1;
	   while ((bytes = read(datafile, buffer, STRLEN)) > 0)
	   {
	   /*  ne pas dupliquer les strings ‚cras‚s  */
	   if (strcmp(buffer, blanks) == 0)
	   {
	   p+=10L;
	   continue;
	   }
	   /*  insertion nouveau string  */
	   if (p == offnew)   
	   {
	   write(newfile, newstr, STRLEN);
	   append = 0;                    /*  nouv. string non ajout‚ en fin fichier  */
	   }
	   write(newfile, buffer, bytes);
	   p+=10L;
	   }
	   /*  le string modifi‚ doit ˆtre ins‚r‚ en tant que nouveau dernier 
	       (cas non trait‚ par la boucle pr‚c‚dente)  */
	   if (append)   
	   write(newfile, newstr, STRLEN);
	   /*  actualise fich. donn‚es via fich. tampon, note offsets initiales  */
	   lseek(datafile, 0L, 0);
	   lseek(newfile, 0L, 0);
	   k = 1;
	   /*  initialise tableau de struct. avant mise … jour 
	       afin d'effacer les anciennes donn‚es non ‚cras‚es  */
	   initzero(r);
	   bytes = read(newfile, buffer, STRLEN);
	   r[k].letter = first = buffer[0];
	   while (bytes > 0)
	   {
	   write (datafile, buffer, bytes);
	   currentfirst = buffer[0];
	   if (first != currentfirst)
	   {
	   first = currentfirst;
	   k++;
	   r[k].letter = first;
	   r[k].offset = tell(datafile) - 10;
	   }
	   bytes = read(newfile, buffer, STRLEN);
	   }
	   noffs = k;                               /*  actualise nombre d'initiales  */
	   fseek(offile, 0L, 0);                     /*  actualise fichier d'offsets  */
	   fwrite(r, sizeof(struct location), 27, offile);
	   fseek(offile, 0L, 0);
	   close(newfile);
	   }                                  /*  Fin branche 'else' de if(notfound)  */
	   }                                                    /*  Fin if (i < 27)  */
	   else                    /*  le string n'existe pas avec l'initiale donn‚e  */
	   {
	   fprintf(stderr, "\n\nString non trouv‚. Autre string … modifier ? (o/n)");
	   if ((rep1 = getche()) == 'o'  ||  rep1 == 'O')
	   {
	   rep2 = 'o';                                             /*  cf. plus haut  */
	   continue;
	   }
	   else
	   return;
	   }
	   printf("\n\nAutre string … modifier ? (o/n)");
	   rep2 = getche();
	   } while (rep2 == 'o'  ||  rep2 == 'O');
	}


	void destr(struct location *r)             /*  supprime string dans fichier  */
	{
	   void getupper(char *buffer, int len); /*  lit 'len' majuscules exactement  */
	   char delstr[11];                                     /*  string … effacer  */
	   int i, k, rep1, rep2;
	   int bytes, first, currentfirst;
	   int notfound;                                                    /*  Flag  */
	   do
	   {
	   printf("\n\nString … supprimer (saisie en majuscules) ? : \n\n");
	   getupper(delstr, STRLEN);
	   i = 1;
	   /*  recherche de l'initiale  */
	   while (delstr[0] != r[ i ].letter && i < 27)
	   i++;
	   if (i < 27)                                          /*  initiale existe  */
	   {
	   /*  positionnement sur premier string ayant cette initiale  */
	   lseek(datafile, r[ i ].offset, 0);
	   /*  recherche du string  */
	   bytes = read(datafile, buffer, STRLEN);
	   while ((notfound = strcmp(delstr, buffer) && (delstr[0] == buffer[0]) && bytes > 0)
	   bytes = read(datafile, buffer, STRLEN);
	   if (notfound)                                       /*  String non trouv‚  */
	   {
	   fprintf(stderr, "\n\nString non trouv‚. "
	   "Autre string … effacer ? (o/n)");
	   if ((rep1 = getche()) == 'o'  ||  rep1 == 'O')
	   {
	   rep2 = 'o';                              /*  pour remplir cond. de boucle  */
	   continue;
	   }
	   else
	   return;
	   }
	   else   /*  String existe  */
	   {
	   /*  ouvre fichier auxiliaire  */
	   if ((newfile = open("data.new", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
	   {
	   fprintf(stderr, "\n\nErreur lors du transfert de donn‚es.");
	   exit(3);
	   }
	   /*  recule de 10 octets et ‚crase ancien string par des blancs  */
	   lseek(datafile, -10L, 1);
	   write(datafile, blanks, STRLEN);   
	   /*  actualise fichier de donn‚es … l'aide du fichier tampon  */
	   lseek(datafile, 0L, 0);                         /*  vers d‚but du fichier  */
	   while ((bytes = read(datafile, buffer, STRLEN)) > 0)
	   {
	   /*  ne pas recopier les strings ‚cras‚s  */
	   if (strcmp(buffer, blanks) == 0)
	   continue;
	   write(newfile, buffer, bytes);
	   }
	   /*  actualise fichier de donn‚es via fichier tampon et note les 
	       offsets des initiales. L'ancien fichier de donn‚es est d'abord 
	       r‚duit … 0 octets pour que la nouvelle version ne contienne pas 
	       de r‚sidus provenant de l'ancienne.  */
	   /*  ferme, puis rouvre le fichier  */
	   close (datafile);   
	   datafile = open("data.fil", O_RDWR | O_TRUNC);
	   lseek(newfile, 0L, 0);
	   k = 1;
	   /*  initialise tableau de struct. avant mise … jour 
	       afin d'effacer les anciennes donn‚es non ‚cras‚es  */
	   initzero(r);
	   bytes = read(newfile, buffer, STRLEN);
	   r[k].letter = first = buffer[0];
	   while (bytes > 0)
	   {
	   write (datafile, buffer, bytes);
	   currentfirst = buffer[0];
	   if (first != currentfirst)
	   {
	   first = currentfirst;
	   k++;
	   r[k].letter = first;
	   r[k].offset = tell(datafile) - 10;
	   }
	   bytes = read(newfile, buffer, STRLEN);
	   }
	   noffs = k;                               /*  actualise nombre d'initiales  */
	   fseek(offile, 0L, 0);                     /*  actualise fichier d'offsets  */
	   fwrite(r, sizeof(struct location), 27, offile);
	   fseek(offile, 0L, 0);
	   /*  actualise nombre de chaŒnes  */
	   lseek(datafile, 0L, 2);
	   nstrings = tell(datafile) / 10;
	   lseek(datafile, 0L, 0);
	   close(newfile);
	   }                                  /*  Fin branche 'else' du if(notfound)  */
	   }                                                    /*  Fin if (i < 27)  */
	   else                         /*  string n'existe pas avec initiale donn‚e  */
	   fprintf(stderr, "\n\nString non trouv‚. Autre string … effacer ? (o/n)");
	   if ((rep1 = getche()) == 'o'  ||  rep1 == 'O')
	   {
	   rep2 = 'o';                                             /*  cf. plus haut  */
	   continue;
	   }
	   else
	   return;
	   }
	   printf("\n\nString effac‚. Suppression d'autres strings ? (o/n)");
	   rep2 = getche();
	   } while (rep2 == 'o'  ||  rep2 == 'O');
	}


	void getupper(char *buffer, int len)   /*  lit 'len' majuscules exactement  */
	{
	   int i = 0;
	   int c;
	   int func_or_cursorkey = 0;               /*  Flag pour touche de fonction ou 
	                                                                de direction  */
	   while (i <= len)
	   {
	   c = getch();
	   if (i == len  &&  c == '\r')
	   break;
	   if (func_or_cursorkey)       /*  saisie pr‚c. = touche fonction/direction  */
	   {
	   func_or_cursorkey = 0;
	   continue;                     /*  ignore saisie (= scancode de la touche)  */
	   }
	   if (c == 0)                        /*  touche de fonction ou de direction  */
	   {
	   func_or_cursorkey = 1;                                /*  positionne flag  */
	   }
	   else if (c == 8)                                   /*  touche <RET_ARR>  */
	   {
	   if(i > 0)                                 /*  au moins 1 caractŠre saisi  */
	   {                   /*  le curseur ne doit pas reculer aprŠs premier car.  */
	   printf("\b \b");              /*  efface car. gauche, puis recule curseur  */
	   i--;                             /*  ‚crase dans le tampon le car. effac‚  */
	   }
	   }
	   else if (i < len  && isupper(c))                /*  caractŠres invalides  */
	   {
	   buffer[i++] = c;                                   /*  m‚morise caractŠre  */
	   putchar(c);                                         /*  affiche caractŠre  */
	   }
	   else
	   putchar(7);                                             /*  bip si erreur  */
	   }
	   buffer[ i ] = '\0';                                  /*  fin de la saisie  */
	}



