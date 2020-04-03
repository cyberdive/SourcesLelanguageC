/*   TCOPY copie un fichier texte … l'aide des fonctions fgets et fputs.
TCOPY est lanc‚ selon la syntaxe : tcopy  source cible. Le programme ne
v‚rifie pas, dans cette version, si la copie ‚crase un fichier existant.   */

#include <stdio.h>                      /*   fopen, fcloseall, fgets, fputs   */
#include <stdlib.h>                                      /*   exit, toupper   */
#include <string.h>                                             /*   strcmp   */

#define   SYNTAX   "\nSyntaxe : tcopy source cible\n"\
   "                 tcopy CON cible\n"\
   "                 tcopy source CON"
#define   NOREAD   "\nImpossible d'ouvrir le fichier source."
#define   NOWRITE   "\nImpossible d'ouvrir le fichier cible."
#define   NOCOPY   "\nImpossible de dupliquer un fichier sur lui-mˆme."

main(int argc, char *argv[])
{
   void upstr(char *s);       /*   conversion d'une chaŒne en majuscules   */
   FILE *infile = stdin;         /* pointeur vers fichier source : initialis‚
		 … 'stdin' pour le cas o— la lecture se fait au clavier.   */
   FILE *outfile = stdout;        /* pointeur vers fichier cible : initialis‚
		 … 'stdout' pour le cas o— l'‚criture se fait … l'‚cran.   */
   char sbuf[512];                       /*   tampon de lecture/‚criture   */
   int i;
   if (argc != 3)          /*   il faut donner une source et une cible !   */
   {
     fputs(SYNTAX, stderr);
     exit(1);
   }
   for (i = 1; i < 3; i++)     /* convertit paramŠtres ligne de commande   */
   upstr(argv[i]);
   if (! strcmp(argv[1], argv[2]))                     /* source = cible   */
   {
     fputs(NOCOPY, stderr);
     exit(2);
   }
   if (strcmp(argv[1], "CON"))                      /* source != clavier   */
   {
     if ((infile = fopen(argv[1], "r")) == NULL)
   {
   fputs(NOREAD, stderr);
   exit(3);
   }
   }
   if (strcmp(argv[2], "CON"))                         /* cible != ‚cran   */
   {
   if ((outfile = fopen(argv[2], "w")) == NULL)
   {
     fputs(NOWRITE, stderr);
     exit(4);
   }
   }
   /* duplication   */
   while (fgets(sbuf, 512, infile) != NULL)
     fputs(sbuf, outfile);
     fcloseall();                                /*   ferme les fichiers   */
}
void upstr(char *s)                    /* convertit string en majuscules   */
{
   int i = 0;
   while (s[i])
   {
     s[i] = toupper(s[i]);
     i++;
   }
}
