/*** VIDEO rŠgle le mode d'‚cran en normal ou en inversion vid‚o. ***/   
/*** Le programme re‡oit le r‚glage souhait‚ depuis un paramŠtre  ***/
/*** sp‚cifi‚ sur la ligne de commande.                           ***/

#include <stdio.h>                                  /* printf, gets */
#include <string.h>                                       /* strcmp */
#include <stdlib.h>                                         /* exit */

main(int argc, char *argv[ ])
 {
   if (argc != 2)
       {
          printf("\n\nSyntaxe : video mode");
          exit(1);
       }
   if (!strcmp(argv[1], "normal"))
       {
          printf("\033[0m");
          printf("\033[2J");
       }
   else if (!strcmp(argv[1], "inverse"))
       {
          printf("\033[7m");
          printf("\033[2J");
       }
   else
       printf("\n\nParamŠtre erron‚ : \"normal\" ou \"inverse\"");
 }
