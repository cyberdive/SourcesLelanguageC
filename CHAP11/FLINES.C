/*   FLINES compte les caractŠres et les lignes d'un fichier de texte.
   Le nom du fichier est donn‚ sur la ligne de commande. A la demande,
   on affiche une s‚lection quelconque de lignes cons‚cutives.
   Les offsets des diff‚rentes lignes sont pour cela rang‚es dans un
		 tableau 'long' dynamique, agrandi si besoin est.   */
#include <stdio.h>                                /*   fonctions de fichier   */
#include <stdlib.h>                                /*   exit, realloc, free   */
#include <conio.h>                                       /*   getche, getch   */
#define POS(x,y)   printf("\033[%d;%dH", x, y)
#define BLANKLINE()   for(k = 0; k < 80; k++) printf(" ")
main(int argc, char *argv[])
{
   FILE *fp;
   int c;                                             /*   tampon caractŠre   */
   int k, n = 1, rep;                            /*   variables de contr“le   */
   int flag;                                             /*   flag d'erreur   */
   long *offset;               /*   pointeur vers tableau dyn. pour offsets   */
   long lines = 1;                         /*   nombre de lignes du fichier   */
   long characters;                    /*   nombre de caractŠres du fichier   */
   long startln, endln;         /*   premiŠre et derniŠre lignes … afficher   */
   if (argc != 2)                          /*   nombre de paramŠtres erron‚   */
   {
   fprintf(stderr, "\nSyntaxe : flines fichier");
   exit(1);
   }
			       /* allocation m‚moire pour tableau dynamique   */
   if ((offset = (long*) realloc(offset, n*500*sizeof(long))) == NULL)
   {
   fprintf(stderr, "\nPlus assez de m‚moire.");
   exit(2);
   }
   /* ouverture binaire du fichier   */
   if ((fp = fopen(argv[1], "rb")) == NULL)
   {
   fprintf(stderr, "\nErreur … l'ouverture du fichier %s.", argv[1]);
   exit(3);
   }
   offset[1] = 0;                            /*   offset premiŠre ligne = 0   */
   while ((c = fgetc(fp)) != EOF)                  /*   lecture du  fichier   */
   {
   if (c == '\n')
   offset[++lines] = ftell(fp);        /*   m‚morise offset de chaque ligne   */
   if (lines % 500 == 0)                            /*   pas assez de place   */
   {
   n++;
		   /* on fait de la place pour 500 autres offsets de lignes   */
   if ((offset = (long*) realloc(offset, n*500*sizeof(long))) == NULL)
   {
   fprintf(stderr, "\nPlus assez de m‚moire.");
   exit(2);
   }
   }
   }
   characters = ftell(fp);        /* position aprŠs la lecture = fin de fichier
			  ftell donne le nb. de caractŠres (taille fichier)   */
   printf("\033[2J");
   POS(5,0);
   if (!characters)                                       /*   fichier vide   */
   {
   printf("\nLe fichier est vide.");
   exit(4);
   }
   else
   printf("Le fichier %s a %ld caractŠres et %ld ligne(s).", argv[1], characters, lines);
   POS(7,0);
   printf("Afficher des lignes ? (o/n)");
   if ((rep = getche()) == 'o')
   {
   do
   {
   flag = 0;
   POS(11,0); BLANKLINE();
   POS(9,0); BLANKLINE(); POS(9,0);
   printf("Depuis la ligne (minimum : 1):");
   POS(9,40);
   printf("Jusqu'… la ligne (maximum : %ld):", lines);
   POS(9,32);
   scanf("%ld", &startln);
   if (startln == 0)
   exit(5);
   else if (startln < 0 || startln > lines)
   {
   flag = 1;
   POS(11,0); BLANKLINE(); POS(11,0);
   printf("Mauvaise valeur initiale. <Entr‚e> pour continuer.");
   getch();
   continue;
   }
   POS(9,74);
   scanf("%ld", &endln);
   if (endln < startln || endln > lines)
   {
   flag = 1;
   POS(11,0); BLANKLINE(); POS(11,0);
   printf("Mauvaise valeur finale. <Entr‚e> pour continuer.");
   getch();
   continue;
   }
   } while (flag);
   fseek(fp, offset[startln], 0);   /*   position premiŠre ligne … afficher   */
   printf("\033[2J");
   printf("%05ld  ", startln);    /*   num‚rotage des lignes sur 5 chiffres   */
   while ((c = fgetc(fp) != EOF))                 /*   lecture et affichage   */
   {                                                               /*   des   */
   fputc(c, stdout);                              /*   lignes s‚lectionn‚es   */
   if (c == '\n')
   {
   if (startln < endln)
   printf("%05ld  ", ++startln);
   else
   break;
   }
   }
   }                                                 /*   fin if rep == 'o'   */
   fclose(fp);
   free(offset);
}
