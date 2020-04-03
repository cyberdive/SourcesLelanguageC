/*        OPENXYZ essaie d'ouvrir en mode ajout le fichier XYZ.DAT            */
#include <stdio.h>                          /*   pour FILE, fopen, printf   */
main()
{
   FILE *fp;                               /*   d‚finit pointeur de fichier   */
   if ((fp = fopen("xyz.dat", "a")) == NULL)  /* essaie d'ouvrir le fichier   */
   printf("ERREUR : impossible d'ouvrir le fichier \"XYZ.DAT\".");
   else
   printf("Fichier \"XYZ.DAT\" ouvert en mode ajout.");
}
