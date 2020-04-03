/*   printfl imprime un fichier dont le nom provient de la ligne de commande   */
#include <stdio.h>   /*   printf, fopen, fgetc, fputc   */
#include <stdlib.h>   /*   exit   */
main(int argc, char **argv)
{
   FILE *fp;
   int c;
   printf("\033[2J");
   if (argc != 2)   /*   un seul paramätre !   */
   {
   printf("\nSyntaxe : printfl fichier");
   exit(1);
   }
   if ((fp = fopen(argv[1], "r")) == NULL)
   {
   printf("\nImpossible d'ouvrir le fichier %s.", argv[1]);
   exit(2);
   }
   while ((c = fgetc(fp)) != EOF)   /*   impression du fichier   */
   fputc(c, "stdprn");
}

