/*   DICE simule, … l'aide d'une fonction de g‚n‚ration al‚atoire, 1000 jets de
trois d‚s. Les tirages sont rang‚s dans un tableau de structures dont le
contenu peut ˆtre ‚crit dans un fichier via la fonction fwrite. Le fichier des
r‚sultats peut ensuite ˆtre affich‚ ou imprim‚. Pour la lecture du fichier, on
						 utilise la fonction fread.   */
#include <stdio.h>       /*   fread, fwrite, printf, fprintf, fopen, fclose   */
#include <stdlib.h>                                  /*   rand, srand, exit   */
#include <time.h>                                                 /*   time   */
#include <conio.h>                                       /*   getch, getche   */
#define SCREENHEADER()   for (i = 0; i < 4; i++)printf("D1 D2 D3 TOT  ");\
   printf("D1 D2 D3 TOT\n");\
   for (i = 0; i < 4; i++)\
   printf("-------------+-");\
   printf("------------\n")
#define PRINTHEADER()   for (i = 0; i < 4; i++)\
   fprintf(stdprn, "D1 D2 D3 TOT  ");\
   fprintf(stdprn, "D1 D2 D3 TOT\n");\
   for (i = 0; i < 4; i++)\
   fprintf(stdprn, "-------------+-");\
   fprintf(stdprn, "------------\n")
#define CLS()   printf("\033[2J")
struct dice
{
   int die[3];                                 /*   r‚sultats des trois d‚s   */
   int sum;                                              /*   total par jet   */
};
void restoscreen(struct dice *d, int *f);         /*   affichage du fichier   */
void restoprn(struct dice *d, int *f);           /*   impression du fichier   */
void freqtoscreen(int *f);           /*   affiche les fr‚quences des totaux   */
void freqtoprint(int *f);            /*   imprime les fr‚quences des totaux   */
int brand(int p, int q);      /*   cr‚e des nombres al‚atoires entre p et q   */
main()
{
   FILE *fp;
   struct dice res[1000];                           /*   r‚sultats des jets   */
   struct dice zero = {0};                      /*   pour initialiser 'res'   */
   int i, k, rep1, rep2, rep3, rep4;             /*   variables de contr“le   */
   int h;                                           /*   tampon pour totaux   */
   int freq[19];                                 /*   fr‚quences des totaux   */
   long sec;                                         /*   heure en secondes   */
   char filename[81];                        /*   nom du fichier d'archives   */
   do
   {
   CLS();
   printf("Le programme simule 1.000 jets de trois d‚s.");
   time(&sec);                            /*   r‚cupŠre l'heure en secondes   */
   srand((unsigned) sec);                            /*   initialise 'rand'   */
   for (i = 0; i < 1000; i++)      /*   initialise le tableau des r‚sultats   */
   res[i] = zero;
   for (i = 0; i < 19; i++)       /*   initialise le tableau des fr‚quences   */
   freq[i] = 0;
   for (i = 0; i < 1000; i++)     /*   remplissage du tableau des r‚sultats   */
   {
   for (k = 0; k < 3; k++)
   res[i].die[k] = brand(1,6);     /* cr‚e un nombre al‚atoire entre 1 et 6   */
   h = res[i].sum = res[i].die[0] + res[i].die[1] + res[i].die[2];
   freq[h] = freq[h] + 1;                          /* compte les fr‚quences   */
   }
   printf("\n\nTermin‚. Archivage des r‚sultats ? (o/n)");
   rep1 = getche();
   if (rep1 == 'o')
   {
   printf("\n\nNom du fichier : ");
   gets(filename);
   if ((fp = fopen(filename, "w")) == NULL)
   {
   fprintf(stderr, "\nErreur en ‚criture sur fichier %s", filename);
   exit(1);
   }
				     /* ‚criture du tableau dans le fichier   */
   fwrite(res, sizeof(struct dice), 1000, fp);
   fclose(fp);
   printf("\n\nR‚sultats enregistr‚s dans fichier %s.", filename);
   printf("\nAffichage du fichier ?"
   "(e = ‚cran   i = imprimante   n = pas d'affichage)");
   switch (rep2 = getche())
   {
   case 'e':
   case 'i':
   if ((fp = fopen(filename, "r")) == NULL)
   {
   fprintf(stderr, "\nErreur d'ouverture sur fichier %s", filename);
   exit(2);
   }
						    /*   lecture du fichier   */
   fread(res, sizeof(struct dice), 1000, fp);
   if (rep2 == 'e')                                         /* sortie ‚cran   */
   restoscreen(res, freq);
   else                                                /* sortie imprimante   */
   restoprn(res, freq);
   fclose(fp);
   break;
   default:
   ;
   }                                                        /*   fin switch   */
   }                                                /*   fin if rep1 == 'o'   */
   else                                            /*   pas de fichier cr‚‚   */
   {
   printf("\n\nAfficher les r‚sultats ? (o/n)");
   rep3 = getche();
   if (rep3 == 'o')
   restoscreen(res, freq);
   }
   printf("\n\n1000 autres jets ? (o/n)");
   rep4 = getche();
   } while (rep4 == 'o');
}
void restoscreen(struct dice *d, int *f)           /*   affiche les donn‚es   */
{
   int i;                                          /*   pour SCREENHEADER()   */
   int n, linecount = 0;
   CLS();
   SCREENHEADER();
   for (n = 0; n < 1000; n++)
   {
   printf(" %d  %d  %d  %2d  ",
   d[n].die[0], d[n].die[1], d[n].die[2], d[n].sum);
   if (((n+1)%5) == 0)                           /*   5 r‚sultats par ligne   */
   {
   printf("\b\b \n");
   linecount++;
   }
   if ((((linecount+1)%21) == 0) && n != 999)
   {
   printf("\n\n<Entr‚e> pour page suivante.");
   getch();
   CLS();
   SCREENHEADER();
   linecount = 0;
   }
   }
   freqtoscreen(f);             /*   affiche la distribution des fr‚quences   */
}
void freqtoscreen(int *f)       /*   affiche la distribution des fr‚quences   */
{
   int i;
   printf("\n\nLes totaux des tirages ont les fr‚quences suivantes : ");
   printf("\n\nTotal :     ");
   for (i = 3; i < 19; i++)
   printf("%4d", i);
   printf("\n\nFr‚quence :");
   for (i = 3; i < 19; i++)
   printf("%4d", f[i]);
}
void restoprn(struct dice *d, int *f)              /*   imprime les donn‚es   */
{
   int i;                                           /*   pour PRINTHEADER()   */
   int n, columns = 0, linecount = 0, pagecount = 0;
   printf("\n\nIMPRESSION DU FICHIER ...");
   PRINTHEADER();
   for (n = 0; n < 1000; n++)
   {
   ++columns;
   fprintf(stdprn, " %d  %d  %d  %2d  ",
   d[n].die[0], d[n].die[1], d[n].die[2], d[n].sum);
   if (columns == 4)
   {
   n++;
   fprintf(stdprn, " %d  %d  %d  %2d\n",
   d[n].die[0], d[n].die[1], d[n].die[2], d[n].sum);
   linecount++;
   columns = 0;
   }
   if ((((linecount+1)%61) == 0) && n != 999)
   {
   fprintf(stdprn, "\n\n\t\t\t      - page %d - ", ++pagecount);
   fprintf(stdprn, "\n\n\n\f");                             /* saut de page   */
   PRINTHEADER();
   linecount = 0;
   }
   }
   freqtoprint(f);              /*   imprime la distribution des fr‚quences   */
}
void freqtoprint(int *f)        /*   imprime la distribution des fr‚quences   */
{
   int i;
   fprintf(stdprn," \n\n Les totaux des tirages ont les fr‚quences suivantes : ");
   fprintf(stdprn," \n\nTotal :     ");
   for (i = 3; i < 19; i++)
   fprintf(stdprn, "%4d", i);
   fprintf(stdprn, "\n\nFr‚quence :");
   for (i = 3; i < 19; i++)
   fprintf(stdprn, "%4d", f[i]);
}
int brand(int p, int q)       /*   cr‚e des nombres al‚atoires entre p et q   */
{
   return (p + (rand() % (q-p+1)));
}
