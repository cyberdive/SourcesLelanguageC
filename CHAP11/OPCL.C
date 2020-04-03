/*   OPCL montre comment utiliser simplement les fonctions 'open' et 'close'.
     Le programme essaie d'ouvrir en lecture un fichier dont le nom provient de
	  la ligne de commande. S'il y arrive, il le referme avec 'close'.   */
#include <stdio.h>                                             /*   printf   */
#include <io.h>                                           /*   open, close   */
#include <fcntl.h>                   /*   constantes symboliques pour open   */
#include <stdlib.h>                                              /*   exit   */
main(int argc, char *argv[])
{
   int fd;
   if (argc != 2)                                  /*   1 seul paramŠtre !   */
   {
   printf("\n\nSyntaxe : opcl fichier[.ext]");
   exit(1);
   }

   /* ouverture en lecture   */

   if ((fd = open(argv[1], O_RDONLY)) == -1)
   fprintf(stderr, "\nERREUR : impossible d'ouvrir le fichier %s.", argv[1]);
   else
   {
   close(fd);                                        /*   ferme le fichier   */
   printf("\n\nFichier %s ouvert en lecture, puis referm‚.", argv[1]);
   }
}
