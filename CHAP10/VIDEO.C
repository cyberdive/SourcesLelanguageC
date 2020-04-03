/*** VIDEO place l'‚cran en mode normal ou en inversion vid‚o ***/

#include <stdio.h>                              /* printf, gets */
#include <string.h>                                   /* strcmp */

main()
 {
   char mode[80];
   
   do
     {
       printf("\n\nMode d'‚cran ? (\"normal\" / \"inverse\") : ");
       gets(mode);
     } while (strcmp(mode, "normal")  &&  strcmp(mode, "inverse"));
   
   if (!strcmp(mode, "normal"))
     {
       printf("\033[0m");
       printf("\033[2J");
     }
   else
     {
       printf("\033[7m");
       printf("\033[2J");
     }
 }
