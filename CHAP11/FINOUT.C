/*   FINOUT recopie l'entr‚e standard sur la sortie standard   */
#include <stdio.h>   /*   fgetc, fputc, feof   */
main()
{
   char message[] = "\n\nErreur en lecture.";
   int i = 0;
   int c;
   while ((c = fgetc(stdin)) != EOF)
   fputc(c, stdout);
   if (!feof(stdin))   /*   erreur en lecture   */
   while (message[i])
   fputc(message[i++], stdout);
}

