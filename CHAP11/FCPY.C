/* FCPY duplique n'importe quel fichier … l'aide des fonctions 'read' et 'write'.
   FCPY est lanc‚ via la syntaxe : fcpy <source> <cible>.
   Pour <source> comme pour <cible>, on peut sp‚cifier la console (= CON).
   Le programme ne v‚rifie pas dans cette version si on ‚crase un fichier
   existant. Les messages d'erreur sont affich‚s par 'write' sur la sortie
   d'erreurs standard (descripteur = 2).   */

#include <io.h>                               /*   open, close, read, write   */
#include <fcntl.h>                    /*   constantes symboliques pour open   */
#include <stdlib.h>                                      /*   exit, toupper   */
#include <string.h>                                     /*   strcmp, strlen   */
main(int argc, char *argv[])
{
   void upstr(char *s);              /*   convertit un string en majuscules   */
   char *syntax =   "\nSyntaxe : fcpy source cible\n"\
   "                fcpy CON cible\n"\
   "                fcpy source CON";
   char *noread =   "\nImpossible d'ouvrir le fichier source.";
   char *nowrite =   "\nImpossible d'ouvrir le fichier cible.";
   char *nocopy =   "\nImpossible de dupliquer un fichier sur lui-mˆme.";
   int infile = 0;          /* descripteur pour fichier source : initialis‚ … 0
				  (entr‚e std.) au cas o— on lit le clavier   */
   int outfile = 1;          /* descripteur pour fichier cible : initialis‚ … 1
			       (sortie std.) au cas o— on ‚crit sur l'‚cran   */
   char rwbuf[1024];                        /*   tampon de lecture/‚criture   */
   int nbytes;                                     /*   nombre d'octets lus   */
   int i;
   if (argc != 3)            /*   il faut sp‚cifier la source et la cible !   */
   {
   write(2, syntax, strlen(syntax));
   exit(1);
   }
   for (i = 1; i < 3; i++)     /*   conversion des paramŠtres en majuscules   */
   upstr(argv[i]);
   if (! strcmp(argv[1], argv[2]))                      /*   source = cible   */
   {
   write(2, nocopy, strlen(nocopy));
   exit(2);
   }
   if (strcmp(argv[1], "CON"))                       /*   source != clavier   */
   {
   if ((infile = open(argv[1], O_RDONLY)) == -1)
   {
   write(2, noread, strlen(noread));
   exit(3);
   }
   }
   if (strcmp(argv[2], "CON"))                          /*   cible != ‚cran   */
   {
   if ((outfile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1)
   {
   write(2, nowrite, strlen(nowrite));
   exit(4);
   }
   }

   /* duplication   */
   while ((nbytes = read(infile, rwbuf, 1024)) > 0)
   write(outfile, rwbuf, nbytes);

   /* fermeture des fichiers   */
   close(infile);
   close(outfile);
}
void upstr(char *s)                  /*   convertit un string en majuscules   */
{
   int i = 0;
   while (s[i])
   {
   s[i] = toupper(s[i]);
   i++;
   }
}
