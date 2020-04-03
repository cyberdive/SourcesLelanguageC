/*     PREPCONS montre comment utiliser les constantes pr‚d‚finies du pr‚processeur.     */
#include <stdio.h>
main()
{
     #if !defined (__STDC__)
     printf("Compilateur non conforme au standard ANSI.\n");
     #endif
     printf("C'est le programme %s, ligne %d\n", __FILE__, __LINE__);
     printf("DerniŠre compilation de %s : %s … %s heure\n", __FILE__, __DATE__, __TIME__);
}

