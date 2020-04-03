/*** CHEKHEX teste si un nombre saisi par l'utilisateur contient les        ***/
/*** lettres A, B, C, D, E, F ou a, b, c, d, e, f, ce qui suffit … d‚tecter ***/
/*** un nombre hexad‚cimal. Les messages du programme sont affich‚s en tant ***/
/*** que chaŒnes constantes avec des pointeurs.                             ***/

#include <stdio.h>                                            /* printf, gets */
#include <ctype.h>                                                 /* isdigit */

main()
  {
    char buffer [128];
    char *m1 = "\n\nAucun nombre entier positif.", 
         *m2 = "\n\nNombre hexad‚cimal.",
         *m3 = "\n\nNombre entier d‚cimal.";
    int i, stop, hex;

    printf("\033[2J");
    printf("Nombre entier : ");
    gets(buffer);
    i = 0;
    stop = 0;
    hex = 0;
    while (buffer[i]  &&  !stop)
      {
         if (!isdigit(buffer[i]) && (buffer[i] < 'A' || buffer[i] > 'F')
                  && (buffer[i] < 'a' || buffer[i] > 'f'))
            {
               printf("%s", m1);
               stop = 1;
            }
         else if ((buffer[i] >= 'A' && buffer[i] <= 'F') || (buffer[i] >= 'a'
                  && buffer[i] <= 'f') && hex == 0)
               hex = 1;
      i++;
      }
    if (hex && !stop)
       printf("%s", m2);
    if (!hex && !stop)
       printf("%s", m3);
  }
  