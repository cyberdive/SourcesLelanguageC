/*     STATIC montre l'utilisation d'une variable static     */
#include <stdio.h>
main()
{
     int i;
     for (i = 0; i < 5; i++)
   {
     int a = 0;                         /* Variable locale de la classe auto.
		   Recr‚‚e et r‚initialis‚e … chaque ex‚cution du bloc     */
     printf("valeur de a (auto) lors de l'ex‚cution no %d du bloc :\t%d\n", i+1, a);
     a++;
   }
     printf("\n\n");
     for (i = 0; i < 5; i++)
   {
     static int a = 0;                   /* Variable locale de classe static.
					 Cr‚‚e et initialis‚e une seule fois.
		     Conserve sa valeur entre deux ex‚cutions du bloc.     */
     printf("Valeur de a (static) lors de l'ex‚cution no %d du bloc:\t%d\n", i+1, a);
     a++;
   }
}

