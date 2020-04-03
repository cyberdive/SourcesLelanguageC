	/*  FUNCSR5 contient les fonctions personnelles utilis‚es dans SEEREC5.  */
	#include <stdio.h>
	#include <io.h>
	#include <fcntl.h>
	#include <stdlib.h>
	#include <string.h>
	#include <conio.h>
	#include <ctype.h>
	#define STRLEN 10
	struct location
	{
	   long offset;
	   char letter;
	};
	extern char buffer [11];
	extern int fd;
	extern char letter;
	extern char blanks[];
	extern char norecord[];
	extern int datafile;
	extern int newfile;
	extern FILE *offile;
	extern long nstrings;
	extern int noffs;
	int brand(int p, int q)         /*  cr‚e des nombres al‚atoires entre p et q  */
	{
	   return (p +(rand() % (q-p+1)));
	}
	void randlet(char d[][11])       /*  cr‚e et m‚morise des strings al‚atoires  */
	{
	   int i, k;
	   for (i = 0; i < 500; i++)               /*  500 Strings de 10 majuscules  */
	   {
	   for (k = 0; k < 10; k++)
	   buffer[k] = (char) brand(65,90);
	   buffer[k] = '\0';
	   strcpy(d[ i ], buffer);
	   }
	}
	void menu (void)                                       /*  affichage du menu  */
	{
	   printf("\033[2J");
	   printf("\n\n\nAFFICHAGE DES CHAINES :\n\n");
	   printf("Tout   (a)\n\n");
	   printf("Initiale   (b)\n\n");
	   printf("Num‚ros (s‚quence)   (c)\n\n");
	   printf("Num‚ros (quelconque)   (d)\n\n");
	   printf("Modification   (e)\n\n");
	   printf("Suppression   (f)\n\n");
	   printf("Cr‚ation   (g)\n\n");
	   printf("Quitter   (q)\n\n\n");
	   printf("Votre choix : ");
	}
	void initzero(struct location *r)      /*  initialise … 0 tableau de structures 
	                                                                     'reloc'  */
	{
	   int i;
	   for (i = 0; i < 27; i++)
	   {
	   r[ i ].offset = 0;
	   r[ i ].letter = '\0';
	   }
	}
	int initfile(struct location *r)            /*  initialise 'reloc' avec fichier 
	                                                                   d'offsets  */
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
	int scomp(char s1[], char s2[])       /*  fonction de comparaison pour qsort  */
	{
	   return (strcmp(s1, s2));
	}
	int nextpage(void)                              /*  annonce de page suivante  */
	{
	   printf("\n\n<Entr‚e> pour page suivante.");
	   getch();
	   printf("\033[2J");
	   return (0);
	}
	void writrec(char d[][11], char first, struct location *r)         /*  ‚criture 
	                                                        chaŒnes dans fichier  */
	{
	   int i, k;
	   char currentfirst;
	   k = 1;
	   for (i = 0; i < 500; i++)
	   {
	   strcpy(buffer, d[ i ]);
	   write(fd, buffer, strlen(buffer));         /*  ‚crit strings dans fichier  */
	   currentfirst = d[ i ][0];                 /*  initiale du string en cours  */
	   if (first != currentfirst)                          /*  nouvelle initiale  */
	   {
	   first = currentfirst;
	   k++;
	   r[k].letter = letter;                      /*  m‚morise nouvelle initiale  */
	   r[k].offset = tell(fd) - 10;           /*  m‚morise offset du premier string 
	                                                        ayant cette initiale  */
	   }
	   }
	}
	void showa(void)                               /*  afficher tous les strings  */
	{
	   int count, bytes;
	   printf("\033[2J");
	   count = 0;
	   lseek (fd, 0L, 0);                              /*  vers d‚but du fichier  */
	   while ((bytes = read(fd, buffer, STRLEN)) > 0)
	   {
	   write(1, buffer, bytes);
	   printf("\n");
	   count++;
	   if (count == 20)
	   count = nextpage();
	   }
	}
	void showb(struct location *r)       /*  affiche les strings ayant une certaine 
	                                                                    initiale  */
	{
	   int count, i, bytes;
	   char first;
	   count = 0;
	   do
	   {
	   printf("\n\nInitiale : ");
	   first = getche();
	   } while (first < 65 || first > 90);

	   i = 1;
	   /*  ne convient pas : on saute la lettre  */
	   while (first != r[ i ].letter && i < 27)
	   i++;
	   if (i > 26)                                     /*  initiale non trouv‚e  */
	   {
	   printf("%s", norecord);
	   return;
	   }
	   printf("\033[2J");
	   lseek(fd, r[ i ].offset, 0);                   /*  vers premier string ayant 
	                                                            initiale choisie  */
	   while ((bytes = read(fd, buffer, STRLEN)) > 0 && buffer[0] == first)
	   {
	   write(1, buffer, bytes);
	   printf("\n");
	   count++;
	   if (count == 20)
	   count = nextpage();
	   }
	}
	void showcs(void)                            /*  affiche strings no x … no y  */
	{
	   long startno, endno;                       /*  num‚ros de d‚but et de fin  */
	   int bytes, result, count;
	   do
	   {
	   count = 0;
	   printf("\n\nNum‚ros des strings (format de saisie : d‚but-fin) : ");
	   result = scanf("%ld-%ld", &startno, &endno);
	   } while((startno<1 || startno > 500)  || (endno < startno || endno > 500)  || (result != 2));
	   lseek(fd, (startno-1)*10, 0);
	   while (startno <= endno)
	   {
	   bytes = read(fd, buffer, STRLEN);
	   printf("\n");
	   write(1, buffer, bytes);
	   startno++;
	   count++;
	   if (count == 20)
	   count = nextpage();
	   }
	}
	void show20(void)              /*  affiche 20 strings de num‚ros quelconques  */
	{
	   int check_entry(char *s);                          /*  contr“le de saisie  */
	   char inbuf[512];                                     /*  tampon de saisie  */
	   char abuf[11];                             /*  tampon alpha. pour nombres  */
	   long nums[20];                                    /*  num‚ros des strings  */
	   int i, k, n, ok;                                /*  variables de contr“le  */
	   int bytes;                                             /*  caractŠres lus  */
	   int result;                            /*  r‚sultat du contr“le de saisie  */
	   do
	   {
	   ok = 1;
	   fflush(stdin);                  /*  Prophylaxie : vidage tampon de saisie  */
	   printf("\n\nNum‚ros des strings (20 num‚ros maximum. "
	   "Format de saisie : no1+no2+no3+...) :\n\n");
	   gets(inbuf);
	   /*  contr“le de la saisie  */
	   if ((result = check_entry(inbuf)) < 0)
	   {
	   fprintf(stderr, "\nSaisie non valide.");
	   ok = 0;
	   continue;
	   }
	   i = n = 0;
	   while (inbuf[ i ])
	   {
	   k = 0;
	   /*  extraction du num‚ro de string  */
	   while (inbuf[ i ] != '+'  &&  inbuf[ i ] != '\0')
	   abuf[k++] = inbuf[i++];
	   abuf[k] = '\0';
	   if ((nums[n] = atol(abuf)) < 1  ||  nums[n] > 500)
	   {
	   fprintf(stderr, "\nNum‚ros 1 … 500 seulement !");
	   ok = 0;
	   break;
	   }
	   if (inbuf[ i ])
	   {
	   i++;
	   n++;
	   }
	   }
	   } while (! ok);
	   for (i = 0; i < n; i++)                              /*  affiche strings  */
	   {
	   lseek(fd, (nums[ i ]-1)*10, 0);
	   bytes = read(fd, buffer, STRLEN);
	   printf("\n");
	   write(1, buffer, bytes);
	   }
	}
	int check_entry(char *s)    /*  contr“le validit‚ des caractŠres des strings  */
	{
	   int count, i;
	   if (! isdigit(s[0]))
	   return (-1);
	   count = i = 0;
	   while (s[ i ])
	   {
	   if (s[ i ] != '+'  &&  !isdigit(s[ i ]))
	   return (-1);
	   else if (s[ i ] == '+')
	   {
	   if (!isdigit(s[i+1]))
	   return (-1);
	   else
	   {
	   count++;
	   if (count > 19)
	   return (-1);
	   }
	   }
	   i++;
	   }
	   return(count);
	}
	void udstr(struct location *r)               /*  modifie string dans fichier  */
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
	   while (
			(notfound = strcmp(oldstr, buffer)) && (oldstr[0] == buffer[0]) && bytes >0);
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
	   else   /*  fin de fichier  */
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
	void destr(struct location *r)              /*  supprime string dans fichier  */
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
	   while ((notfound = strcmp(delstr, buffer) && (delstr[0] == buffer[0])) && bytes > 0);
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
	   else                                                    /*  String existe  */
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
	   lseek(datafile, 0L, 0);   /*  vers d‚but du fichier  */
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
	   else   /*  string n'existe pas avec initiale donn‚e  */
	   fprintf(stderr, "\n\nString non trouv‚. Autre string … effacer ? (o/n)");
	   if ((rep1 = getche()) == 'o'  ||  rep1 == 'O')
	   {
	   rep2 = 'o';                                             /*  cf. plus haut  */
	   continue;
	   }
	   else
	   return;

	   printf("\n\nString effac‚. Suppression d'autres strings ? (o/n)");
	   rep2 = getche();
	   } while (rep2 == 'o'  ||  rep2 == 'O');
	}
	void getupper(char *buffer, int len)     /*  lit 'len' majuscules exactement  */
	{
	   int i = 0;
	   int c;
	   int func_or_cursorkey = 0;        /*  flag pour touche fonction/direction  */
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
	void crstr(struct location *r)         /*  enregistre un nouveau string dans le
	                                                                     fichier  */
	{
	   void getupper(char *buffer, int len); /*  lit 'len' majuscules exactement  */
	   char newstr[11];                                       /*  nouveau string  */
	   int i, k, rep1, rep2;
	   int bytes, first, currentfirst;
	   long p;                                      /*  position dans le fichier  */
	   long offnew;                                 /*  offset du string modifi‚  */
	   int append;                       /*  flag pour l'ajout en fin de fichier  */
	   do
	   {
	   printf("\n\nNouveau string (saisie en majuscules) : ");
	   getupper(newstr, STRLEN);
	   /*  ouvre fichier tampon  */
	   if((newfile=open("data.new",O_RDWR | O_CREAT | O_TRUNC,0666))== -1)
	   {
	   fprintf(stderr, "\n\nErreur lors du transfert des donn‚es.");
	   exit(3);
	   }
	   /*  d‚termine position dans le fichier pour l'insertion du nouveau string  */
	   lseek(datafile, 0L, 0);
	   bytes = read(datafile, buffer, STRLEN);
	   while (strcmp(newstr, buffer) > 0 && bytes > 0)
	   bytes = read(datafile, buffer, STRLEN);
	   if (bytes > 0)
	   offnew = tell(datafile) - 10;
	   else                                                   /*  fin de fichier  */
	   offnew = tell(datafile);
	   /*  actualise fichier de donn‚es … l'aide du fichier tampon  */
	   lseek(datafile, 0L, 0);                         /*  vers d‚but du fichier  */
	   p = 0L;
	   append = 1;
	   while ((bytes = read(datafile, buffer, STRLEN)) > 0)
	   {
	   if (p == offnew)                                /*  insŠre nouveau string  */
	   {
	   write(newfile, newstr, STRLEN);
	   append = 0;               /*  nouveau string pas ajout‚ en fin de fichier  */
	   }
	   write(newfile, buffer, bytes);
	   p+=10L;
	   }
	   /*  le string modifi‚ doit ˆtre ins‚r‚ en tant que nouveau dernier
	       (cas non trait‚ par la boucle pr‚c‚dente)  */
	   if (append)
	   write(newfile, newstr, STRLEN);
	   /*  actualise fichier donn‚es via fichier tampon et note offsets des
	       initiales  */
	   lseek(datafile, 0L, 0);
	   lseek(newfile, 0L, 0);
	   k = 1;
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
	   fseek(offile, 0L, 0);                       /*  actualise fichier offsets  */
	   fwrite(r, sizeof(struct location), 27, offile);
	   fseek(offile, 0L, 0);
	                                             /*  actualise nombre de strings  */
	   lseek(datafile, 0L, 2);
	   nstrings = tell(datafile) / 10;
	   lseek(datafile, 0L, 0);
	   close(newfile);
	   printf("\n\nString enregistr‚. Autre string … ajouter ? (o/n)");
	   rep2 = getche();
	   } while (rep2 == 'o'  ||  rep2 == 'O');
	}

