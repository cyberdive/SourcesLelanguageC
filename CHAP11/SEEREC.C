/*   SEEREC montre comment utiliser 'tell' et 'lseek'. On g‚nŠre al‚atoirement
     500 chaŒnes de caractŠres compos‚es de 10 majuscules, puis on les trie
     alphab‚tiquement et on les stocke dans un fichier en tant qu'enregistrements.
     L'utilisateur peut ensuite faire afficher soit tous les strings, soit ceux
     commen‡ant par une certaine initiale, soit un seul string donn‚ par son
     num‚ro (1 - 500).   */
#include <stdio.h>                                       /*   printf, scanf   */
#include <io.h>                  /*   open, close, read, write, tell, lseek   */
#include <fcntl.h>                    /*   constantes symboliques pour open   */
#include <stdlib.h>                                        /*   exit, qsort   */
#include <string.h>                                     /*   strcpy, strcmp   */
#include <conio.h>                                       /*   getch, getche   */
main()
{
   int brand(int p, int q);           /*   g‚n‚rateur de nombres al‚atoires   */
   int scomp(char s1[], char s2[]);             /*   comparaison de strings   */
   char data[500][11];                     /*   tableau 2D pour 500 strings   */
   char buffer[11];                              /*   tampon pour un string   */
   struct location
   {
     long offset;      /* offset premier string ayant une certaine initiale   */
     char letter;                                   /* initiale d'un string   */
   } reloc[27];                  /* tableau m‚morisant offsets/initiales des 26
			 groupes de strings (A - Z). reloc[0] est inoccup‚.   */
   char firstletter, currentfirst;                /*   tampon pour initiale   */
   int fd;                                                 /*   descripteur   */
   int bytes;                                           /*   caractŠres lus   */
   long recnum;                                       /*   num‚ro du string   */
   int i, k, count;                              /*   variables de contr“le   */
   int rep1, rep2;                               /*   variables de contr“le   */
   char *noopen   =   "\nErreur en ouverture.";
   char *norecord   =   "\nAucun enregistrement avec cette initiale.";
   char *intro   =   "Cr‚ation al‚atoire de 500 strings"\
   " tri‚s alphab‚tiquement\net rang‚s dans un fichier.";
   printf("\033[2J");
   printf("%s", intro);


   /****  cr‚ation de chaŒnes de caractŠres al‚atoires  ***/

   for (i = 0; i < 500; i++)                               /*   500 strings   */
   {
   for (k = 0; k < 10; k++)                           /*   de 10 majuscules   */
   buffer[k] = (char) brand(65,90);
   buffer[k] = '\0';
   strcpy(data[i], buffer);
   }
   /***  trie les strings  ********************/

   qsort((void*)data, 500, sizeof(char[11]), scomp);

   /*************  ouvre/cr‚e fichier et y range les strings  **************/

   if ((fd = open("data.fil", O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
   {
   write(2, noopen, strlen(noopen));
   exit(1);
   }
   for (i = 0; i < 27; i++)           /*   initialise tableau de structures   */
   {
   reloc[i].offset = 0;
   reloc[i].letter = '\0';
   }
   firstletter = reloc[1].letter = data[0][0];
				    /*  m‚morise initiale du premier string   */
   k = 1;
   for (i = 0; i < 500; i++)
   {
   strcpy(buffer, data[i]);
   write(fd, buffer, strlen(buffer));        /*   ‚crit string dans fichier   */
   currentfirst = data[i][0];               /*   initiale du string courant   */
   if (firstletter != currentfirst)                  /*   nouvelle initiale   */
   {
   firstletter = currentfirst;
   k++;
   reloc[k].letter = firstletter;           /*   m‚morise nouvelle initiale   */
   reloc[k].offset = tell(fd) - 10; /* offset premier string de nlle initiale */
   }
   }
   /***  affichage  *****************************/
   printf("\nTermin‚. Afficher les chaŒnes de caractŠres ? (o/n)");
   if ((rep1 = getche())== 'o')
   {
   do
   {
   printf("\033[2J");
   printf("\n\n\nAFFICHAGE DES STRINGS ENREGISTRES :\n\n");
   printf("Tous             (a)\n\n");
   printf("Initiale           (b)\n\n");
   printf("Num‚ro        (c)\n\n");
   printf("Quitter          (q)\n\n\n");
   printf("Votre choix : ");
   switch(rep2 = getche())
   {
   case 'a':                                              /*   affiche tout   */
   printf("\033[2J");
   count = 0;
   lseek (fd, 0L, 0);                            /*   vers d‚but du fichier   */
   while ((bytes = read(fd, buffer, strlen(buffer))) > 0)
   {
   write(1, buffer, bytes);
   printf("\n");
   count++;
   if (count == 20)
   {
   printf("\n\n<Entr‚e> pour page suivante.");
   getch();
   printf("\033[2J");
   count = 0;
   }
   }
   break;
   case 'b':                             /* tous strings avec mˆme initiale   */
   do
   {
   count = 0;
   printf("\n\nInitiale : ");
   firstletter = getche();
   i = 1;
					   /* saute initiales non conformes   */
   while (firstletter != reloc[i].letter && i < 27)
   i++;
   if (i > 26)                       /*   l'initiale saisie est inexistante   */
   {
   printf("%s", norecord);
   printf("\n<Entr‚e> pour continuer.");
   getch();
   }
   } while (i > 26);
   printf("\033[2J");
   lseek(fd, reloc[i].offset, 0);         /* vers premier string d'initiale   */
   while ((bytes = read(fd, buffer, strlen(buffer))) > 0 && buffer[0] == firstletter)
   {
   write(1, buffer, bytes);
   printf("\n");
   count++;
   if (count == 20)
   {
   printf("\n\n<Entr‚e> pour page suivante.");
   getch();
   printf("\033[2J");
   count = 0;
   }
   }
   break;
   case 'c':
   do
   {
   printf("\n\nString num‚ro (1-500) : ");
   scanf("%ld", &recnum);
   } while (recnum < 1 || recnum > 500);
   lseek(fd, (recnum-1) * 10, 0);                /* vers enreg. no 'recnum'   */
   bytes = read(fd, buffer, strlen(buffer));
   printf("\n");
   write(1, buffer, bytes);
   break;
   default:
   ;
   }                                                        /*   fin switch   */
   if (rep2 == 'a'  ||  rep2 == 'b'  ||  rep2 == 'c')
   {
   printf("\n\n<Entr‚e> pour revenir au menu.");
   getch();
   }
   } while (rep2 != 'q');
   }                                                /*   fin if rep1 == 'o'   */
}
int brand(int p, int q)         /*   donne un nombre al‚atoire entre p et q   */
{
   return (p +(rand() % (q-p+1)));
}
int scomp(char s1[], char s2[])           /*   compare strings pour 'qsort'   */
{
   return (strcmp(s1, s2));
}
