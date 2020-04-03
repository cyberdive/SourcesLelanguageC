/*   OPNCLOSE montre comment ouvrir et fermer un fichier dont le nom est donn‚ sur la ligne de commande.   */
#include <stdio.h>   /*   printf, fopen, fclose   */
#include <stdlib.h>   /*   exit   */
#define READ "r"
main(int argc, char *argv[])
{
   FILE *fp;
   if (argc != 2)   /*   un seul paramŠtre admis   */
   {
   printf("\n\nSyntaxe : opnclose fichier[.ext]");
   exit(0);
   }
   if ((fp = fopen(argv[1], READ)) == NULL)   /*   ouverture du fichier en lecture   */
   printf("\n\nERREUR : impossible d'ouvrir le fichier %s.", argv[1]);
   else
   {
   fclose(fp);   /*   fermeture du fichier   */
   printf("\n\nLe fichier %s a ‚t‚ ferm‚.", argv[1]);
   }

}
