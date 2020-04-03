/*      whichkey montre, via scancode et code ASCII, la touche enfonc‚e       */
#include <stdio.h>                                            /* pour printf  */
#include <bios.h>                                       /* pour _bios_keybrd  */
main()
{
     unsigned int saisie;                 /* pour le r‚sultat de _bios_keybrd */
     int carlu, scancode;                    /*  pour code ASCII et scancode  */
     printf("\033[2J");                                   /*  Efface l'‚cran  */
     printf("Appuyez sur une touche :");
     saisie = _bios_keybrd(_keybrd_read);      /*prise en compte de la saisie */
     carlu = saisie & 255;                                /*  isole Low Byte  */
     scancode = saisie >> 8;                             /*  isole High Byte  */
     printf("\nScancode : %d  CaractŠre : %c", scancode, carlu);
}
