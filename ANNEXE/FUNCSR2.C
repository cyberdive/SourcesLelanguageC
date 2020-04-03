	/*  FUNCSR2 contient les fonctions personnelles utilis‚es dans SEEREC2.  */
	#include <stdio.h>
	#include <io.h>
	#include <stdlib.h>
	#include <string.h>
	#include <conio.h>
	#define STRLEN 10
	struct location
	{
	   long offset;
	   char letter;
	};
	extern char buffer [11];
	extern int fd;
	extern char norecord[];
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
	   printf("Num‚ro   (c)\n\n");
	   printf("Quitter   (q)\n\n\n");
	   printf("Votre choix : ");
	}
	void initialize(struct location *r)     /*  initialise tableau de structures  */
	{
	   int i;
	   for (i = 0; i < 27; i++)
	   {
	   r[ i ].offset = 0;
	   r[ i ].letter = '\0';
	   }
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
	/*  ‚criture des chaŒnes dans le fichier  */
	void writrec(char d[][11], char first, struct location *r)
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
	   r[k].letter = currentfirst;                      /*  m‚morise nouvelle initiale  */
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
	   if (i > 26)   /*  initiale non trouv‚e  */
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
	void showc(void)                            /*  affiche string de num‚ro xxx  */
	{
	   long recnum;
	   int bytes;
	   do
	   {
	   printf("\n\nString no (1-500) : ");
	   scanf("%ld", &recnum);
	   } while (recnum < 1 || recnum > 500);
	   lseek(fd, (recnum-1)*10, 0);       /*  vers enreg. ayant le num‚ro recnum  */
	   bytes = read(fd, buffer, STRLEN);
	   printf("\n");
	   write(1, buffer, bytes);
	}


