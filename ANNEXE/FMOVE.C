	/*  fmove "d‚place" un fichier : le fichier concern‚ est dupliqu‚, 
	     puis l'original est effac‚.  */
	#include <stdio.h>          /*  fopen, fclose, fgetc, fputc, ftell, remove  */
	#include <string.h>                                             /*  strcmp  */
	#include <stdlib.h>                                               /*  exit  */
	#define   SYNTAX   "\nSyntaxe : fmove source cible\n"
	#define   NOREAD   "\nImpossible d'ouvrir fichier source."
	#define   NOWRITE   "\nImpossible d'ouvrir fichier cible."
	#define   NOMOVE   "\nSource et cible doivent ˆtre diff‚rentes."
	#define   MOVERR   "\nErreur. Le fichier n'a pas ‚t‚ d‚plac‚."
	main(int argc, char *argv[])
	{
	   FILE *infile;                            /*  pointeur vers fichier source  */
	   FILE *outfile;                            /*  pointeur vers fichier cible  */
	   int c;
	   if (argc != 3)                       /*  il faut indiquer source et cible  */
	   {
	   fputs(SYNTAX, stderr);
	   exit(1);
	   }
	   if (! strcmp(argv[1], argv[2])) /*  fichier en entr‚e = fichier en sortie  */
	   {
	   fputs(NOMOVE, stderr);
	   exit(2);
	   }
	   /*  ouverture binaire du fichier en entr‚e  */
	   if ((infile = fopen(argv[1], "rb")) == NULL)
	   {
	   fputs(NOREAD, stderr);
	   exit(3);
	   }
	   /*  ouverture binaire du fichier en sortie  */
	   if ((outfile = fopen(argv[2], "wb")) == NULL)
	   {
	   fputs(NOWRITE, stderr);
	   exit(4);
	   }
	   /*  duplication  */
	   while ((c = fgetc(infile)) != EOF)
	   fputc(c, outfile);
	   if (ftell(infile) != ftell(outfile))               /*  fichiers de longueurs 
	                                                               diff‚rentes ?  */
	   {
	   fputs(MOVERR, stderr);
	   fclose(outfile);
	   remove(argv[2]);                        /*  suppression fichier en sortie  */
	   exit(5);
	   }
	   fcloseall();
	   remove(argv[1]);         /*  pas d'erreur : suppression fichier en entr‚e  */
	}


